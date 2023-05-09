# prototxt definition
+ See https://caffe.berkeleyvision.org/tutorial/layers.html for more info.
+ See https://github.com/BVLC/caffe/blob/master/src/caffe/proto/caffe.proto#L956-L983 for proto info.
### 1 - input layers
+ `type: ImageData`. Image Data - read raw images. 
  + `source: "data/train_list.txt"`. The 1st line of train_list.txt is "/path/to/myfirstimage.jpg 123", i.e., the path and the label. Make sure your '/my/path/file_list.txt' has this exact format: only one space (not tab or any other character) between the path and the label. There are no other white space characters after the label other than new line char indicating end of line.
+ `type: Data`. Database - read data from a LEVELDB or LMDB database. 
+ `type: Input`. Input - typically used for networks that are being deployed. 

```
layer {
  name: "data"
  type: "ImageData"
  top: "data"
  top: "label"
  include {
    phase: TRAIN
  }
  transform_param {
    mirror: false
    crop_size: 28
    scale: 0.0039215684
  }
  image_data_param {
    source: "data/train_list.txt"
    root_folder: "data/"
    batch_size: 8
    is_color: false
    new_height: 28
    new_width: 28
    shuffle: true
  }
}

layer {
  name: "data"
  type: "ImageData"
  top: "data"
  top: "label"
  include {
    phase: TEST
  }
  transform_param {
    mirror: false
    crop_size: 28
    scale: 0.0039215684
  }
  image_data_param {
    source: "data/test_list.txt"
    root_folder: "data/"
    batch_size: 8
    is_color: false
    new_height: 28
    new_width: 28
    shuffle: true
  }
}
```
```
layer {
  name: "data"
  type: "Data"
  top: "data"
  top: "label"
  include {
    phase: TEST
    stage: "test-on-train"//(or "test-on-test")
  }
  transform_param {
    mirror: false
    scale: 0.0039215684
    crop_size: 128
    mean_file: "data/train_mean.binaryproto"
  }
  data_param {
    source: "data/train_lmdb"
    batch_size: 8
    backend: LMDB
  }
}
```
```
layer {
  name: "data"
  type: "Input"
  top: "data"
  input_param { shape: { dim: 1 dim: 1 dim: 28 dim: 28 } }
  transform_param {
    mirror: false
    scale: 0.0039215684
  }
}
```
### 2 - vision layers
+ Convolution Layer - convolves the input image with a set of learnable filters, each producing one feature map in the output image.
+ Deconvolution Layer - transposed convolution.
+ Crop - perform cropping transformation.
```
layer {
  name: "conv1"
  type: "Convolution"
  bottom: "data"
  top: "conv1"
  param {
    lr_mult: 1
    decay_mult: 1
  }
  param {
    lr_mult: 2
    decay_mult: 0
  }
  convolution_param {
    num_output: 32
    kernel_size: 4
    stride: 2
    pad: 1
    weight_filler {
      type: "gaussian"
      std: 0.01
    }
    bias_filler {
      type: "constant"
      value: 0
    }
  }
}
```
```
layer {
  name: "deconv1"
  type: "Deconvolution"
  bottom: "relu1"
  top: "deconv1"
  param {
    lr_mult: 1
    decay_mult: 1
  }
  param {
    lr_mult: 1
    decay_mult: 1
  }
  convolution_param {
    num_output: 128
    kernel_size: 4
    stride: 1
    pad: 0
  }
}
```
### 3 - activation layers
```
layer {
  name: "relu1"
  type: "ReLU"
  bottom: "conv1"
  top: "relu1"
  relu_param {
    negative_slope: 0.2
  }
}
```
```
layer {
  name: "sigmoid"
  type: "Sigmoid"
  bottom: "inv_relu1"
  top: "sigmoid"
}
```
### 4 - loss layers
```
layer {
  name: "loss"
  type: "EuclideanLoss"
  bottom: "sigmoid"
  bottom: "data"
  top: "l2_error"
  loss_weight: 1.0
}
```
