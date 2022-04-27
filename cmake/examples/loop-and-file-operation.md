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