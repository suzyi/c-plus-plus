#include <opencv2/opencv.hpp>
#include <stdint.h>
#include <torch/torch.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Options {
    int image_size = 224;
    size_t train_batch_size = 1024;
    size_t iterations = 2;
    // path must end in delimiter
    std::string datasetPath = "../dataset/";
    std::string infoFilePath = "info.txt";
    torch::DeviceType device = torch::kCPU;
};

static Options options;

using Data = std::vector<std::pair<std::string, long>>; // data[i].first=path(string), data[i].second=label(long)

class CustomDataset : public torch::data::datasets::Dataset<CustomDataset> {
    using Example = torch::data::Example<>; // an Example is a training or testing point.

    Data data;

public:
    CustomDataset(const Data& data) : data(data) {}

    Example get(size_t index) {
        std::string path = options.datasetPath + data[index].first;
        auto mat = cv::imread(path);
        assert(!mat.empty());

        cv::resize(mat, mat, cv::Size(options.image_size, options.image_size));
        std::vector<cv::Mat> channels(3);
        cv::split(mat, channels);

        auto R = torch::from_blob(
            channels[2].ptr(),
            { options.image_size, options.image_size },
            torch::kUInt8);
        auto G = torch::from_blob(
            channels[1].ptr(),
            { options.image_size, options.image_size },
            torch::kUInt8);
        auto B = torch::from_blob(
            channels[0].ptr(),
            { options.image_size, options.image_size },
            torch::kUInt8);

        auto tdata = torch::cat({ R, G, B })
            .view({ 3, options.image_size, options.image_size })
            .to(torch::kFloat);
        auto tlabel = torch::from_blob(&data[index].second, { 1 }, torch::kLong); // from_blob(data, sizes, type)
        return { tdata, tlabel };
    }

    torch::optional<size_t> size() const {
        return data.size();
    }
};

std::pair<Data, Data> readInfo() {
    Data train, test;

    std::ifstream stream(options.infoFilePath);
    assert(stream.is_open());

    long label;
    std::string path, type;

    while (true) {
        stream >> path >> label >> type;

        if (type == "train")
            train.push_back(std::make_pair(path, label));
        else if (type == "test")
            test.push_back(std::make_pair(path, label));
        else
            assert(false);

        if (stream.eof())
            break;
    }
    return std::make_pair(train, test);
}

template <typename DataLoader>
void train(
    DataLoader& loader,
    size_t epoch,
    size_t data_size) {
    size_t index = 0;

    for (auto& batch : loader) {
        auto data = batch.data.to(options.device);
        std::cout << "(batch_size, channel, width, height) = (" << data.size(0) << ", " << data.size(1) << ", " << data.size(2) << ", " << data.size(3) << ")" << std::endl;
        }
    }

int main() {
    torch::manual_seed(1);

    if (torch::cuda::is_available())
        options.device = torch::kCUDA;
    std::cout << "Running on: "
        << (options.device == torch::kCUDA ? "CUDA" : "CPU") << std::endl;

    auto data = readInfo();

    auto train_set =
        CustomDataset(data.first).map(torch::data::transforms::Stack<>());
    auto train_size = train_set.size().value();
    auto train_loader =
        torch::data::make_data_loader<torch::data::samplers::SequentialSampler>(
            std::move(train_set), options.train_batch_size);

    for (size_t i = 0; i < options.iterations; ++i) {
        train(*train_loader, i + 1, train_size);
    }

    return 0;
}