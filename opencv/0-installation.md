# opencv
### 1 - install opencv on windows
The official installation on Windows 10 can be found in [tutorial_windows_install](https://docs.opencv.org/master/d3/d52/tutorial_windows_install.html#tutorial_windows_install_prebuilt), which can be summarized as
+ Firstly, download the "opencv-for-windows.exe" from [the downloading page](https://sourceforge.net/projects/opencvlibrary/files/opencv-win/).
+ Secondly, click the downloaded "opencv-for-windows.exe" and install it to a proper directory (actually, the installation is just an uncompressing process).
+ Finally, run a toy example using opencv to check if it works fine, following these steps.
### 2 - run a toy opencv example, with the helpf of CMakeLists.txt
Before all, we have to declare that this toy example is run on such a platform
+ OS is Windows 10,
+ cmake,
+ language is C++ written in Visual Studio 2019.

With the computer requirements above, we can create a toy example of converting a BGR image to a gray image, by following these steps.

Firstly, create an empty folder called "bgr2gray" and then add two files () and another empty folder (called build) to "bgr2gray". So it looks like
```
bgr2gray
|--CMakeLists.txt
|--main.cpp
```
CMakeLists.txt stores all needed CMake comments, i.e.,
```
cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
project(bgr2gray)

find_package(OpenCV PATHS "D:/opencv-4.5.1/opencv/build/x64/vc15/lib" NO_DEFAULT_PATH) # the directory is set to OpenCV_DIR, under which you can find "OpenCVConfig.cmake".
if(NOT OpenCV_FOUND)
	message(FATAL_ERROR "OpenCV not found.")
endif(NOT Torch_FOUND)

message(STATUS "Here is OpenCV_DIR: ${OpenCV_DIR}")
message(STATUS "Here is the libraries info of OpenCV: ${OpenCV_LIBRARIES}")

add_executable(bgr2gray main.cpp)
target_link_libraries(bgr2gray ${OpenCV_LIBRARIES})
set_property(TARGET bgr2gray PROPERTY CXX_STANDARD 11)
```
The cpp file "main.cpp" contains
```
#include "opencv2/opencv.hpp"
using namespace std;
using namespace cv;
int main()
{
	string image_path = "../wechatIcon.png";
	Mat img = imread(image_path, IMREAD_COLOR);

	if (img.empty())
	{
		cout << "Could not read the image: " << image_path << endl;
		return 1;
	}

	cout << img.size << endl;
	imshow("Here is display window for original image", img);
	cvtColor(img, img, COLOR_BGR2GRAY);
	imshow("Here is display window for gray image", img);
	waitKey();
	return 0;
}
```

Secondly, open your "powershell" or "cmd" and then navigate to the directory "bgr2gray/build/". Enter the command line 
```
cmake "Visual Studio 16 2019 Win64" ..
```
which will then returns you some messages like
```
-- Building for: Visual Studio 16 2019
-- Selecting Windows SDK version 10.0.18362.0 to target Windows 10.0.18363.
-- The C compiler identification is MSVC 19.26.28806.0
-- The CXX compiler identification is MSVC 19.26.28806.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: D:/Microsoft Visual Studio/2019/Community/VC/Tools/MSVC/14.26.28801/bin/Hostx64/x64/cl.exe - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: D:/Microsoft Visual Studio/2019/Community/VC/Tools/MSVC/14.26.28801/bin/Hostx64/x64/cl.exe - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Found OpenCV: D:/opencv-4.5.1/opencv/build (found version "4.5.1")
CMake Warning (dev) in CMakeLists.txt:
  A logical block opening on the line

    F:/cpp20200707/opencv20210401/helloworld20210401/CMakeLists.txt:6 (if)

  closes on the line

    F:/cpp20200707/opencv20210401/helloworld20210401/CMakeLists.txt:8 (endif)

  with mis-matching arguments.
This warning is for project developers.  Use -Wno-dev to suppress it.

-- Here is OpenCV_DIR: D:/opencv-4.5.1/opencv/build/x64/vc15/lib
-- Here is the libraries info of OpenCV: opencv_calib3d;opencv_core;opencv_dnn;opencv_features2d;opencv_flann;opencv_gapi;opencv_highgui;opencv_imgcodecs;opencv_imgproc;opencv_ml;opencv_objdetect;opencv_photo;opencv_stitching;opencv_video;opencv_videoio;opencv_world
-- Configuring done
-- Generating done
-- Build files have been written to: F:/cpp20200707/opencv20210401/helloworld20210401/build
```
if no error reported.

Thirdly, open the file "bgr2gray/build/rgb2gray.vcxproj" using Visual Studio 2019 (VS 2019 for short) and in the VS 2019 interface, 
+ set the mode to "Debug", "x64",
+ right click "bgr2gray" and left click "Set as Startup Project",
+ left click "Local Windows Debugger",
then you may suffer from an error "opencv_world451d.dll is missing" or "can't find opencv_world451d.dll". To fix this, just copy "D:\opencv-4.5.1\opencv\build\x64\vc15\bin\opencv_world451d.dll" to the folder "bgr2gray\build\Debug\".

Finally, click the "bgr2gray\build\Debug\rgb2gray.exe" and you will see a color image and a gray image.

### 3 - run a toy opencv example, without the helpf of CMakeLists.txt
Configure a VS2017 project without using CMakeLists.txt.

+ Configuration Properties
	+ C/C++
		+ General
			+ Additional Include Directories: `D:\opencv-4.5.1\opencv\build\include;` under which header files are found.
	+ Linker
		+ General
			+ Additional Library Directories: `D:\opencv-4.5.1\opencv\build\x64\vc15\lib;` under which .lib files are found.
		+ Input
			+ Additional Dependencies:
				+ `opencv_world451.lib;` for Release version.
				+ `opencv_world451d.lib;` for Debug version.
