// Rotate Image
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include<iostream>

using namespace cv;
using namespace std;

int main()
{
    cout << "Press 'ESC' to Exit" << endl << endl;
    int iAngle;
    cout << "Enter Angle to Rotate: ";
    cin >> iAngle;
    waitKey();

    // Load the image
    Mat imgOriginal = imread("./Images/image.jpg", IMREAD_UNCHANGED);

    Size s = imgOriginal.size();

    //show the original image
    String Original_Label = "Original Image";
    namedWindow(Original_Label, WINDOW_AUTOSIZE);
    imshow(Original_Label, imgOriginal);

    String Rotated_Label = "Rotated Image";
    namedWindow(Rotated_Label, WINDOW_AUTOSIZE);


    createTrackbar("Angle", Rotated_Label, &iAngle, 360);

    // Center Point to Rotate...
    int iImageHeight = imgOriginal.rows / 2;
    int iImageWidth = imgOriginal.cols / 2;

    while (true)
    {
        Mat matRotation = getRotationMatrix2D(Point(iImageWidth, iImageHeight), (-iAngle), 1);
        // (-iAngle) negative value to Rotate Image Clockwise, positive value for counter-clockwise rotation.
        // scale = 1 is original image, increment value to zoom in.

        // Rotate the image
        Mat imgRotated;
        warpAffine(imgOriginal, imgRotated, matRotation, s); //s=imgOriginal.size()

        imshow(Rotated_Label, imgRotated);

        int iRet = waitKey(5);
        // if user press Esc Key
        if (iRet == 27)
        {
            break;
        }
    }
    destroyAllWindows();
    return 0;
}

