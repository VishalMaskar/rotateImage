#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	Mat img = imread("./images/image.jpg");
	if (img.empty())
	{
		cout << "error !!! no image...";
		return -1;
	}
	namedWindow("image", WINDOW_AUTOSIZE);
	imshow("image", img);
	Mat img1 = imread("./images/image.jpg", IMREAD_UNCHANGED);
	imshow("grayscale", img1);
	waitKey();
return 0;
}
