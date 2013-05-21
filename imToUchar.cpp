#include"imToUchar.h"

const Mat& imToUchar(const Mat& src,Mat& dst ) 
{
	int rows=src.rows;
	int cols=src.cols;
	for(int i=0;i<rows;i++)
		for(int j=0;j<cols;j++)
		{
			dst.at<uchar>(i,j)=(uchar)src.at<double>(i,j)*255;
		}
	return  dst;








}
