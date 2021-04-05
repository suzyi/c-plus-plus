# basics
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
#### set
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
### 3 - some other keywords
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

In all above cases, \<prefix\> can be specified manually in the command line by the variable "CMAKE_PREFIX_PATH", "cmake -DCMAKE_PREFIX_PATH=D:\libtorch-win-debug-1.8.1-cpu\libtorch -DCMAKE_BUILD_TYPE=Release "Visual Studio 16 2019 Win64" .." for searching libtorch, for example.

In practice, one can specify package_DIR for the function find_package by, for exampel,
```
find_package(OpenCV PATHS "D:/opencv-4.5.1/opencv/build/x64/vc15/lib" NO_DEFAULT_PATH)
message(STATUS "config: ${OpenCV_DIR}") # OpenCV_DIR=D:/opencv-4.5.1/opencv/build/x64/vc15/lib
```
where "D:/opencv-4.5.1/opencv/build/x64/vc15/lib" is determined manually by checking if there is a file called "OpenCVConfig" within it. Likewise, use 
```
find_package (Torch PATHS "D:/libtorch-win-debug-1.8.1-cpu/libtorch" NO_DEFAULT_PATH)
message(STATUS "config: ${Torch_DIR}") # Torch_DIR=D:/libtorch-win-debug-1.8.1-cpu/libtorch/share/cmake/Torch
```
for deploying Libtorch on Visual Studio 2019 because "TorchConfig.cmake" is under "D:\libtorch-win-debug-1.8.1-cpu\libtorch\share\cmake\Torch".
