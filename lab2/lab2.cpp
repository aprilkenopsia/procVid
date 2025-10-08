#include <opencv2/core/types.hpp>
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
 
using namespace cv;
 

int a ;
int b ;
int arr[2] = {a,b};
int i = 0;

void Add_salt_pepper_Noise(Mat &scr, float pa, float pb )

{    RNG rng; // rand number generator
    int amount1=scr.rows*scr.cols*pa;
    int amount2=scr.rows*scr.cols*pb;
    for(int counter=0; counter<amount1; ++counter)
    {
     scr.at<uchar>(rng.uniform( 0,scr.rows), rng.uniform(0, scr.cols)) =0;

    }
     for (int counter=0; counter<amount2; ++counter)
     {
     scr.at<uchar>(rng.uniform(0,scr.rows), rng.uniform(0,scr.cols)) = 255;
     }
}



int main(int argc, char** argv)
{
    // Parâmetros pa e pb podem ser alterados para maior ou menor quantidade de ruido
    float pa,pb;
    pa = 0.5;
    pb = 0.5;
    bool aplicarFiltro = false;

        if (argc != 2)
    {
        printf("usage: DisplayImage.out <Image_Path>\n");
        return -1;
    }
        
    Mat src;
    src = imread(argv[1], IMREAD_COLOR);
    if (!src.data)
    {
        printf("No image data \n");
        return -1;
    }
 
    printf("Digite o valor de a e b (valores impares): ");
    scanf("%d %d", &arr[0], &arr[1]);

    printf("Aplicar Sal e Pimenta? (1 = Sim, 0 = Não)");
    int filtro;
    scanf("%d", &filtro);
    aplicarFiltro = (filtro == 1);

    if (aplicarFiltro) {
        Add_salt_pepper_Noise(src, pa,pb);
        printf("Sal e pimenta aplicados");
    }

    
    // Blur
    cv::Mat dst1;
    cv::blur(src, dst1, Size(arr[0], arr[1]));
    cv::imwrite("export/blurred.png", dst1);
    printf("Imagem salva em blurred.png\n");
    
    // Gaussian blur
    cv::Mat dst2;
    cv::GaussianBlur(src, dst2, Size(arr[0], arr[1]), 0);
    cv::imwrite("gaussian_blurred.png", dst2);
    printf("Imagem salva como gaussian_blurred.png\n");
    
    // Median blur
    cv::Mat dst3;
    cv::medianBlur(src, dst3, arr[0]);
    cv::imwrite("median_blurred.png", dst3);
    printf("Imagem salva como median_blurred.png\n");
    
    // Bilateral filter
    cv::Mat dst4;
    cv::bilateralFilter(src, dst4, arr[0], arr[1]*2, arr[1]/2);
    cv::imwrite("bilateral_filtered.png", dst4);
    printf("Imagem salva como bilateral_filtered.png\n");
    
    return 0;
}                                 