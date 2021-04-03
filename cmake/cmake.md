# cmake
### 1 - installing cmake on windows 10
To install cmake on your computer, follow these steps,
+ download a suitable cmake version for your computer from [cmake official website](https://cmake.org/download/). A suitable version here is a binary distribution "Windows x64 Installer".
+ double click the installer after the downloading is complete and then fill in a path where you want cmake be installed and proceed to complete the installation.
+ test if the cmake is successfully installed by opening powershell or cmd and run "cmake -version".

### 2 - [basics](https://github.com/suzyi/cpp/blob/master/cmake/basics.md)
### 3 - deploy libtorch on Visual Studio 2019 using cmake
Check [here](https://github.com/suzyi/cpp/blob/master/deep-learning/libtorch.md) for an explicit documentation.
### 3 - 1 intro
Generally, three files (one .h header file and two .cpp files) are contained within a c++ project. The .h (Header.h for example) file simply declares needed classes for the project but doesn't constain any further information. Then the specific definitions and operations of those classes are written in one corresponding .cpp (Hello.cpp for example) file. The remaining .cpp-often named as main.cpp, file acts to show you how to call those classes to complete a certain task.

Here you can find a nice [project](https://github.com/ttroy50/cmake-examples/tree/master/01-basic/C-static-library) to demonstrate the relationship among Header.h, Hello.cpp and main.cpp, which is summarized as 
+ Header.h ---> Hello.cpp via target_include_directories, i.e., `target_include_directories(project_name PUBLIC ${PROJECT_SOURCE_DIR}/include)`, where Header.h is placed under the directory "${PROJECT_SOURCE_DIR}/include".
+ Hello.cpp --> .exe via target_link_libraries, i.e., `target_link_libraries(exe_name PRIVATE project_name)`.
+ main.cpp ---> .exe via add_executable, i.e., `add_executable(exe_name src/main.cpp)`.

### common directory variables
+ CMAKE_SOURCE_DIR:
+ CMAKE_CURRENT_SOURCE_DIR:
+ PROJECT_SOURCE_DIR: For example, in the project [C-static-library](https://github.com/ttroy50/cmake-examples/tree/master/01-basic/C-static-library), the PROJECT_SOURCE_DIR is the directory `C-static-library`.
+ CMAKE_BINARY_DIR: The root or top level folder that you run the cmake command from is known as your CMAKE_BINARY_DIR and is the root folder for all your binary files. For example, in the project [C-static-library](https://github.com/ttroy50/cmake-examples/tree/master/01-basic/C-static-library), the CMAKE_BINARY_DIR is `C-static-library/build`.
+ CMAKE_CURRENT_BINARY_DIR:
+ PROJECT_BINARY_DIR:
### the most important three components in a CMakeLists.txt
+ header files, which are in "projectname/include/\*.h"
+ source files, which are in "projectname/src/\*.cpp"
+ executable, which is in "projectname/build/"
### useful commands
+ `message(${PROJECT_SOURCE_DIR})` prints the content the variable `PROJECT_SOURCE_DIR` represents.
