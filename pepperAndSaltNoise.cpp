#include <iostream>
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
using namespace std;
using namespace cv;
void Pepper_And_Salt(cv::Mat& image, int n) {
	int i, j , k , l;
	for (int m = 0; m < n; m++) {
		// rand() is the MFC random number generator
		i = rand() % image.cols;
		j = rand() % image.rows;
		k = rand() % image.cols;
		l = rand() % image.rows;

		if (image.channels() == 1) { // gray-level image
			image.at<uchar>(j, i) = 255;
			image.at<uchar>(l, k) = 0;
		}
		else if (image.channels() == 3) { // color image
			image.at<cv::Vec3b>(j, i)[0] = 255;
			image.at<cv::Vec3b>(j, i)[1] = 255;
			image.at<cv::Vec3b>(j, i)[2] = 255;
			image.at<cv::Vec3b>(l, k)[0] = 0;
			image.at<cv::Vec3b>(l, k)[1] = 0;
			image.at<cv::Vec3b>(l, k)[2] = 0;

		}
	}



}
int main(int, char**) {


	// Capture the Image from the webcam
	cv::VideoCapture cap(0);

	// Get the frame
	cv::Mat image; cap >> image;

	if (image.empty())
	{
		std::cerr << "Something is wrong with the webcam, could not get frame." << std::endl;
	}
	// Save the frame into a file
	imwrite("me.jpg", image); // A JPG FILE IS BEING SAVED


	Pepper_And_Salt(image, 1000);
	cv::namedWindow("Salt & Pepper", CV_WINDOW_AUTOSIZE);
	cv::imshow("Salt & Pepper", image);
	cv::imwrite("salted.bmp", image);
	cv::waitKey();
	return 0;
}