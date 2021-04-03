# cmake
### 1 - installing cmake on windows 10
To install cmake on your computer, follow these steps,
+ download a suitable cmake version for your computer from [cmake official website](https://cmake.org/download/). A suitable version here is a binary distribution "Windows x64 Installer".
+ double click the installer after the downloading is complete and then fill in a path where you want cmake be installed and proceed to complete the installation.
+ test if the cmake is successfully installed by opening powershell or cmd and run "cmake -version".

### 2 - basics
In this section, we use the ttroy50's [C-static-library](https://github.com/ttroy50/cmake-examples/tree/master/01-basic/C-static-library) to introduce you some basics about cmake, including add_library, target_include_directories, add_executable and target_link_libraries. But with a few modification to the file "CMakeLists.txt" to make it more understandable. We will split "CMakeLists.txt" below into several subsections to understand it.
```
# CMakeLists.txt
cmake_minimum_required(VERSION 3.5)

project(project_name)

############################################################
# Create a library
############################################################

#Generate the static library from the library sources
add_library(library_name STATIC 
    src/Hello.cpp
)

target_include_directories(library_name
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/include
)


############################################################
# Create an executable
############################################################

# Add an executable with the above sources
add_executable(hello_binary 
    src/main.cpp
)

# link the new hello_library target with the hello_binary target
target_link_libraries( hello_binary
    PRIVATE 
        library_name
)
```
#### 2 - 1 add_library
By using the following sample code, you will see the file "library_name.lib" is generated and placed to the directory "project_name/build/Debug/".
```
# Generate the static library from the library sources
add_library(library_name STATIC 
    src/Hello.cpp
)
```
#### 2 - 2 target_include_directories
The following code tells the library (i.e., the library_name.lib, or Hello.cpp) that where its needed header file is placed.
```
target_include_directories(library_name
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/include
)
```
### 2 - 3 add_executable
As we know, "main.cpp" performs a certain task and shows you how can we call all those defined classes in the header file. To make it runnable, the build-in command add_executable generates a hello_binary from "main.cpp". Then you can find it at "project_name/build/hello_binary" when the OS is Linux and "project_name/build/hello_binary.vcxproj" when OS is Windows 10.
```
add_executable(hello_binary 
    src/main.cpp
)
```
#### target_link_libraries
target_link_libraries is used to tell the .exe (also named as binary file or executable file) where the library (equivalent to the header file) is placed at.
```
# link the new hello_library target with the hello_binary target
target_link_libraries( hello_binary
    PRIVATE 
        library_name
)
```
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
