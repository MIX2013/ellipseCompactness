#ifndef  MYREGION_H
#define  MYREGION_H

#include<opencv2/opencv.hpp>
using namespace cv;
Mat myRegion(const Mat& img,int x1,int y1,int threshold);
#endif