###
+ [0-installation](0-installation.md): install opencv, and deploy it on Visual Studio 2019 and then run a simple example called "bgr2gray".
+ [1-object-detection](1-object-detection): Detect objects on images with pure background.
### cv::Mat
+ `cv::hconcat(img_true, img_recon, img_concat);`
+ `cv::imwrite("result/1.png", img_concat);`
+ `cv::Mat img = cv::imread("data/1.png", -1);`
  + `-1` unchanged, `0` grayscale.
  + `cv_img.create(height, width, CV_8UC(channels));`
  + `cv_img.size()` will print (width, height).
  + `cv_img.channels()`
  + `cv_img.type()`
+ `double minVal; double maxVal; cv::minMaxLoc(img_float, &minVal, &maxVal); std::cout << "min val: " << minVal << std::endl;`
+ `cv::resize(img, img_resized, net_in_height_width);`
  + `cv::Mat img_float; img_resized.convertTo(img_float, CV_32FC3);` or `img_resized.convertTo(img_float, CV_32FC3);`
+ `std::vector<cv::Mat> input_channels; cv::split(img_float, input_channels);`
+ `cv::Size net_in_height_width;`
+ `int s = cv::sum(img_resized)[0];`