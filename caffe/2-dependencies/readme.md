# Dependencies of Caffe
+ [2-1-gflags_glog_example](2-1-gflags_glog_example)
    + `rum.cmd`
### functions
+ `caffe_default_properties` is defined in cmake/Targets.cmake.
    + `caffe_default_properties(convert_imageset)`, `caffe_default_properties(compute_image_mean)`
+ `caffe_option()` is defined in cmake/Utils.cmake.
    + `caffe_option(CPU_ONLY  "Build Caffe without CUDA support" OFF)`
+ `caffe_set_caffe_link()` is defined in cmake/Targets.cmake.
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
+ LOG()
    + `LOG(INFO) << "Glog works now";`
    + `LOG(FATAL) << "This tool requires OpenCV.";`
+ `CHECK`, `CHECK_EQ`, `CHECK_NE`, `CHECK_LE`, `CHECK_LT`, `CHECK_GE`, `CHECK_GT`. They will break if `false`.
    + `cv::Mat img = cv::imread(file, -1); CHECK(!img.empty()) << "Unable to decode image " << file;`
    + `CHECK_EQ(data.size(), data_size) << "Incorrect data field size " << data.size();`
### boost
+ `#include "boost/scoped_ptr.hpp"`
### caffe/util/db.hpp
`db.hpp` contains a scope named `db`, defined as 
```
namespace db {
    class Cursor {};
    class Transaction {};
    class DB {};
    DB* GetDB(DataParameter::DB backend);
    DB* GetDB(const string& backend);
}
```
There, `db::Cursor` is used to specify a class within it.

+ `#include "caffe/util/db.hpp"`
+ `scoped_ptr<db::DB> db_file(db::GetDB("lmdb"));` create a new db.
+ `db_file->Open("data/mnist/img_lmdb", db::NEW)`, or `db_file->Open("data/mnist/img_lmdb", db::READ);`
+ `scoped_ptr<db::Transaction> txn(db->NewTransaction());`, txn is short for transaction.
    + `txn->Put(key_str, out);`
    + `txn->Commit();`
    + `txn.reset(db->NewTransaction());`
+ `scoped_ptr<db::Cursor> cursor(db->NewCursor());`
    + `datum.ParseFromString(cursor->value());`
    + `cursor->key();`
    + `while (cursor->valid()) {...; cursor->Next();}`
### "caffe/proto/caffe.pb.h"
+ `#include "caffe/proto/caffe.pb.h"`
+ `Datum datum;`
+ `data_size = datum.channels() * datum.height() * datum.width();`
+ `string out; datum.SerializeToString(&out);`