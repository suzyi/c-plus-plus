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
Nearly all non-trivial projects will have a requirement for including third party libraries, headers, or programs. CMake has support for finding the path to these tools using the find_package() function. This will search for CMake modules in the format "FindXXX.cmake" from the list of folders in CMAKE_MODULE_PATH. On linux the default search path will include /usr/share/cmake/Modules. On my system this includes support for approximately 142 common third party libraries.
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
