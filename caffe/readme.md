# Caffe
### 1 - Examples
+ [0-installation and running the 1st example](0-caffe_cpu_installation.md)
+ [1-hellocaffe](1-hellocaffe) is borrowed from [koosyong/caffestudy](https://github.com/koosyong/caffestudy/), with a minor modification made to the original CMakeLists.txt to make the project runnable on Windows.
  + `mkdir build && cd build`->`cmake .. -A x64`->`cmake --build . --config Release`->`Release\hellocaffe.exe`
+ [3-convert_imageset](3-convert_imageset)
  + `run_win.cmd`
+ Classification
+ Segmentation

### 2 - Containers
+ `Blob<Dtype>* const blob = new Blob<Dtype>(20, 30, 40, 50);` Binary long object
  + `blob->asum_data()`-absolute sum
  + `blob->channels()`
  + `blob->count()`-`batchsize*channels*height*width`
  + `blob->cpu_data()`
  + `blob->gpu_data()`
  + `blob->height()`
  + `blob->mutable_cpu_data()`
  + `blob->num()`-batchsize
  + `blob->offset(100,0,0,0)`
  + `blob->Reshape(50, 40, 30, 20)`
  + `blob->sumsq_data()`
  + `blob->width()`
+ `caffe::InnerProductLayer< Dtype > Class Template Reference`
  + `LayerParameter layer_ip_param; InnerProductLayer<Dtype> layer_ip(layer_ip_param);`
### 3 - exe
+ `build\tools\Release\convert_imageset.exe data\re\ data\re\trainlist.txt data\re\img_train_lmdb`
+ `build\tools\Release\compute_image_mean.exe data\re\img_train_lmdb data\mean.binaryproto`
+ `build\tools\Release\caffe.exe train -solver=data\re\solver.prototxt`

### 4 - folder tree
```
data\
  Scritps used to download dataset needed.
examples\
  Examples used to show usage of caffe.
include\
  All header files.
matlab\
python\
tools\
  caffe.cpp will be compiled to caffe.exe, which allows training and infering in the terminal.
  Data processing tools.
scripts\
src\
```