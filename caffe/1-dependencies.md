# Dependencies of Caffe
### functions
+ `caffe_default_properties(convert_imageset)`, `caffe_default_properties(compute_image_mean)`
    + `caffe_default_properties` is defined in cmake/Targets.cmake.
### gflags
`gflags` helps the .exe file receive arguments/parameters from the Terminal.

```
libraries_v140_x64_py27_1.1.0\libraries\lib
|-gflags.dll # for release mode
|-gflags.lib # for release mode
|-gflagsd.dll # for debug mode
|-gflagsd.lib # for debug mode

libraries_v140_x64_py27_1.1.0\libraries\cmake
|-gflags-config.cmake
|-gflags-config-version.cmake
|-gflags-targets.cmake
|-gflags-targets-debug.cmake
|-gflags-targets-release.cmake
```
+ [gflags-example](2-gflags-example)
    + How to build this project? Open an anaconda prompt and navigate to the project folder. Firstly, `mkdir build && cd build`. Secondly, `cmake -A x64 ..`. And finally `cmake --build . --config Debug`.
    + When building is done, try `Debug\hello_exe.exe --width=23 --height=23 --type="png"`.
+ `#include <gflags/gflags.h>`
+ `DEFINE_bool(gray, false, "When this option is on, treat images as grayscale ones");`
+ `DEFINE_int32(resize_width, 0, "Width images are resized to");`
+ `DEFINE_string(encode_type, "", "Optional: What type should we encode the image as ('png','jpg',...).");`
+ In main function, use `google::ParseCommandLineFlags(&argc, &argv, true)`. If `true`, only `argv[0]` left and `argc=1`, else both will not be changed.
+ Now, these arguments are be accessed via `FLAGS_VarName`, `const bool is_color = !FLAGS_gray; const bool check_size = FLAGS_check_size;` for example.
+ In the terminal, use `my.exe --var1="test" --var2=3.1415`, or `build\tools\Release\convert_imageset.exe data\re\ data\re\trainlist.txt data\re\img_train_lmdb` for example.
### glog
glog is short for google logging that implements application-level logging.
+ `#include <glog/logging.h>`
+ `int main(int argc, char* argv[]) { google::InitGoogleLogging(argv[0]); LOG(INFO) << "Found " << num_cookies << " cookies";}`