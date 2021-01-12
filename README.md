# rotateImage

The Repository also contains a detailed Informatioin about Project in PDF form.
Please go through it...

// Rotating an Image

Aim: 
To Rotate the Image at any given Angle

Input: 
Image and Angle to Rotate

Output: 
Rotated Image

Edge Cases: 
1.	If the User Does not give an Image,
	Program will exit with appropriate Message.
Technologies Used: 
Open CV, Visual Studio 2019, C++

How to run the Program:
Installation of Required Software’s:
You can Refer to my YouTube Channel: https://youtu.be/riArxlmRMoQ

Working:
1.	Reading the Image
-	Read in matrix format with data type Mat.

2.	Reading Angle as integer to Rotate the Image.

3.	Create AutoSize Window to Display Image and TrackBar.
-	Using namedWindow(string_name, Type);
-	
4.	Rotating Image using built-in Function.
-	getRotationMatrix2D(Point2f center, angle, Scale);
-	center => takes value to rotate image from a (center)point.
-	Angle => take Anti Clockwise value to rotate Image
-	Scale => Zoom, 1 is Normal, +1 Values Zoom the Image.

5.	Overcoming Problem of Image Cropping while Rotating Image.
-	We will take a Bounding Rectangle and add it to Translated Image
-	To make a bigger box to fit our Image without Cropping in our window.
-	RotatedRect(Point2f(), src.size(), -angle).boundingRect2f();
-	Point2f()
-	This OpenCV function applies affine transformation to an image.
6.	void warpAffine( InputArray src, OutputArray dst, InputArray M, Size dsize )
-	src - Source Image
-	dst - Destination image which should have the same type as the source image(The transformed image is stored in this location)
-	M - 2x3 affine transformation matrix
-	dsize - Size of the destination image

7.	int createTrackbar(string trackbarname, string  winname, int* value, int count, TrackbarCallback onChange = 0, void* userdata = 0).
-	This OpenCV function creates a trackbar and attached that trackbar to a specified window
-	trackbarname - The name of the trackbar
-	winname - The name of the window to which the trackbar is attached
-	value - This integer, pointed by this pointer, holds the value associated with the position of the trackbar
-	count - The maximum value of the trackbar. The minimum value is always zero.
-	onChange - This function will be called everytime the position of the trackbar is changed. The prototype of this function should be "FunctionName(int, void*)". The "int" value is the value associate with the position of the trackbar. And "void*" is any pointer value which you pass as the "userdata" (See the next parameter).
-	userdata - This pointer variable will be passed as the second parameter of the above function

8.	Displaying Image 
-	imshow(string winName,  InputArray() mat).
-	winName is name displayed on window
-	InputArray is image Matrix to be Displayed

9.	Run Program and Enter value to Rotate

10.	Window will be Displayed with Interactive Track Bar that can be used to rotate the Image.

11.	Press “ESC” to exit Program Displaying Image 
-	Number 27 key is for “ESC” button in keyboard so we can set it to exit the Program.

12.	Press “CTRL” + “S”  to save Image on your Storage Device.

