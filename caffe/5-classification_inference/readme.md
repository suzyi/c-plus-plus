### inference using a classication network
+ Download [bvlc_reference_caffenet.caffemodel](http://dl.caffe.berkeleyvision.org/bvlc_reference_caffenet.caffemodel)
+ Download [caffe_ilsvrc12.tar.gz](http://dl.caffe.berkeleyvision.org/caffe_ilsvrc12.tar.gz) and uncompress it.
+ `D:\libcaffe\caffe\build\examples\cpp_classification\Release\classification.exe D:\libcaffe\caffe\models\bvlc_reference_caffenet\deploy.prototxt bvlc_reference_caffenet.caffemodel caffe_ilsvrc12\imagenet_mean.binaryproto caffe_ilsvrc12\synset_words.txt D:\libcaffe\caffe\examples\images\cat.jpg`