#include "imToDouble.h"
#include<iostream>
using namespace std;
void imToDouble(const Mat& src,Mat& dst)
{
	int rows=src.rows;
	int cols=src.cols;
	for(int i=0;i<rows;i++)
	{	
		for(int j=0;j<cols;j++)
		{
			dst.at<double>(i,j)=(double)src.at<uchar>(i,j);
		}
	}

}