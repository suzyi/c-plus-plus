# Caffe
### 1 - Installation
+ [0-installation and running the 1st example](https://github.com/suzyi/cpp/blob/master/caffe/0-caffe_installation.md)

### 2 - Basic Examples
Examples below are copied and modified from this repository [koosyong/caffestudy](https://github.com/koosyong/caffestudy/):
+ [1-hellocaffe](https://github.com/suzyi/cpp/tree/master/caffe/1-hellocaffe)

When compiling these examples, I suffered from error messages such as "glog.cmake" is missing. To alleviate this, an alternative way is putting these files and aranging them like below. Then rebuild the caffe project from scratch.
<p align="center">
  <img src="imgs/how_to_run_examples.png" width="550" title="how_to_run_examples.png">
</p>

### 3 - Further Examples
+ Classification
+ Segmentation

### 4 - Containers
+ `Blob<Dtype>* const blob = new Blob<Dtype>(20, 30, 40, 50);`
  + `blob->asum_data()`-absolute sum
  + `blob->channels()`
  + `blob->count()`-`batchsize*channels*height*width`
  + `blob->cpu_data()`
  + `blob->height()`
  + `blob->num()`-batchsize
  + `blob->width()`
