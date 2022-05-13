#include "opencv2/opencv.hpp"
using namespace std;
using namespace cv;
int main()
{
	string path_to_img = "../3_245.bmp";
	Mat img = imread(path_to_img, IMREAD_COLOR);

	if (img.empty())
	{
		cout << "Could not read the image: " << path_to_img << endl;
		return 1;
	}

	int img_h = img.rows;
	int img_w = img.cols;
	cout << img.size << endl;
	imshow("Here is display window for original image", img);
	Mat1b img_gray, img_binary;
	extractChannel(img, img_gray, 0);
	threshold(img_gray, img_binary, 160, 255, 1);
	//cvtColor(img, img_gray, COLOR_BGR2GRAY);

	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;
	findContours(img_binary, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE);

	vector<Rect> boundRect(contours.size());
	Scalar color = Scalar(0, 255, 0);
	int gap = 3;
	for (size_t i = 0; i < contours.size(); i++)
	{
		if (contours[i].size() >= 20) {
			boundRect[i] = boundingRect(contours[i]);
			Point topLeft, bottomRight;
			topLeft.x = boundRect[i].tl().x - gap >= 0 ? boundRect[i].tl().x - gap : 0;
			topLeft.y = boundRect[i].tl().y - gap >= 0 ? boundRect[i].tl().y - gap : 0;
			bottomRight.x = boundRect[i].br().x + gap < img_w ? boundRect[i].br().x + gap : img_w - 1;
			bottomRight.y = boundRect[i].br().y + gap < img_h ? boundRect[i].br().y + gap : img_h - 1;
			//cout << typeid(boundRect[i].tl()).name() << ". The top-left point of rectangle is (" << boundRect[i].tl().x << ", " << boundRect[i].tl().y << ")." << endl;
			//drawContours(img, contours, (int)i, color);
			rectangle(img, topLeft, bottomRight, color, 1); // the last argument controls the width of line.
		}
		
	}
	string path_to_img_bbox = path_to_img.substr(0, path_to_img.find(".bmp")) + "_bbox.png";
	imwrite(path_to_img_bbox, img);
	return 0;
}