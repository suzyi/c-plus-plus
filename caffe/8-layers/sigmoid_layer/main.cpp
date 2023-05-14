#include "caffe/caffe.hpp"
#include "caffe/proto/caffe.pb.h"   // caffe::layerparameter param_;
#include "caffe/layers/sigmoid_layer.hpp"

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
    caffe::Blob<float>* bottom_blob = new caffe::Blob<float>(1, 3, 2, 2);
    caffe::Blob<float>* top_blob;
    top_blob->ReshapeLike(*bottom_blob);
    for (int b=0; b<bottom_blob->num(); ++b) {
        for (int c=0; c<bottom_blob->channels(); ++c) {
            for (int h=0; h<bottom_blob->height(); ++h) {
                for (int w=0; w<bottom_blob->width(); ++w) {
                    bottom_blob->mutable_cpu_data()[((b*bottom_blob->channels()+c)*bottom_blob->height()+h)*bottom_blob->width()+w] = 0.5;
                }
            }
        }
    }

    // calculate via caffe sigmoid_layer.cpp
    caffe::LayerParameter param_;
    // cout << "param_.blobs_size(): " << param_.blobs_size() << endl;
    // cout << "param_.loss_weight_size(): " << param_.loss_weight_size() << endl;
    // param_.add_loss_weight(.5);
    caffe::SigmoidLayer<float> sigmoid_layer(param_);
    std::vector<caffe::Blob<float>*> bottom_vec = {bottom_blob};
    std::vector<caffe::Blob<float>*> top_vec = {top_blob};
    sigmoid_layer.Forward(bottom_vec, top_vec);
    cout << "------------------------Forward Info------------------------" << endl;
    for (int i=0; i<top_blob->count(); i++ ) {
        cout << i << " : " << top_blob->cpu_data()[i] << endl;
    }
    cout << "------------------------Backward Info------------------------" << endl;
    cout << "Before: " << endl;
    for (int i=0; i<bottom_vec[0]->count(); i++) {
        top_vec[0]->mutable_cpu_diff()[i] = 1.0;
        cout << i << " : " << bottom_vec[0]->cpu_diff()[i] << endl;
    }
    std::vector<bool> propagate_down = {true};
    sigmoid_layer.Backward(top_vec, propagate_down, bottom_vec);
    cout << "After: " << endl;
    for (int i=0; i<bottom_vec[0]->count(); i++) {
        cout << i << " : " << bottom_vec[0]->cpu_diff()[i] << endl;
    }
    cout << "done!" << endl;
}