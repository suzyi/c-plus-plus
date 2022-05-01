#include <cstdlib> // system("pause")
#include "glog/logging.h"
#include <gflags/gflags.h>

DEFINE_int32(width, 0, "Width of an image");
DEFINE_int32(height, 0, "Height of an image");

int main(int argc, char** argv) {
	gflags::ParseCommandLineFlags(&argc, &argv, false);
	if (argc < 2) {
		gflags::ShowUsageWithFlagsRestrict(argv[0], "tools_convert_imageset");
		return 1;
	}
	
	LOG(INFO) << "Glog works now.";
	LOG(INFO) << "(img_width, img_height) = (" << FLAGS_width << ", " << FLAGS_height <<")";
	CHECK_EQ(FLAGS_width, FLAGS_height) << "The width is required to equal height";

	system("pause");
	return 0;
}