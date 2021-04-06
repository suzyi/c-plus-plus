# custom a dataset using libtorch and opencv
### requirements
This project is tested on a platform meeting such requirements:
```
+ Windows x64
+ Visual Studio 2019
+ libtorch-win-debug-1.8.1-cpu
+ opencv-4.5.1
+ cmake 3.20.0
```

Before runing this project, we highly recommend you to read a toy demo []() which will tells you how to deloy a project on a platform with requirements above.
### folder tree
This project is modified from [pytorch-examples-custom-dataset](https://github.com/pytorch/examples/tree/master/cpp/custom-dataset) and organized in a tree structure.
```
custom-dataset/
|--custorm-dataset.cpp
|--CMakeLists.txt
|--info.txt
```

### building
Open your "powershell" or "cmd", and navigate to the folder "custom-dataset", then
```
$ mkdir build
$ cd build
$ cmake "Visual Studio 16 2019 Win64" ..
```
