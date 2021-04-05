# libtorch
Today is Wednesday, Feb 24, 2021.
### 1 - download the libtorch from the official website
Before downloading, I should say that we don't need any VPN for downloading the libtorch.
+ step 1. Go to the website "https://pytorch.org/get-started/locally/".
+ step 2. Set 
  + "PyTorch Build" to "Stable(version number)"
  + "Your OS" to "Windows"
  + "Package" to "LibTorch"
  + "Language" to "C++/Java"
  + "CUDA" to CUDA version which can be found by following the steps below:
    + substep 1. go to the Desktop of your computer
    + substep 2. right click and then choose "Nvidia Control panel"
    + substep 3. "Help" -> "System Info" -> "组件" -> "3D settings", then you will see "NVCUDA.DLL" whose product name is "NVIDIA CUDA 10.2.132 driver" for example, in which "10.2" is the CUDA version you are seeking for.
    + Or without these complicated steps above, you can simply open you cmd or powershell and run the command "nvidia-smi.exe" which will then tells you the CUDA Version.
+ step 3. download the debug version and then unzip it to your preferred directory. For examle, mine is "D:\libtorch-debug-1.7.1\libtorch"
### 2 - deploy the libtorch on Visual Studio 2019 without and with cmake
There are two ways to deploy libtorch on Visual Studio 2019, i.e., without and with the help of cmake.
#### 2 - 1 without cmake
Before deploying libtorch on Visual Studio, I assume that you've installed Visual Studio 2019 on your computer and your OS is Windows 10. The deploying procedure below may work as well on other computer configuration with a little change.

1. Add necessary environment path by following steps below:
+ step 1. Press the "Windows" on your keyboard and input "environ", then choose to open environment variable editing interface.
+ step 2. Choose the "system variable" -> "Path" and then add "D:\libtorch-debug-1.7.1\libtorch\lib" to the Path.
+ step 3. Reboot your computer to make this change work.

2. Create an empty project in Visual Studio 2019 and then deploy the libtorch on Visual Studio 2019:
+ step 1. Open Visual Studio, then click "Create a new project" -> "Empty project (Console, C++, Windows)" -> "Next", and then set the "Project name" to "hellolibtorch", then click "Create".
+ step 2. On the interface of "Solution Explorer", right click "Resource Files" -> "add" -> "New Item...", and then choose "C++ File" and name it to "hello.cpp", then click "Add" to create a cpp file.
+ step 3. Right click the project name "hellolibtorch" and then choose "Properties", you will see the "hellolibtorch Property Pages".
+ step 4. "VC++ Directories" -> "Include Directories", add two lines "D:\libtorch-debug-1.7.1\libtorch\include" and "D:\libtorch-debug-1.7.1\libtorch\include\torch\csrc\api\include".
+ step 5. "Linker" -> 
  + "General" -> "Additional Library Directories", add "D:\libtorch-debug-1.7.1\libtorch\lib" to here.
  + "Input" -> "Additional Dependencies", add the names of all .lib file under the directory "D:\libtorch-debug-1.7.1\libtorch\lib", for example, mine is 
```
asmjit.lib
c10.lib
c10_cuda.lib
c10d.lib
caffe2_detectron_ops_gpu.lib
caffe2_module_test_dynamic.lib
caffe2_nvrtc.lib
clog.lib
cpuinfo.lib
dnnl.lib
fbgemm.lib
gloo.lib
gloo_cuda.lib
libprotobufd.lib
libprotobuf-lited.lib
libprotocd.lib
mkldnn.lib
torch.lib
torch_cpu.lib
torch_cuda.lib
```
+ step 6. "C/C++" -> 
  +  "General" -> "SDL checks" is modified to "No".
  +  "Language" -> "Conformance mode" is modified to "No".
  +  "General" -> "Additional Include Directories", add this line "D:\libtorch-debug-1.7.1\libtorch\include;D:\libtorch-debug-1.7.1\libtorch\include\torch\csrc\api\include".
+ step 7. Open the file "hello.cpp" created previously and copy the code below and paste into it:
```

#include <iostream>
#include <torch/torch.h>
 
int main()
{
    torch::Tensor tensor = torch::rand({ 5,3 });
    std::cout << tensor << std::endl;
    return EXIT_SUCCESS;
}
```
+ step 8. Change the "Configuration" to "Active(Debug)" and "Platform" to "x64".
+ step 9. Click "Local Windows Debugger" or alternatively, click "Build" -> "Build Solution" and then "Debug" -> "Start Debugging". After doing this, if you see right output, then the libtorch is correctly deployed on your machine.
+ step 10. If you close the project "hellolibtorch", just go to the directory where it was created and click "hellotorch.vcxproj", then the project will be opened.
#### 2 - 2 with cmake
With the help of cmake, it's easier to deploy libtorch on Visual Studio 2019. Just follow the steps below.

Firstly, make sure you have a folder called "print_tensor" which contains these files within it:
```
print_tensor
— build # build is an empty folder.
— main.cpp
— CMakeLists.txt
```
Here "main.cpp" contains
```
#include <torch/torch.h>
#include <iostream>

int main() {
	at::Tensor tensor = torch::rand({ 2, 3 });
	std::cout << tensor << std::endl;
}
```
and "CMakeLists.txt" contains
```
cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
project(print_tensor)

find_package(Torch REQUIRED)

if(NOT Torch_FOUND)
    message(FATAL_ERROR "Pytorch Not Found!")
endif(NOT Torch_FOUND)

message(STATUS "Here is Torch_DIR: ${Torch_DIR}")
message(STATUS "Pytorch status:")
message(STATUS "    libraries: ${TORCH_LIBRARIES}")

add_executable(print_tensor main.cpp)
target_link_libraries(print_tensor ${TORCH_LIBRARIES})
set_property(TARGET print_tensor PROPERTY CXX_STANDARD 11)
```

Secondly, open your powshell or cmd and then navigate to the empty folder "build" mentioned above. Run this line 
```
cmake -DCMAKE_PREFIX_PATH=D:\libtorch-win-debug-1.8.1-cpu\libtorch -DCMAKE_BUILD_TYPE=Release "Visual Studio 16 2019 Win64" ..
```
and it will return you some info like
```
-- Building for: Visual Studio 16 2019
-- Selecting Windows SDK version 10.0.18362.0 to target Windows 10.0.18363.
-- The C compiler identification is MSVC 19.26.28806.0
-- The CXX compiler identification is MSVC 19.26.28806.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: D:/Microsoft Visual Studio/2019/Community/VC/Tools/MSVC/14.26.28801/bin/Hostx64/x64/cl.exe - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: D:/Microsoft Visual Studio/2019/Community/VC/Tools/MSVC/14.26.28801/bin/Hostx64/x64/cl.exe - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Looking for pthread.h
-- Looking for pthread.h - not found
-- Found Threads: TRUE
-- Found Torch: D:/libtorch-win-debug-1.8.1-cpu/libtorch/lib/torch.lib
-- Here is Torch_DIR: D:/libtorch-win-debug-1.8.1-cpu/libtorch/share/cmake/Torch
-- Pytorch status:
-- here is libraries: torch;torch_library;D:/libtorch-win-debug-1.8.1-cpu/libtorch/lib/c10.lib
-- Configuring done
-- Generating done
-- Build files have been written to: F:/cpp20200707/libtorch-examples-20210224/print_tensor_using_cmake20210326/build
```
if the code is successfully configured.

Thirdly, go to the directory "print_tensor/build" and open the file "print_tensor.vcxproj" using Visual Studio 2019. Then in the VS2019 interface you will see a "Solution Explorer" and then right click on the bold "print_tensor" to choose "Set as Startup Project".

Finally, set the mode to "Release, x64" and left click "Local Windows Debugger" which will return you the expected output. After this, you can find "print_tensor.exe" from the directory "print_tensor/build/Release/".

You may encounter some errors such as "XXX.dll is missing". In this case, just copy all .dll files from "D:\libtorch-win-debug-1.8.1-cpu\libtorch\lib" to "print_tensor/build/release/" and the try again.

**Just one more paragraph**, `cmake -DCMAKE_PREFIX_PATH=D:\libtorch-win-debug-1.8.1-cpu\libtorch -DCMAKE_BUILD_TYPE=Release "Visual Studio 16 2019 Win64" ..` is just one option. Another method is
+ substitute `find_package(Torch REQUIRED)` into `find_package(Torch REQUIRED)` in the "CMakeLists.txt".
+ run `cmake "Visual Studio 16 2019 Win64" ..` in the command line.

To understand why this would work, just check [cmake-basics:how does find_package work?](https://github.com/suzyi/cpp/blob/master/cmake/basics.md#4---how-does-find_package-work).
### 3 - libtorch examples
+ [linear regression](https://github.com/suzyi/cpp/blob/master/deep-learning/linearRegression.cpp): contain the source cpp file of a toy example of linear regression.
