#include <cstdlib> // system("pause")
#include "glog/logging.h"

int main(int argc, char** argv) {
	LOG(INFO) << "Decoding Datum";
	LOG(INFO) << "Glog works now.";

	system("pause");
	return 0;
}