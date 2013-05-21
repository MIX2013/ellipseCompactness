#include "myregion.h"
#include<cmath>
#include<iostream>
using namespace std;
Mat myRegion(const Mat& img,int x1,int y1,int threshold)
{

	//�������¿���img
	int M=img.rows;
	int N=img.cols;
	
	//cout<<"M"<<M<<" "<<"N"<<N<<endl;
	//cout<<"x1 is "<<x1<<" "<<"y1 is"<<y1<<endl;
	double seed=img.at<double>(x1,y1);
	//cout<<"seed is"<<seed<<endl;
	Mat Yimage=Mat::zeros(M,N,CV_64FC1);
	Yimage.at<double>(x1,y1)=1;
	double sum=seed;//sum=seed=24
	int suit=1;//��������������������ĵ�ĸ���
	int count=1;//��¼ÿ���ж���Χ8������������µ����


	while(count>0)
	{
		double s=0;	
		count=0;
		for(int i=0;i<M;i++)
		{
			for(int j=0;j<N;j++)
			{
				if(Yimage.at<double>(i,j)==1)
				{

				
					if(i>0&&i<M-1&&j>0&&j<N-1)//�ж��Ƿ��� �Ǳ߽��
					{
						for(int u=-1;u<=1;u++) 
						{
							for(int v=-1;v<=1;v++)
							{
								if(
									Yimage.at<double>(i+u,j+v)==0
									&& abs(img.at<double>(i+u,j+v)-seed)<=threshold
									&& 1.00/(1.00+0.067*abs(img.at<double>(i+u,j+v)-seed ))>0.5  )	
								{
									Yimage.at<double>(i+u,j+v)=1;
									count++;
									s+=img.at<double>(i+u,j+v);
								}
							}
						}
					}
				}
			}
		}
		suit+=count;	
		//cout<<"count is "<<count<<endl;
		sum+=s;
		seed=sum/suit; 
	}
	return Yimage;//matlab��Ҫ��Y��Ϊ�����������ı��ʽ����Ϊmatlabû�з���ֵ
			//�������������=һ��������ʽ��ʱ�����ζ��return 
			//����c++����.
}
