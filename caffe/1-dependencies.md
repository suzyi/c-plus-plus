# Dependencies of Caffe
+ [2-gflags_glog_example](2-gflags_glog_example)
    + `mkdir build && cd build`, `cmake -A x64 ..`, `cmake --build . --config Debug`.
    + Try `Debug\gflags_glog_exe.exe --width=32 --height=32` and `Debug\gflags_glog_exe.exe --width=128 --height=64`.
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

libraries_v140_x64_py27_1.1.0\libraries\include
|-gflags\
    |-gflags.h
    |-gflags_completions.h
    |-gflags_declare.h
    |-gflags_gflags.h
libraries_v140_x64_py27_1.1.0\libraries\cmake
|-gflags-config.cmake
|-gflags-config-version.cmake
|-gflags-targets.cmake
|-gflags-targets-debug.cmake
|-gflags-targets-release.cmake
```

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
+ `LOG(INFO) << "Glog works now";`
+ `CHECK_EQ`, `CHECK_NE`, `CHECK_LE`, `CHECK_LT`, `CHECK_GE`, `CHECK_GT`
    + `CHECK_EQ(data.size(), data_size) << "Incorrect data field size " << data.size();`