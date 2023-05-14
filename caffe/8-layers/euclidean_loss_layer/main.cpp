#include "caffe/caffe.hpp"
#include "caffe/proto/caffe.pb.h"   // caffe::layerparameter param_;
#include "caffe/util/math_functions.hpp" // caffe_sub, caffe_cpu_dot.
#include "caffe/layers/euclidean_loss_layer.hpp"

using std::string;
using std::cout;
using std::endl;

int main(int argc, char** argv) {
    // set cpu or gpu
    #ifdef CPU_ONLY
        caffe::Caffe::set_mode(caffe::Caffe::CPU);
    #else
        caffe::Caffe::set_mode(caffe::Caffe::GPU);
    #endif

    // define two blobs
    caffe::Blob<float>* blob_1 = new caffe::Blob<float>(1, 3, 2, 2);
    caffe::Blob<float>* blob_2 = new caffe::Blob<float>(1, 3, 2, 2);
    for (int b=0; b<blob_1->num(); ++b) {
        for (int c=0; c<blob_1->channels(); ++c) {
            for (int h=0; h<blob_1->height(); ++h) {
                for (int w=0; w<blob_1->width(); ++w) {
                    blob_1->mutable_cpu_data()[((b*blob_1->channels()+c)*blob_1->height()+h)*blob_1->width()+w] = 0.5;
                    blob_2->mutable_cpu_data()[((b*blob_1->channels()+c)*blob_1->height()+h)*blob_1->width()+w] = 2;
                }
            }
        }
    }

    // calculate via caffe math_functions.cpp
    caffe::Blob<float> diff_;
    diff_.ReshapeLike(*blob_1);
    caffe::caffe_sub(blob_1->count(), blob_1->cpu_data(), blob_2->cpu_data(), diff_.mutable_cpu_data());
    float dot = caffe::caffe_cpu_dot(diff_.count(), diff_.cpu_data(), diff_.cpu_data());
    float loss = dot / blob_1->num() / float(2);
    cout << "Euclidean distance between blob_1 and blob_2, via math_functions.cpp, is : " << loss << endl;

    // calculate via caffe euclidean_loss_layer.cpp
    caffe::LayerParameter param_;
    cout << "param_.blobs_size(): " << param_.blobs_size() << endl;
    cout << "param_.loss_weight_size(): " << param_.loss_weight_size() << endl;
    param_.add_loss_weight(.5);
    caffe::EuclideanLossLayer<float> mse_layer(param_);
    std::vector<caffe::Blob<float>*> bottom = {blob_1, blob_2};
    std::vector<caffe::Blob<float>*> top = {new caffe::Blob<float>(1, 1, 1, 1)};
    mse_layer.Forward(bottom, top);
    cout << "Euclidean distance between blob_1 and blob_2, via euclidean_loss_layer.cpp, is : " << top[0]->cpu_data()[0] << endl;

    // calculate the gradient of euclidean layer
    std::vector<bool> propagate_down = {true, true};
    top[0]->mutable_cpu_diff()[0] = 1;
    mse_layer.Backward(top, propagate_down, bottom);
    cout << "-------------gradient info-------------" << endl;
    for (int i=0; i<bottom[0]->count(); i++) {
        cout << i << " : " << bottom[0]->cpu_diff()[i] << endl;
    }
    cout << "done!" << endl;
}