# caffe::EuclideanLossLayer
### 1 - Forward
In [caffe's official description](http://caffe.berkeleyvision.org/doxygen/classcaffe_1_1EuclideanLossLayer.html#details) the mathematical equation of Euclidean loss is
```
loss = 1/(2*N) sum_{i=1}^{N} ||x_i - y_i ||^2,
```
where `x_i` is a predicted scalar, and `y_i` is the true label. But you will find by reading [its source code](https://github.com/BVLC/caffe/blob/master/src/caffe/layers/euclidean_loss_layer.cpp#LL27C36-L27C36) that the equation it used in fact is
```
loss_{euclidean} = 1/2 sum_{i=1}^{N} ||x_i - y_i ||^2.
```
### 2 - Backward
When calculating gradient, caffe uses cumulative loss,
```
loss_{cumulative} = \alpha_{euclidean} * loss_{euclidean} + \alpha_{other} * loss_{other}.
```
As a result, the gradient looks like
```
\frac{\partial loss_{cumulative}}{\partial x_i} = \alpha_{euclidean} * (x_i - y_i),
```
which is exactly the same as in [the source code](https://github.com/BVLC/caffe/blob/master/src/caffe/layers/euclidean_loss_layer.cpp#L40) and a little different from [its documentation](http://caffe.berkeleyvision.org/doxygen/classcaffe_1_1EuclideanLossLayer.html#details).