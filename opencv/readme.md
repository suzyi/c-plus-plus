###
+ [0-installation](0-installation.md): install opencv, and deploy it on Visual Studio 2019 and then run a simple example called "bgr2gray".
+ [1-object-detection](1-object-detection): Detect objects on images with pure background.
### cv::Mat
+ `void cv::cvtColor(cv::InputArray src, cv::OutArray dst, int code , int  dstCn=0 );`
+ `std::vector<cv::String> path_to_imgs; cv::glob("img_library/*.jpg", path_to_imgs, true);` true indicates subfolders will be recursively included.
+ `cv::hconcat(img_true, img_recon, img_concat);`
+ `cv::imwrite("result/1.png", img_concat);`
+ `cv::Mat ones = cv::Mat(int rows, int cols, CV_8UC3, cv::Scalar(1, 1, 1));`
+ `cv::Mat img(int rows, int cols, int type);`
  + `img.at<float>(i, j) = 2*CV_PI*rng.uniform(0.0, 1.0);` i-th row, j-th col.
  + `for (int channel=0; channel<3; channel++) img.ptr<float>(i, j)[channel];`
  + `cv::Mat subImg = img(cv::Range(0, 100), cv::Range(0, 100));` `subImage` has the same channels with `img`.
+ `cv::Mat img = cv::imread("data/1.png", -1);`
  + `-1` unchanged, `0` grayscale, `cv::IMREAD_COLOR`
  + `cv_img.create(height, width, CV_8UC(channels));`
  + `cv_img.size()` will print (width, height).
    + `cv_img.size().height`, `cv_img.size().width`
  + `cv_img.channels()`
  + `cv_img.type()`
  + `cv_img.reshape(int cn, int rows)`
    + `cn` specifies channels.
  + `cv_img.t()` transpose.
+ `cv::Mat grid_mat; cv::merge(grid_vec, grid_mat);`
+ `double minVal; double maxVal; cv::minMaxLoc(img_float, &minVal, &maxVal); std::cout << "min val: " << minVal << std::endl;`
+ `cv::Mat(kernel_gradients, cv::Rect(top_left_x, top_left_y, kernel_size.width, kernel_size.height));`
+ `cv::repeat(InputArray src, int ny, int nx, OutputArray dst);`
  + `ny` Flag to specify how many times the `src` is repeated along the vertical axis.
  + `nx` how many times along horizontal axis.
+ `cv::resize(img, img_resized, net_in_height_width);`
  + `cv::Mat img_float; img_resized.convertTo(img_float, CV_32FC3);` or `img_resized.convertTo(img_float, CV_32FC3);`
+ `cv::RNG rng(cv::getTickCount());`
  + `rng.uniform(0.0, 1.0);` generates a float over the interval [0, 1).
  + `rng.uniform(0, 7);` generates an int number over [0, 7).
+ `std::vector<cv::Mat> input_channels; cv::split(img_float, input_channels);`
+ `cv::Size kernel_size(16, 8);`
  + `kernel_size.width` prints 16, `kernel_size.height` prints 8.
+ `int s = cv::sum(img_resized)[0];`
### img.type() - a table to look up

|  | C1 | C2 | C3 | C4 | C(5) | C(6) | C(7) | C(8) |
|--|----|----|----|----|------|------|------|------|
| CV_8U | 0 | 8 | 16 | 24 | 32 | 40 | 48 | 56 |
| CV_8S | 1 | 9 | 17 | 25 | 33 | 41 | 49 | 57 |
| CV_16U | 2 | 10 | 18 | 26 | 34 | 42 | 50 | 58 |
| CV_16S | 3 | 11 | 19 | 27 | 35 | 43 | 51 | 59 |
| CV_32S | 4 | 12 | 20 | 28 | 36 | 44 | 52 | 60 |
| CV_32F | 5 | 13 | 21 | 29 | 37 | 45 | 53 | 61 |
| CV_64F | 6 | 14 | 22 | 30 | 38 | 46 | 54 | 62 |
