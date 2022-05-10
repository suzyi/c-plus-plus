# prototxt definition
See https://caffe.berkeleyvision.org/tutorial/layers.html for more info.
### 1 - input layers
+ Image Data - read raw images. `type: ImageData`
+ Database - read data from a LEVELDB or LMDB database. `type: Data`
+ Input - typically used for networks that are being deployed. `type: Input`

```
layer {
  name: "data"
  type: "ImageData"
  top: "data"
  transform_param {
    mirror: false
    crop_size: 28
  }
  image_data_param {
    source: "data/train_list.txt"
    batch_size: 4
    new_height: 28
    new_width: 28
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
    phase: TRAIN
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