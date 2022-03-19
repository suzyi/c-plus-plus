# basics
### loop and file operation
```
cmake_minimum_required(VERSION 3.2)
message("PROJECT_SOURCE_DIR: ${PROJECT_SOURCE_DIR}")
message("PROJECT_BINARY_DIR: ${PROJECT_BINARY_DIR}")
if(MSVC)
  message("MSVC found")
endif()

file(GLOB_RECURSE examples_srcs "images/*.png")

foreach(source_file ${examples_srcs})
  # get file name (variable, filename, mode), NAME_WE--name without extension
  get_filename_component(name ${source_file} NAME_WE)

  # get folder name
  get_filename_component(path ${source_file} PATH)
  get_filename_component(folder ${path} NAME_WE)
  message("---------")
  message("source_file: ${source_file}")
  message("name: ${name}")
  message("path: ${path}")
  message("folder: ${folder}")
endforeach()
```
results in 
```
PROJECT_SOURCE_DIR: C:/Users/me/Downloads/convert_mnist
PROJECT_BINARY_DIR: C:/Users/me/Downloads/convert_mnist/build
MSVC found
---------
source_file: C:/Users/me/Downloads/convert_mnist/images/89.png
name: 89
path: C:/Users/me/Downloads/convert_mnist/images
folder: images
---------
source_file: C:/Users/me/Downloads/convert_mnist/images/91.png
name: 91
path: C:/Users/me/Downloads/convert_mnist/images
folder: images
---------
source_file: C:/Users/me/Downloads/convert_mnist/images/97.png
name: 97
path: C:/Users/me/Downloads/convert_mnist/images
folder: images
```
### 1 - understanding [C-static-library](https://github.com/ttroy50/cmake-examples/tree/master/01-basic/C-static-library)
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
#### add_library
By using the following sample code, you will see the file "library_name.lib" is generated and placed to the directory "project_name/build/Debug/".
```
# Generate the static library from the library sources
add_library(library_name STATIC 
    src/Hello.cpp
)
```
#### target_include_directories
The following code tells the library (i.e., the library_name.lib, or Hello.cpp) that where its needed header file is placed.
```
target_include_directories(library_name
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/include
)
```
#### add_executable
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
### 2 - understanding [H-third-party-library](https://github.com/ttroy50/cmake-examples/tree/master/01-basic/H-third-party-library)
#### find_package
find_package tries to find an external project, and load its settings. <PackageName>_FOUND will be set to indicate whether the package was found.

This will search for CMake modules in the format "FindXXX.cmake" from the list of folders in CMAKE_MODULE_PATH. On linux the default search path will include /usr/share/cmake/Modules. On my system this includes support for approximately 142 common third party libraries.

As below, find_package tries to find two libraries, i.e., "filesystem" and "system", from the third-party package "Boost 1.46.1".
```
find_package(Boost 1.46.1 REQUIRED COMPONENTS filesystem system)
```
The arguments are:
+ Boost - Name of the library. This is part of used to find the module file FindBoost.cmake.
+ COMPONENTS - The list of libraries to find.
### Boost_FOUND
Most included packages will set a variable "XXX_FOUND", which can be used to check if the package is available on the system. In this example the variable is "Boost_FOUND":
```
if(Boost_FOUND)
    message ("boost found")
    include_directories(${Boost_INCLUDE_DIRS})
else()
    message (FATAL_ERROR "Cannot find Boost")
endif()
```
### include_directories and Boost_INCLUDE_DIRS
After a package is found it will often export variables which can inform the user where to find the library, header, or executable files. Similar to the XXX_FOUND variable, these are package specific and are typically documented at the top of the FindXXX.cmake file. The variables exported in this example include:
+ Boost_INCLUDE_DIRS - The path to the boost header files.
Or more generally, 
+ xxx_INCLUDE_DIRS - A variable pointing to the header files.
+ xxx_LIBRARY - A variable pointing to the library path.
These can then be added to your target_include_directories and target_link_libraries as:
```
# Include the boost headers
target_include_directories( third_party_include
    PRIVATE ${Boost_INCLUDE_DIRS}
)

# link against the boost libraries
target_link_libraries( third_party_include
    PRIVATE
    ${Boost_SYSTEM_LIBRARY}
    ${Boost_FILESYSTEM_LIBRARY}
)
```
### 3 - command line, variables and functions
+ command line
  + `cmake ..`
    + `cmake -DCMAKE_PREFIX_PATH=D:\libtorch-win-debug-1.8.1-cpu\libtorch "Visual Studio 16 2019 Win64" ..` or `cmake "Visual Studio 16 2019 Win64" ..`
  + `cmake --build .`
    + `cmake --build . --config Release` or `Debug`
    + `cmake --build . --target runtest --config Debug`
+ variables
  + CMAKE_GENERATOR
    + `set CMAKE_GENERATOR=Visual Studio 12 2013 Win64`, `set CMAKE_GENERATOR=Visual Studio 14 2015 Win64`, or `set CMAKE_GENERATOR=Ninja`
  + CMAKE_PREFIX_PATH
  + ThirdPartyPackage_DIR, Torch_DIR and OpenCV_DIR for example under which you can find "TorchConfig.cmake" and "OpenCVConfig.cmake", respectively.
  + CMAKE_SOURCE_DIR:
  + CMAKE_CURRENT_SOURCE_DIR:
  + PROJECT_SOURCE_DIR: For example, in the project [C-static-library](https://github.com/ttroy50/cmake-examples/tree/master/01-basic/C-static-library), the PROJECT_SOURCE_DIR is the directory `C-static-library`.
  + CMAKE_BINARY_DIR: The root or top level folder that you run the cmake command from is known as your CMAKE_BINARY_DIR and is the root folder for all your binary files. For example, in the project [C-static-library](https://github.com/ttroy50/cmake-examples/tree/master/01-basic/C-static-library), the CMAKE_BINARY_DIR is `C-static-library/build`.
  + CMAKE_CURRENT_BINARY_DIR:
  + MSVC: Set to true when the compiler is some version of Microsoft Visual C++.
  + PROJECT_BINARY_DIR:

+ functions
  + cmake_minimum_required(VERSION 3.5)
  + project(project_name)
  + add_library()
  + [find_package()](https://github.com/suzyi/cpp/blob/master/cmake/basics.md#4---how-does-find_package-work)
  + set(OpenCV_DIR "D:/opencv-4.5.1/opencv/build/x64/vc15/lib"), so that there is a "OpenCVConfig.cmake" under the directory OpenCV_DIR.
  + target_include_directories()
  + target_link_libraries()
  + add_executable()
  + message()
#### CMAKE_PREFIX_PATH
In the libtorch project "print_tensor", we run the command
```
cmake -DCMAKE_PREFIX_PATH=D:\libtorch-win-debug-1.8.1-cpu\libtorch -DCMAKE_BUILD_TYPE=Release "Visual Studio 16 2019 Win64" ..
```
in the terminal. According to [CMAKE_PREFIX_PATH.html](https://cmake.org/cmake/help/v3.0/variable/CMAKE_PREFIX_PATH.html), CMAKE_PREFIX_PATH is a path used for searching by FIND_XXX(), with appropriate suffixes added. To be specific, CMAKE_PREFIX_PATH contains the “base” directories, 
+ the FIND_PROGRAM() adds /bin to each of the directories in the path, 
+ FIND_LIBRARY() appends /lib to each of the directories, 
+ and FIND_PATH() and FIND_FILE() append /include . 
+ By default it is empty, it is intended to be set by the project.
### 4 - how does find_package work?
+ Do what and return what? Finds and loads settings from an external project. \<PackageName\>_FOUND will be set to indicate whether the package was found. When the package is found package-specific information is provided through variables and Imported Targets documented by the package itself.
+ two modes? find_package has two modes by which it searches for packages: "Module" mode and "Config" mode. The above signature selects Module mode. If no module is found the command falls back to Config mode, described below. This fall back is disabled if the MODULE option is given.
    + In Module mode, CMake searches for a file called Find\<PackageName\>.cmake. The file is first searched in the CMAKE_MODULE_PATH, then among the Find Modules provided by the CMake installation. If the file is found, it is read and processed by CMake. It is responsible for finding the package, checking the version, and producing any needed messages.
    + If the MODULE option is not specified in the above signature, CMake first searches for the package using Module mode. Then, if the package is not found, it searches again using Config mode. A user may set the variable CMAKE_FIND_PACKAGE_PREFER_CONFIG to TRUE to direct CMake first search using Config mode before falling back to Module mode.
+ search where? CMake constructs a set of possible installation prefixes for the package. For example, on Windows 10 these entries are used for searching a configuration file (according to [find_package.html](https://cmake.org/cmake/help/latest/command/find_package.html)),
    + \<prefix\>/
    + \<prefix\>/(cmake|CMake)/
    + \<prefix\>/\<name\>*/
    + \<prefix\>/\<name\>*/(cmake|CMake)/

In all above cases, \<prefix\> (namely, package_DIR) can be specified manually in three ways.

Method 1: Add these lines
```
find_package(OpenCV REQUIRED)
message(STATUS "Here is OpenCV_DIR: ${OpenCV_DIR}")
```
to CMakeLists.txt and then use `cmake -DCMAKE_PREFIX_PATH=D:\libtorch-win-debug-1.8.1-cpu\libtorch -DCMAKE_BUILD_TYPE=Release "Visual Studio 16 2019 Win64" ..` in the command line.

Method 2: Add these lines 
```
find_package(OpenCV PATHS "D:/opencv-4.5.1/opencv/build/x64/vc15/lib" NO_DEFAULT_PATH)
message(STATUS "Here is OpenCV_DIR: ${OpenCV_DIR}")
```
to CMakeLists.txt and then use `cmake "Visual Studio 16 2019 Win64" ..` in the command line.

Method 3: Add these lines 
```
set(OpenCV_DIR "D:/opencv-4.5.1/opencv/build/x64/vc15/lib")
find_package(OpenCV REQUIRED)
message(STATUS "Here is OpenCV_DIR: ${OpenCV_DIR}")
```
to CMakeLists.txt and then use `cmake "Visual Studio 16 2019 Win64" ..` in the command line.
### 3 - deploy libtorch on Visual Studio 2019 using cmake
+ [deploy a libtorch project on Visual Studio 2019 using cmake](https://github.com/suzyi/cpp/blob/master/deep-learning/libtorch.md)
+ [deploy a opencv project on Visual Studio 2019 using cmake](https://github.com/suzyi/cpp/blob/master/deep-learning/opencv.md)
### 3 - 1 intro
Generally, three files (one .h header file and two .cpp files) are contained within a c++ project. The .h (Header.h for example) file simply declares needed classes for the project but doesn't constain any further information. Then the specific definitions and operations of those classes are written in one corresponding .cpp (Hello.cpp for example) file. The remaining .cpp-often named as main.cpp, file acts to show you how to call those classes to complete a certain task.

Here you can find a nice [project](https://github.com/ttroy50/cmake-examples/tree/master/01-basic/C-static-library) to demonstrate the relationship among Header.h, Hello.cpp and main.cpp, which is summarized as 
+ Header.h ---> Hello.cpp via target_include_directories, i.e., `target_include_directories(project_name PUBLIC ${PROJECT_SOURCE_DIR}/include)`, where Header.h is placed under the directory "${PROJECT_SOURCE_DIR}/include".
+ Hello.cpp --> .exe via target_link_libraries, i.e., `target_link_libraries(exe_name PRIVATE project_name)`.
+ main.cpp ---> .exe via add_executable, i.e., `add_executable(exe_name src/main.cpp)`.
### the most important three components in a CMakeLists.txt
+ header files, which are in "projectname/include/\*.h"
+ source files, which are in "projectname/src/\*.cpp"
+ executable, which is in "projectname/build/"
