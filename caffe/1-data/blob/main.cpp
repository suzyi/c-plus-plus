#include <stdio.h>

#include "caffe/caffe.hpp"
#include "caffe/util/io.hpp"
#include "caffe/blob.hpp"
#include "caffe/common.hpp"
#include "caffe/filler.hpp"
#include <conio.h>

using std::cout;
using std::endl;

int main(int argc, char** argv) { 
    int batchsize(2), channels(3), height(2), width(1);
    caffe::Blob<float>* blob_1 = new caffe::Blob<float>(batchsize, channels, height, width);
    cout << " batchsize*channels*height*width = " << blob_1->count() << endl;
    cout << " batchsize = " <<blob_1->num() << endl;
    cout << " channels =" <<blob_1->channels() << endl;
    cout << " height =" <<blob_1->height() << endl;
    cout << " width =" <<blob_1->width() << endl;
    cout << " batchsize*channels*height*width = " << blob_1->count(0) << endl;
    cout << " channels*height*width = " << blob_1->count(1) << endl;
    cout << " height*width = " << blob_1->count(2) << endl;
    cout << " width = " << blob_1->count(3) << endl;

    for (int b=0; b<batchsize; ++b) {
        for (int c=0; c<channels; ++c) {
            for (int h=0; h<height; ++h) {
                for (int w=0; w<width; ++w) {
                    blob_1->mutable_cpu_data()[((b*channels + c)*height + h)*width + w] = 1.2;
                }
            }
        }
    }
    cout << "absolute sum : " << blob_1->asum_data() << endl;

    for (int b=0; b<batchsize; ++b) {
        for (int c=0; c<channels; ++c) {
            for (int h=0; h<height; ++h) {
                for (int w=0; w<width; ++w) {
                    cout << "the value at give index: " << blob_1->data_at(b, c, h, w) << endl;
                }
            }
        }
    }

    // fill a blob via uniform distribution
    caffe::FillerParameter filler_param;
    filler_param.set_min(-3);
    filler_param.set_max(3);
    caffe::UniformFiller<float> filler(filler_param);
    filler.Fill(blob_1);
    cout << "absolute sum : "<< blob_1->asum_data() << endl;
    delete blob_1;

    cout << "Press any key to exit!" << std::endl;
	getch();
    return 0;
}