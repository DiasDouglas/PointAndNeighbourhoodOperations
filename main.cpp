#include "main.h"
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace cv;

int threshValue = 120, threshType = 0, adaptThreshType = 0, morphOpValue = 0;
Mat image = imread("LennaGrayScale.png", CV_8UC1);

void onThreshValueChange(int, void*)
{
	Mat newImage;
	threshold(image, newImage, threshValue, 255, threshType);
	imshow("Threshold Test", newImage);
}

void onAdaptThreshValueChange(int, void*)
{
	Mat newImage;
	adaptiveThreshold(image, newImage, 255, adaptThreshType, threshType, 11, 12);
	imshow("Adaptive Threshold Test", newImage);
}

void onMorphOpValueChange(int, void*)
{
	Mat newImage;
	morphologyEx(image, newImage, morphOpValue, Mat());
	imshow("MorphologyEx Test", newImage);
}

void defaultThreshold() {
	namedWindow("Threshold Test");
	createTrackbar("Type", "Threshold Test", &threshType, 7, onThreshValueChange);
	createTrackbar("Threshold", "Threshold Test", &threshValue, 255, onThreshValueChange);

	onThreshValueChange(0, 0);

	while (true) {
		if (waitKey(1) == 27) {
			break;
		}
	}
}

void adaptiveThreshold() 
{
	namedWindow("Adaptive Threshold Test");
	createTrackbar("Adapt Type", "Adaptive Threshold Test", &adaptThreshType, 1, onAdaptThreshValueChange);
	createTrackbar("Thresh Type", "Adaptive Threshold Test", &threshType, 1, onAdaptThreshValueChange);
	
	onAdaptThreshValueChange(0, 0);

	while (true) {
		if (waitKey(1) == 27) {
			break;
		}
	}
}

void equalizeHistogram()
{
	Mat output;

	equalizeHist(image, output);

	imshow("Default Image", image);
	imshow("Histogram Equalized Image", output);

	waitKey();
}

void defaultBlurring()
{
	Mat output;

	blur(image, output, Size(5,5));

	imshow("Default Image", image);
	imshow("Blurred Image", output);

	waitKey();
}

void gaussianBlurring()
{
	Mat output;

	GaussianBlur(image, output, Size(5, 5), 2);

	imshow("Default Image", image);
	imshow("Gaussian Blurred Image", output);

	waitKey();
}

void medianBlurring()
{
	Mat output;

	medianBlur(image, output, 7);

	imshow("Default Image", image);
	imshow("Median Blurred Image", output);

	waitKey();
}

void sobelFiltering()
{
	Mat output;

	Sobel(image, output, CV_16S, 1, 0);
	convertScaleAbs(output, output);

	imshow("Default Image", image);
	imshow("Sobel Filtered Image #1", output);

	Sobel(image, output, CV_16S, 0, 1);
	convertScaleAbs(output, output);

	imshow("Sobel Filtered Image #2", output);

	waitKey();
}

void laplaceFiltering()
{
	Mat output;

	Laplacian(image, output, CV_16S, 1);
	convertScaleAbs(output, output);

	imshow("Default Image", image);
	imshow("Laplace Filtered Image", output);

	waitKey();
}

void dilateExample()
{
	Mat output;

	dilate(image, output, Mat());
	convertScaleAbs(output, output);

	imshow("Default Image", image);
	imshow("Dilated Image", output);

	waitKey();
}

void erodeExample()
{
	Mat output;

	erode(image, output, Mat());
	convertScaleAbs(output, output);

	imshow("Default Image", image);
	imshow("Eroded Image", output);

	waitKey();
}

void morphologyExExample()
{
	Mat output;

	namedWindow("MorphologyEx Test");
	createTrackbar("Operation", "MorphologyEx Test", &morphOpValue, 7, onMorphOpValueChange);

	onMorphOpValueChange(0, 0);

	waitKey();
}

int main() 
{
	//defaultThreshold();
	//adaptiveThreshold();
	//equalizeHistogram();
	//defaultBlurring();
	//gaussianBlurring();
	//medianBlurring();
	//sobelFiltering();
	//laplaceFiltering();
	//dilateExample();
	//erodeExample();
	//morphologyExExample();
}