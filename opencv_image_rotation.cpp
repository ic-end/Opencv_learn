#include <opencv2\highgui\highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void decide_bound(double in,double low,double high)
{
	if((in<low)||(in>high))
	{
		cout<<"����ĽǶȳ�����Χ��"<<endl;
		_sleep(2000);
		exit(0);
	}
}

int main()
{
	float angle=0;
	float angle_r=0;
	float max,min;
	int new_R=0,new_C=0; //�µ��к���
	int Ri,Rj;

	//����ԭʼͼ����ʾ
	Mat ori_ima;//ԭʼͼ��	
	ori_ima=imread("D:\\Document\\vidpic\\pictures\\LenaRGB.bmp");

	//������ת�Ƕ�
	cout<<"��������ת�Ƕ�(-90,90��,���س�����:"<<endl;
	cin>>angle;
	decide_bound(angle,-90,90);

	angle_r=angle/180*CV_PI;

	//�任����
	float t[2][2]={cos(angle_r),-sin(angle_r),sin(angle_r),cos(angle_r)};
	Mat T=Mat(2,2,CV_32F,t);//�任����

	//������ͼ��Ĵ�С
	float rw_[4][2]={{1,1},{1,ori_ima.cols},{ori_ima.rows,1},{ori_ima.rows,ori_ima.cols}};
	Mat rw=Mat(4,2,CV_32F,rw_);//
	Mat RW(4,2,CV_32F);//
	RW=rw*T;
	Mat maxm,minm;
	reduce(RW,maxm,0,CV_REDUCE_MAX,-1);//ÿһ�е����ֵ
	reduce(RW,minm,0,CV_REDUCE_MIN,-1);//ÿһ�е����ֵ
	Mat new_RW=maxm-minm;
	new_R=ceil(new_RW.at<float>(0,0));//�µ�����
	new_C=ceil(new_RW.at<float>(0,1));//�µ�����

	
	Mat new_ima(new_R,new_C,CV_8UC3,Scalar(0,0,0));//��ת���ͼ��

	Mat RIJ=Mat(1,2,CV_32F,Scalar(0)),RIJ_=Mat(1,2,CV_32F,Scalar(0));
	int ri,rj;

	for(int i=0;i<new_R;i++)
	{
		for(int j=0;j<new_C;j++)
		{

			RIJ.at<float>(0,0)=i-1;
			RIJ.at<float>(0,1)=j-1;
			RIJ=(RIJ+minm)*T.inv();
			ri=ceil(RIJ.at<float>(0,0));//��ԭʼͼ������
			rj=ceil(RIJ.at<float>(0,1));//��ԭʼͼ������

			if((ri>=0)&&(rj>=0)&&(ri<ori_ima.rows)&&(rj<ori_ima.cols))
			{
				new_ima.at<Vec3b>(i,j)[0]=ori_ima.at<Vec3b>(ri,rj)[0];
				new_ima.at<Vec3b>(i,j)[1]=ori_ima.at<Vec3b>(ri,rj)[1];
				new_ima.at<Vec3b>(i,j)[2]=ori_ima.at<Vec3b>(ri,rj)[2];
			}
		}
	}
	
	namedWindow("ԭʼͼ��");
	imshow("ԭʼͼ��",ori_ima);
	namedWindow("��ת���ͼ��");
	imshow("��ת���ͼ��",new_ima);
	
	waitKey(0);
}