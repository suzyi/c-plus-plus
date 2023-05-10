#include <caffe/caffe.hpp>
#include "caffe/proto/caffe.pb.h" // Datum datum;
#ifdef USE_OPENCV
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#endif  // USE_OPENCV
using namespace caffe;
using std::string;
using std::cout;
using std::endl;

int main(int argc, char** argv){
    string model_file = argv[1];
    string path_to_img = argv[2];

    // set cpu or gpu
    #ifdef CPU_ONLY
        Caffe::set_mode(Caffe::CPU);
    #else
        Caffe::set_mode(Caffe::GPU);
    #endif

    // define net
    shared_ptr<Net<float>> net_;
    net_.reset(new Net<float>(model_file, TEST));

    // read img via opencv
    cv::Mat img_cv = cv::imread(path_to_img, -1);
    cv::resize(img_cv, img_cv, cv::Size(net_->input_blobs()[0]->width(), net_->input_blobs()[0]->height()));
    img_cv.convertTo(img_cv, CV_32FC(net_->input_blobs()[0]->channels()));
    img_cv /= 256.0;

    // pass cv::Mat to caffe net
    std::vector<cv::Mat> net_in;
    float* input_ = net_->input_blobs()[0]->mutable_cpu_data();
    for (int i=0; i<net_->input_blobs()[0]->channels(); i++) {
        cv::Mat channel_(net_->input_blobs()[0]->height(), net_->input_blobs()[0]->width(), CV_32FC1, input_);
        net_in.push_back(channel_);
        input_ += channel_.size().height*channel_.size().width;
    }
    split(img_cv, net_in);
    net_->Forward();
    
    // read an image via caffe
    const shared_ptr<Blob<float>> img_blob_ptr = net_->blob_by_name("data");

    // print properties
    cout << "batchsize*channels*height*width is : " << img_blob_ptr->count() << endl;
    cout << "batchsize is : " << img_blob_ptr->num() << endl;
    cout << "channels is : " << img_blob_ptr->channels() << endl;
    cout << "height is : " << img_blob_ptr->height() << endl;
    cout << "width is : " << img_blob_ptr->width() << endl;
    cout << "absolute sum is : " << img_blob_ptr->asum_data() << endl;
    cout << "data_at is : " << img_blob_ptr->data_at(0, 1, 32, 33) << endl;

    const float* begin = img_blob_ptr->cpu_data();
    for (int i=0; i<10; i++) {
        cout << i << ": " << begin[i] << endl;
    }

    // save image
    cv::Mat img_save(img_blob_ptr->height(), img_blob_ptr->width(), CV_32FC(img_blob_ptr->channels()));
    for (int c=0; c<img_blob_ptr->channels(); ++c) {
        for (int h=0; h<img_blob_ptr->height(); ++h) {
            for (int w=0; w<img_blob_ptr->width(); ++w) {
                img_save.ptr<float>(h, w)[c] = img_blob_ptr->data_at(0, c, h, w);
            }
        }
    }
    img_save *= 256;
    cv::imwrite("result.png", img_save);
    cout << "result.png generated!" << endl;
}