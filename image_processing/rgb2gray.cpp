/**
 *@brief RGBͼ��ת��Ϊ�Ҷ�ͼ��,GRAY=0.299*R+0.587*G+0.114*B,Mat�а�BGR�洢
 *@param[in] ori_ima Mat��  CV_8UC3 ��, RGBͼ
 *@param[out]
 *@return    new_ima Mat��  CV_8U
 *@pre       �����Mat�����ݱ�������ͨ��CV_8U�͵�
 *@post      �����Mat�������ǵ�ͨ��CV_8U�͵�
 *@code
   Mat test_ima=imread("LenaRGB.bmp");
   Mat test_ima1(test_ima.rows, test_ima.cols, CV_8U, Scalar(0));
   test_ima1=rgb2gray(test_ima);
 *@endcode

 *@since 2013.10.16
 *@author lichao
*/
#include "rgb2gray.h"

Mat rgb2gray(Mat& ori_ima)
{
	Mat gray(ori_ima.rows, ori_ima.cols, CV_8U, Scalar(0));
	if (ori_ima.channels() != 3)
	{
		cout << "��������룬������RGBͼ��" << endl;
		Sleep(2000);
		exit(-1);
	}
	else
	{
		for (int i=0; i<ori_ima.rows; i++)
		{
			uchar* data = gray.ptr<uchar>(i);
			for (int j=0; j<ori_ima.cols; j++)
			{
				data[j] = uchar(0.114*ori_ima.at<Vec3b>(i,j)[0]
								+0.587*ori_ima.at<Vec3b>(i,j)[1]
								+0.299*ori_ima.at<Vec3b>(i,j)[2]);
			}
		}
	}
	return gray;
}