# delete existed files and folders
cd data
for file in [ train_list.txt test_list.txt train_lmdb test_lmdb ];do
    if [ -e ${file} ];then
        echo deleting ${file}
        rm -rf ${file}
    fi
done

# generate train_list.txt and test_list.txt
python generate_img_list.py
cd ..

# generate img_lmdb
convert_imageset_exe=D:/libcaffe/caffe/build/tools/Release/convert_imageset.exe
${convert_imageset_exe} data/ data/train_list.txt data/train_lmdb --resize_width=128 --resize_height=128 --gray=true --shuffle=true
${convert_imageset_exe} data/ data/test_list.txt data/test_lmdb --resize_width=128 --resize_height=128 --gray=true --shuffle=false

# generate .binaryproto
compute_image_mean_exe=D:/libcaffe/caffe/build/tools/Release/compute_image_mean.exe
${compute_image_mean_exe} data/train_lmdb data/train_mean.binaryproto

# deleting existed trained files
for file in [ trained_files ];do
    if [ -e ${file} ];then
        echo deleting ${file}
        rm -rf ${file}
    fi
done
mkdir trained_files

# train the model
caffe_exe=D:/libcaffe/caffe/build/tools/Release/caffe.exe
${caffe_exe} train -solver=models/solver.prototxt