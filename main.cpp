#include <iostream>
#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc )
{
    Mat src, src_gray;//1
    Mat src2;
    Mat grad;
    char* window_name = "Sobel Demo - Simple Edge Detector";
    int scale = 1;
    int delta = 0;
    int ddepth = CV_16S;

    int c;

    /// Load an image
    src = imread( "/home/tm/ClionProject/shapecirclebwlabeled.jpg", 0); // - 0 Серый, ниже 0 безизменений либо такие флаги CV_LOAD_IMAGE_UNCHANGED, CV_LOAD_IMAGE_GRAYSCALE, CV_LOAD_IMAGE_COLOR
    src2 = imread("/home/tm/ClionProjects/tem/shapediamondbwlabeled.jpg", 0); // тоже самое

    Mat res;
    if( !src.data )
    { return -1; }

    imshow("src",src);
    imshow("src2",src2);

    bitwise_and(src(cv::Rect(100,200,src2.cols, src2.rows)),src2,res); //Здесь размеры матриц разные, и мы взяли ROI(Region of interest) в нашем случае RECT с src по размерам src2. x,y точки можещь выбрать сам. В нашем случае f(100,200) охватывает зону лица
    imshow("AND",res);

    bitwise_xor(src(cv::Rect(100,200,src2.cols, src2.rows)),src2,res); //Здесь размеры матриц разные, и мы взяли ROI(Region of interest) в нашем случае RECT с src по размерам src2. x,y точки можещь выбрать сам. В нашем случае f(100,200) охватывает зону лица
    imshow("XOR",res);

    bitwise_or(src(cv::Rect(100,200,src2.cols, src2.rows)),src2,res); //Здесь размеры матриц разные, и мы взяли ROI(Region of interest) в нашем случае RECT с src по размерам src2. x,y точки можещь выбрать сам. В нашем случае f(100,200) охватывает зону лица
    imshow("OR",res);

    waitKey(0);

}