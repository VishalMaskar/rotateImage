// Program to Rotate Image in Open CV

#include <opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;

int main()
{
    // Reading an Image
    Mat src = imread("./Images/image.jpg", IMREAD_UNCHANGED);
    int angle;

    // Reading Angle to Rotate
    cout << "Enter Angle to Rotate: ";
    cin >> angle;

    // Autosize Window to Display Image and TrackBar
    string Rotated_Label = "Rotated Image";
    namedWindow(Rotated_Label, WINDOW_AUTOSIZE);

    // // Original image
    //string Original_Label = "Original Image";
    //namedWindow(Original_Label, WINDOW_AUTOSIZE);
    //imshow(Original_Label, src);

    //Trackbar to rotate Image in various Angles
    createTrackbar("Angle", Rotated_Label, &angle, 360);

    //Loop for Trackbar Values
    while(true)
    {
        // get rotation matrix for rotating the image around its center in pixel coordinates
        Point2f center((src.cols - 1) / 2.0, (src.rows - 1) / 2.0);
        Mat rot = getRotationMatrix2D(center, -angle, 1.0);

        // determine bounding rectangle, center not relevant
        Rect2f bbox = RotatedRect(Point2f(), src.size(), -angle).boundingRect2f();

        // adjust transformation matrix
        rot.at<double>(0, 2) += bbox.width / 2.0 - src.cols / 2.0;
        rot.at<double>(1, 2) += bbox.height / 2.0 - src.rows / 2.0;

        Mat dst;
        warpAffine(src, dst, rot, bbox.size());
        imshow(Rotated_Label, dst);

        int keyPressed = waitKey(5);
        // if user press Esc Key
        if (keyPressed == 27)
        {
            break;            
        }
    }
    destroyAllWindows;
    return 0;
}