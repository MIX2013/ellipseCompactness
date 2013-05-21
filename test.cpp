#include<opencv2/opencv.hpp>
#include "myregion.h"
#include "imToDouble.h"
#include<iostream>
using namespace std;
using namespace cv;
int main()
{
	Mat img=imread("D:/denoised_image3.jpg",0);
	Mat dst;
	dst.create(img.rows,img.cols,CV_64FC1);
	imToDouble(img,dst);//变成双精度,便于计算
	img=dst;
	imshow("原图变成双精度后",img);
	int x1=img.rows/2;
	int y1=img.cols/2;

	Mat result =myRegion(img,x1,y1,25);
	imshow("region",result);
	Mat fillHole=result.clone();		
	
	





















	waitKey(0);	
	return 0;
}