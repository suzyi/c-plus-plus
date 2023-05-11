#include "caffe/caffe.hpp"
#include "caffe/proto/caffe.pb.h"

#ifdef USE_OPENCV
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#endif

using std::string;
using std::cout;
using std::endl;

int main(int argc, char** argv) {
    // read an img via caffe::ReadImageToDatum function
    caffe::Datum datum_;
    string path_to_img = argv[1];
    int label(1), height(128), width(64);
    bool is_color(true);
    caffe::ReadImageToDatum(path_to_img, label, height, width, is_color, &datum_);
    cout << "height: " << datum_.height() << endl;
    cout << "width: " << datum_.width() << endl;
    cout << "channels: " << datum_.channels() << endl;

    // The mutual convert between a Datum and a Blob (bathsize 1) can be done with the help of cv::Mat.
    // Datum->cv::Mat->Blob
    // Blob->cv::Mat->Datum, or write your own function.
    // cv::Mat DecodeDatumToCVMat(const Datum& datum, bool is_color);
    // void CVMatToDatum(const cv::Mat& cv_img, Datum* datum);
    cout << "done!" << endl;
}