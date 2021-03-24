# cmake
### installation
To install cmake on your computer, follow these steps,
+ download a suitable cmake version for your computer from [cmake official website](https://cmake.org/download/). A suitable version here is a binary distribution "Windows x64 Installer".
+ double click the installer after the downloading is complete and then fill in a path where you want cmake be installed and proceed to complete the installation.
+ test if the cmake is successfully installed by opening powershell or cmd and run "cmake".
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
