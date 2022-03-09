# caffe
This article contains
+ the installion of caffe on windows 10,
+ the classification task of MNIST using the installed caffe.
## 1 - Installation
There are many posts online sharing the installation of Caffe on Windows 10. Among them, three posts are mostly mentioned, i.e., 
+ [BVLC-caffe-windows](https://github.com/BVLC/caffe/tree/windows/). This one is the official document teaching people to install caffe. So we will follow it to complete our installation.
+ [willyd-caffe-builder](https://github.com/willyd/caffe-builder). willyd is a major contributor maintaining BVLC-caffe-windows. He also posted willyd-caffe-builder to help people install caffe in a easy way.
+ [microsoft-caffe](https://github.com/microsoft/caffe). Maintained by Microsoft, this repository adds some extra features uppon BVLC-caffe.

We follow the steps of BVLC-caffe-windows to build and install Caffe.
### 1-1- Install Visual Studio 2013
+ Install Visual Studio 2013 (vs 2013). [A Chinese tutorial of downloading and installing vs2013](https://jingyan.baidu.com/article/3ea5148999921f52e61bbae0.html) is helpful.
  + In fact, only the VS C/C++ compiler is required (cl.exe). 
  + After vs2013 is installed, you can find the VS C/C++ compiler (cl.exe) in `D:\vs2013\VC\bin\amd64\cl.exe`.
+ Test if VS 2013 works fine.
  + 1 do something
  + 2 do something
### 1-2- Install cmake
+ download a suitable cmake version for your computer from [cmake official website](https://cmake.org/download/). A suitable version here is a binary distribution "Windows x64 Installer".
+ double click the installer after the downloading is complete and then fill in a path where you want cmake be installed and proceed to complete the installation.
+ test if the cmake is successfully installed by opening powershell or cmd and run `cmake -version`.
### 1-3- Install Anaconda and required packages
[Download and Install the latest version of Anaconda](https://www.anaconda.com/?modal=nucleus)

After Anaconda is installed, open an Anaconda Propt to install python 2.7 by following steps:
```
# it outputs python 3.9
(base)> python --version

# create a virtual environment with python 2.7
(base)> conda create --name forCaffe python=2.7

# check all existed environments to see if forCaffe exists
(base)> conda info --envs

# activate
(base)> conda activate forCaffe
(forCaffe)> python --version # now, it should give python 2.7

# install ninja and git
(forCaffe)> conda install -c anaconda git

# check if every thing goes well
(forCaffe)> cmake --version
(forCaffe)> git --version
(forCaffe)> python --version
```
Expected results are
<p align="center">
  <img src="check_before_installation.png" width="400" title="check_before_installation">
</p>

### 1-4- Install Caffe
With all requirements met, we can now install caffe.

Firstly, 
+ Create an empty folder to install caffe, e.g., "D:\libcaffe\".
+ Open an Anaconda Prompt and then
  + `(base)D:\libcaffe> conda activate forCaffe`
  + `(forCaffe)D:\libcaffe> git clone https://github.com/BVLC/caffe.git`
  + `(forCaffe)D:\libcaffe> cd caffe`
  + `(forCaffe)D:\libcaffe>caffe> git checkout windows`. This line will create the file "D:\libcaffe\caffe\scripts\build_win.cmd"

Next, edit the file "D:\libcaffe\caffe\scripts\build_win.cmd" to a wanted configuration.
+ If you have CUDA installed but want a CPU-only version you can set `-DCPU_ONLY=1`.
+ If Python is installed the default is to build the python interface and python layers. If you wish to disable the python layers or the python build use the CMake options `-DBUILD_python_layer=0` and `-DBUILD_python=0` respectively.
+ `set WITH_NINJA=0` disables ninja generator.
+ `set MSVC_VERSION=12` specifies "Visual Stutio 12 2013 Win64" generator.
+ `set CPU_ONLY=1` disables GPU and enable CPU.
+ `set PYTHON_VERSION=2` specifies python 2.7
+ `set BUILD_PYTHON=0` and `set BUILD_PYTHON_LAYER=0` will not support python interface.
+ `set BUILD_MATLAB=0` will not support matlab interface.

In addition, we'd better download the file "libraries_v120_x64_py27_1.1.0.tar" for Internet and place it to the path "C:\Users\jack\.caffe\dependencies\download\libraries_v120_x64_py27_1.1.0.tar". It contains some libraries that Caffe requires. Although this step is optional, we highly recommend you to follow this to avoid a bad network connection issue.

Finally, 
+ `(forCaffe)D:\libcaffe>caffe> scripts\build_win.cmd`

Up to now, Caffe is successfully installed. To verify this, we need run the classification task of MNIST in the next Section.

### 1-5- Run the classification task of MNIST to check if Caffe works fine
+ [run this example to check if caffe is successfully installed](https://caffe.berkeleyvision.org/gathered/examples/mnist.html)
  + build/examples/mnist/convert_mnist_data.bin: No such file or directory. Since Caffe is build on Windows 10, so .bin will not be generated. In stead, use "D:\libcaffe\caffe\build\examples\mnist\Release\convert_mnist_data.exe" to generate data.
  + build/tools/caffe: No such file or directory. Solution: caffe.exe can be found at "D:\libcaffe\caffe\build\tools\Release\caffe.exe"

## 2- Possible errors encounterd during installation
+ error 1: vs compiler is not found. To solve this error, edit the file "caffe/scripts/build_win.cmd" so that all `WITH_NINJA` are set to `0`, to use VS generator and disable NINJA.

Add these lines at the top (must be added before you use `project()` command)
```
set(CMAKE_C_COMPILER "D:/vs2013/VC/bin/amd64/cl.exe")
set(CMAKE_CXX_COMPILER "D:/vs2013/VC/bin/amd64/cl.exe")
```
+ error2: Since `%VS120COMNTOOLS%` points to `'D:\vs2013\Common7\Tools\'`, so `call "%VS120COMNTOOLS%..\..\VC\vcvarsall.bat" amd64` equals `call "D:\vs2013\VC\vcvarsall.bat" amd64`
+ error3: VS 2013, version 12.0, MSC_VER=1800; VS 2015, version 14.0
+ error4: `cmake -G "Visual Studio 12 2013 Win64" -C D:\libcaffe\caffe-builder\build_v120_x64\libraries\caffe-build-config.cmake ..`, where `CMAKE_GENERATOR=Visual Studio 12 2013 Win64`
+ error5: After the installation of vs2013 is done, create a simple project to test it.
  + If error `-- The C compiler identification is unknown-- The CXX compiler identification is unknown` occurred, then copy "rc.exe" and "rcdll.dll" from "C:\Program Files (x86)\Windows Kits\8.1\bin\x86\" to replace "D:\vs2013\VC\bin\".
### 3- Further examples
+ Classification
+ Segmentation
