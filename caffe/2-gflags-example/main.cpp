#include <string>
#include <iostream> // cout
#include <cstdlib> // system("pause")
#include <gflags.h>
DEFINE_int32(width, 0, "Width of an image");
DEFINE_int32(height, 0, "Height of an image");
DEFINE_string(type, "", "Optional: What type should we encode the image as ('png','jpg',...).");

int main(int argc, char** argv) {
	gflags::ParseCommandLineFlags(&argc, &argv, false);
	if (argc < 2) {
		gflags::ShowUsageWithFlagsRestrict(argv[0], "tools_convert_imageset");
		return 1;
	}
	std::cout << "img width:" << FLAGS_width << std::endl;
	std::cout << "img height:" << FLAGS_height << std::endl;
	std::cout << "img type:" << FLAGS_type << std::endl;
	system("pause");
	return 0;
}