/*
 * OpenCV_ex_13.c
 *
 * MEDIAN FILTER
 *
 * J. Madeira - Dec 2012 + Nov 2017
 */


// Visual Studio ONLY - Allowing for pre-compiled header files

// This has to be the first #include

// Remove it, if you are not using Windows and Visual Studio

// #include "stdafx.h"


#include <iostream>


#include "opencv2/core/core.hpp"

#include "opencv2/imgproc/imgproc.hpp"

#include "opencv2/highgui/highgui.hpp"


// If you want to "simplify" code writing, you might want to use:

// using namespace cv;

// using namespace std;


// AUXILIARY  FUNCTION

void printImageFeatures( const cv::Mat &image )
{
    std::cout << std::endl;

	std::cout << "Number of rows : " << image.size().height << std::endl;

	std::cout << "Number of columns : " << image.size().width << std::endl;

	std::cout << "Number of channels : " << image.channels() << std::endl;

	std::cout << "Number of bytes per pixel : " << image.elemSize() << std::endl;

	std::cout << std::endl;
}


// MAIN

int main( int argc, char** argv )
{
    if( argc != 2 )
    {
		std::cout << "The name of the image file is missing !!" << std::endl;

        return -1;
    }

	cv::Mat originalImage;

	originalImage = cv::imread( argv[1], cv::IMREAD_UNCHANGED );

	if( originalImage.empty() )
	{
		// NOT SUCCESSFUL : the data attribute is empty

		std::cout << "Image file could not be open !!" << std::endl;

	    return -1;
	}

	if( originalImage.channels() > 1 )
	{
	    // Convert to a single-channel, intensity image

		cv::cvtColor( originalImage, originalImage, cv::COLOR_BGR2GRAY, 1 );
	}

    // Create window

	cv::namedWindow( "Original Image", cv::WINDOW_AUTOSIZE );

    // Display image

	cv::imshow( "Original Image", originalImage );

    // Print some image features

	std::cout << "ORIGINAL IMAGE" << std::endl;

    printImageFeatures( originalImage );

    // 3 x 3 Averaging Filter

    cv::Mat medianImage_3x3_1;

	cv::medianBlur( originalImage, medianImage_3x3_1, 3 );

	cv::namedWindow( "Median Filter 3 x 3 - 1 Iter", cv::WINDOW_AUTOSIZE );

	cv::imshow( "Median Filter 3 x 3 - 1 Iter", medianImage_3x3_1 );

	// 5 x 5 Averaging Filter

    cv::Mat medianImage_5x5_1;

	cv::medianBlur( originalImage, medianImage_5x5_1, 5 );

	cv::namedWindow( "Median Filter 5 x 5 - 1 Iter", cv::WINDOW_AUTOSIZE );

	cv::imshow( "Median Filter 5 x 5 - 1 Iter", medianImage_5x5_1 );
	
	// 7 x 7 Averaging Filter

    cv::Mat medianImage_7x7_1;

	cv::medianBlur( originalImage, medianImage_7x7_1, 7 );

	cv::namedWindow( "Median Filter 7 x 7 - 1 Iter", cv::WINDOW_AUTOSIZE );

	cv::imshow( "Median Filter 7 x 7 - 1 Iter", medianImage_7x7_1 );

    // Waiting

	cv::waitKey( 0 );

	// Destroy the windows

	cv::destroyAllWindows();

	return 0;
}
