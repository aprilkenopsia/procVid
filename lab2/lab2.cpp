#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
 
using namespace cv;
 
int main(int argc, char** argv )
{
    if ( argc != 2 )
    {
        printf("usage: DisplayImage.out <Image_Path>\n");
        return -1;
    }
 
    Mat src;
    src = imread( argv[1], IMREAD_COLOR );
    if ( !src.data )
    {
        printf("No image data \n");
        return -1;
    }
    cv::Mat dst;
    cv::blur(src, dst, Size(6,6));
    namedWindow("Display Image", WINDOW_AUTOSIZE );
    imshow("Display Image", dst);
 
    waitKey(0);
 
    return 0;
}