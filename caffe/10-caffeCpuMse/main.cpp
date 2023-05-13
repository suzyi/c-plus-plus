#include "caffe/caffe.hpp"
#include "caffe/proto/caffe.pb.h"
#include "caffe/util/math_functions.hpp"

#ifdef USE_OPENCV
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#endif // USE_OPENCV

using std::cout;
using std::endl;

int main(int argc, char** argv) {
    
    // set cpu or gpu
    #ifdef CPU_ONLY
        cout << "cpu used." << endl;
        caffe::Caffe::set_mode(caffe::Caffe::CPU);
    #else
        cout << "gpu used." << endl;
        caffe::Caffe::set_mode(caffe::Caffe::GPU);
    #endif

    // define two blobs
    int batchsize(1), channels(3), height(2), width(2);
    caffe::Blob<float> blob_1(batchsize, channels, height, width), blob_2(batchsize, channels, height, width);
    for (int b=0; b<batchsize; ++b) {
        for (int c=0; c<channels; ++c) {
            for (int h=0; h<height; ++h) {
                for (int w=0; w<width; ++w) {
                    blob_1.mutable_cpu_data()[((b*channels + c)*height + h)*width + w] = 0.5;
                    blob_2.mutable_cpu_data()[((b*channels + c)*height + h)*width + w] = 1.7;
                }
            }
        }
    }

    cout << blob_1.cpu_data()[0] << endl;
    cout << blob_1.cpu_data()[11] << endl;
    cout << blob_1.cpu_data()[12] << endl;
    
    // Calcualte the element-wise subtraction between two blobs
    float y(0.001);
    caffe::caffe_sub(blob_1.count(), blob_1.cpu_data(), blob_2.cpu_data(), &y);
    for (int i=0; i<blob_1.count(); i++) { cout << i << " : " << *(&y + i) << endl; }

    // Calculate the dot product and mse between two blobs
    float dot = caffe::caffe_cpu_dot(blob_1.count(), &y, &y);
    cout << "mse : " << dot/blob_1.num()/float(2) << endl;

    // Calculate mse value
    float value = caffe::caffe_cpu_mse(blob_1.count(), blob_1.num(), blob_1.cpu_data(), blob_2.cpu_data());
    cout << "Mean Squared Error (mse) between them is: " << value << endl;
    cout << "done!" << endl;
}