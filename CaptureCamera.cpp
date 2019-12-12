#include "opencv2/opencv.hpp"
using namespace cv;
int main(int argc, char** argv)
{


	cv::VideoCapture cap(0);
	cv::Mat image; cap >> image;
	if (image.empty())
	{
		std::cerr << "Something is wrong with the webcam, could not get frame." << std::endl;
	}
	imwrite("yourSmile.jpg", image); // A JPG FILE IS BEING SAVED

	cv::namedWindow("yourSmile", CV_WINDOW_AUTOSIZE);
	cv::imshow("yourSmile", image);

	cv::waitKey();



	return 0;
}