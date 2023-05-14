exe=D:/libcaffe/caffe/build/examples/cpp_classification/Release/classification.exe
model_file=models/deploy.prototxt
trained_file=trained_files/trained_model_iter_200.caffemodel
mean_file=data/train_mean.binaryproto
label_file=data/label2words.txt


# infer all images in the path data/test/
for ((i=0;i<=2;i=i+1));do
     for file in data/test/${i}/*.png;do
          ${exe} ${model_file} ${trained_file} ${mean_file} ${label_file} ${file}
     done
done