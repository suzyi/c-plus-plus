:: generate img_list.txt
cd data
if EXIST train_list.txt rm -rf train_list.txt
if EXIST test_list.txt rm -rf test_list.txt
python generate_img_list.py
cd ..

:: generate img_lmdb
if EXIST data\train_lmdb rm -rf data\train_lmdb
if EXIST data\test_lmdb rm -rf data\test_lmdb
D:\libcaffe\caffe\build\tools\Release\convert_imageset.exe data\ data\train_list.txt data\train_lmdb --resize_width=128 --resize_height=128 --gray=true --shuffle=true
D:\libcaffe\caffe\build\tools\Release\convert_imageset.exe data\ data\test_list.txt data\test_lmdb --resize_width=128 --resize_height=128 --gray=true --shuffle=false

:: generate .binaryproto
D:\libcaffe\caffe\build\tools\Release\compute_image_mean.exe data\train_lmdb data\train_mean.binaryproto

:: train the model
if EXIST results rm -r results
mkdir results
D:\libcaffe\caffe\build\tools\Release\caffe.exe train -solver=models\solver.prototxt