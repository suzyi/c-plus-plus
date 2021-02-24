# libtorch
Today is Wednesday, Feb 24, 2021.
### 1 - download the libtorch from the official website
### 2 - deploy the libtorch on Visual Studio 2019
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
+ step 8. Click "Local Windows Debugger" or alternatively, click "Build" -> "Build Solution" and then "Debug" -> "Start Debugging".