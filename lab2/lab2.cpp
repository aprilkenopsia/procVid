#include <opencv2/core/types.hpp>
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
 
using namespace cv;
 

int a ;
int b ;
int arr[2] = {a,b};
int i = 0;



int main(int argc, char** argv )
{
    printf("Digite o valor de a e b (valores impares): ");
    scanf("%d %d", &arr[0], &arr[1]);

    if ( argc != 2 )
    {
        printf("usage: DisplayImage.out <Image_Path>\n");
        return -1;
    }
 while (i < 4) {
    Mat src;
    src = imread( argv[1], IMREAD_COLOR );
    if ( !src.data )
    {
        printf("No image data \n");
        return -1;
    }
    if (i == 0) {
        cv::Mat dst;
        cv::blur(src, dst, Size(arr[0], arr[1]));
        cv::imwrite("blurred.png", dst);
        printf("Imagem salva como blurred.png\n");
        i++;
    }
    else if (i == 1) {
        cv::Mat dst;
        cv::GaussianBlur(src, dst, Size(arr[0], arr[1]), 0);
        cv::imwrite("gaussian_blurred.png", dst);
        printf("Imagem salva como gaussian_blurred.png\n");
        i++;
    }
    if (i == 2) {
        cv::Mat dst;
        cv::medianBlur(src, dst, 3);
        cv::imwrite("median_blurred.png", dst);
        printf("Imagem salva como median_blurred.png\n");
        i++;
    }
    if (i == 3) {
        cv::Mat dst;
        cv::bilateralFilter(src, dst, arr[0], arr[1]*2 , arr[1]/2);
        cv::imwrite("bilateral_filtered.png", dst);
        printf("Imagem salva como bilateral_filtered.png\n");
    }
    // cv::putText(dst, "imagem salva para blurred.png", cv::Point(20,50), cv::FONT_HERSHEY_COMPLEX, 0., cv::Scalar(255,255,255), 2);
    // namedWindow("Display Image", WINDOW_AUTOSIZE );
    // imshow("Display Image", dst);
    return 0;

 }
}                                                 