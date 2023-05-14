# Add New Layers to Caffe
https://github.com/BVLC/caffe/issues/684
### 1 - Create "my_euclidean_loss_layer" with the Help of Existed "euclidean_loss_layer"
The most simple way to create your first caffe layer is copying an already existed layer and then rename it. Take "my_euclidean_loss_layer" as an example to illustrate.
+ Step 1: generate and then modify "my_euclidean_loss_layer.hpp".
+ Step 2: generate and then modify "my_euclidean_loss_layer.cpp".
// + Step 3 (required for convolution, activation layers): modify "layer_factory.cpp".
