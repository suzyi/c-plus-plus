# Caffe
### 1 - Examples
All examples below are tested in Anaconda Prompt.
+ [0-installation and running the 1st example](0-caffe_cpu_installation.md)
+ [1-hellocaffe](1-hellocaffe) is borrowed from [koosyong/caffestudy](https://github.com/koosyong/caffestudy/), with a minor modification made to the original CMakeLists.txt to make the project runnable on Windows.
  + `run.cmd`
+ [2-dependencies](2-dependencies)
    + [2-1-gflags_glog_example](2-dependencies/2-1-gflags_glog_example)
      + `run.cmd`
+ [3-convert_imageset](3-convert_imageset)
  + `run_win.cmd`
+ [4-mnist_classification](4-mnist_classification)
  + `bash train.sh`
  + `bash test.sh`
+ [5-classification_inference](5-classification_inference)
+ [6-prototxt_definition](6-prototxt_definition)
+ Segmentation

### 2 - Containers
+ `Blob<Dtype>* const blob = new Blob<Dtype>(20, 30, 40, 50);` Binary long object
  + `blob->asum_data()`-absolute sum
  + `blob->channels()`
  + `blob->count()`-`batchsize*channels*height*width`
  + `blob->cpu_data()`
  + `blob->data_at(0, 1, 43, 32);` - the value at given index.
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
+ net (when should . and -> be used?what's their difference?)
  + `shared_ptr<Net<float> > net_;`
  + `net_.reset(new Net<float>(model_file, TEST));`
  + `net_->CopyTrainedLayersFrom(trained_file);`
  + `CHECK_EQ(net_->num_inputs(), 1) << "Network should have exactly one input.";`
  + `CHECK_EQ(net_->num_outputs(), 1) << "Network should have exactly one output.";`
  + `Blob<float>* input_layer = net_->input_blobs()[0];`
  + `Blob<float>* output_layer = net_->output_blobs()[0];`
  + `net_->Reshape();`
  + `net_->Forward();`
  + `const shared_ptr<Blob<float> > prob_blob = net_->blob_by_name("prob"); std::vector<float> prob_vec = std::vector<float>(prob_blob->cpu_data(), prob_blob->cpu_data()+prob_blob->count());`
    + `for (int i=0; i<prob_vec.size(); i++) {std::cout << "prob_vec[" << i << "]: " << prob_vec[i] << std::endl;}`
### 3 - exe
+ `build\tools\Release\convert_imageset.exe data\re\ data\re\trainlist.txt data\re\img_train_lmdb --resize_width=32 --resize_height=32 --gray=true --shuffle=false`
+ `build\tools\Release\compute_image_mean.exe data\re\img_train_lmdb data\mean.binaryproto`
+ `build\tools\Release\caffe.exe train -solver=data\re\solver.prototxt`
+ `build\tools\Release\caffe.exe test -model examples\mnist\lenet_train_test.prototxt -weights examples\mnist\lenet_iter_10000.caffemodel -gpu 0 -iterations 100`

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
+ A nice website to visualize image pixel: https://pixspy.com/
