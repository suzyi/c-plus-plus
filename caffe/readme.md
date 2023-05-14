# Caffe
### 1 - Examples
All examples below are tested in Anaconda Prompt.
#### 1 - 1 use caffe
+ 0-install and then run your 1st example
  + [0-caffe_cpu_installation](0-caffe_cpu_installation.md)
  + [0-caffe_gpu_installation](0-caffe_gpu_installation.md). To-do: check again, May 13, 2023.
+ [1-hellocaffe](1-hellocaffe) 
  + is borrowed from [koosyong/caffestudy](https://github.com/koosyong/caffestudy/), with a minor modification made to the original CMakeLists.txt to make it runnable on Windows.
  + `run.cmd`
  + To-do: remove rng from main.cpp, which is difficult to understand at the very begining.
+ [2-understand dependencies](2-dependencies)
    + [2-1-gflags_glog_example](2-dependencies/2-1-gflags_glog_example)
      + `run.cmd`
+ [3-convert_imageset](3-convert_imageset)
  + `run_win.cmd`
+ [4-mnist_classification](4-mnist_classification)
  + `bash train.sh`
  + `bash test.sh`
+ classification task
  + [5-classification_inference](5-classification_inference)
+ segmentation task
  + to-do
+ [6-prototxt_definition](6-prototxt_definition)
+ [7-readAndWriteImgViaCaffeBlob](7-readAndWriteImgViaCaffeBlob)
+ 8-layers
  + [euclidean_loss_layer](./8-layers/euclidean_loss_layer/readme.md)
    + Calculate Euclidean distance via `math_functions.cpp`.
    + Calculate Euclidean distance via `euclidean_loss_layer.cpp`.
    + Calculate gradient of Euclidean layer, via `mse_layer.Backward(top, propagate_down, bottom);`
  + [sigmoid_layer](./8-layers/sigmoid_layer/)
    + `Forward` and `Backward`
+ [9-datumAndBlob](9-datumAndBlob)
  + Datum->cv::Mat->Blob
  + Blob->cv::Mat->Datum
#### 1 - 2 modify caffe
+ [10-add a new function to caffe](10-addNewFunctionsToCaffe/readme.md)
+ [11-add a new layer to caffe](11-addNewLayersToCaffe)
### 2 - Containers
+ `caffe::Blob<float> blob_1;` or `caffe::Blob<float> blob_1(int batchsize, int channels, int height, int width); blob_1.mutable_cpu_data()[((b*channels + c)*height + h)*width + w] = 0.5;`
  + `diff_.ReshapeLike(blob_1);`, if `blob_1` already exists. This function is commonly used in the subtraction of two blobs, i.e., `caffe::caffe_sub(blob_1->count(), blob_1->cpu_data(), blob_2->cpu_data(), diff_.mutable_cpu_data());`.
  + `blob_1->cpu_data()` vs `blob_1->mutable_cpu_data()`, the former is read-only, while the latter allows you to re-write its value.
  + `blob_1->cpu_diff(); for (int i=0; i<blob_1->count(); ++i) { cout << blob_1->cpu_diff()[i] << endl; }`
+ `Blob<Dtype>* const blob = new Blob<Dtype>(20, 30, 40, 50);` Binary long object
  + `blob->asum_data()`-absolute sum
  + `blob->channels()`
  + `blob->count()`-`batchsize*channels*height*width`
    + `blob->count(0)`-`batchsize*channels*height*width`
    + `blob->count(1)`-`channels*height*width`
    + `blob->count(2)`-`height*width`
    + `blob->count(3)`-`width`
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
+ Datum (A Datum is more like a single image, because a datum and a cv::Mat can be mutually converted to each other. A Blob is more like a batch of images.)
  + `caffe::Datum datum_;`
    + `caffe::ReadImageToDatum("1.png", string label, int height, int width, bool is_color, &datum_);`
    + `datum_.height();`
    + `datum_.width();`
    + `datum_.channels();`
    + There is no batchsize: `datum_.num();`
    + There is no absolute sum: `datum_.asum_data();`
    + There is no data at certain index: `datum_.data_at(c, h, w);`
    + `cv::Mat DecodeDatumToCVMat(const Datum& datum, bool is_color)`, or `cv::Mat DecodeDatumToCVMatNative(const Datum& datum)`
    + `void CVMatToDatum(const cv::Mat& cv_img, Datum* datum);`
    + From cv::Mat to Datum: `datum_.set_data(buffer);`, where `std::string buffer(datum_size, ' ');`. See [caffe/util/io.cpp](https://github.com/BVLC/caffe/blob/master/src/caffe/util/io.cpp) for more details.
    + From Datum to cv::Mat: `const string& data = datum.data();`
+ layer
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
