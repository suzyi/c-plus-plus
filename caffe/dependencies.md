# Dependencies of Caffe
### gflags
`gflags` helps the .exe file receive arguments/parameters from the terminal.

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
