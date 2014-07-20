/**
 *@brief RGBͼ��ת��Ϊ�Ҷ�ͼ��,GRAY=0.299*R+0.587*G+0.114*B,Mat�а�BGR�洢
 *@param[in] ori_img Mat��  CV_8UC3 ��, RGBͼ
 *@param[out]
 *@return    new_img Mat��  CV_8U
 *@pre       �����Mat�����ݱ�������ͨ��CV_8U�͵�
 *@post      �����Mat�������ǵ�ͨ��CV_8U�͵�
 *@code
   Mat test_img=imread("LenaRGB.bmp");
   Mat test_img1(test_img.rows, test_img.cols, CV_8U, Scalar(0));
   test_img1=rgb2gray(test_img);
 *@endcode

 *@since 2013.10.16
 *@author lichao
*/

// �˺���������imgproc���е�cvtColor�����滻
#include "rgb2gray.h"

Mat rgb2gray(Mat& ori_img)
{
	Mat gray_img(ori_img.rows, ori_img.cols, CV_8U, Scalar(0));
	if (ori_img.channels() != 3)
	{
		cout << "��������룬������RGBͼ��" << endl;
		Sleep(2000);
		exit(-1);
	}
	else
	{
		// cvtColor(ori_img, gray_img, CV_RGB2GRAY);
		for (int i=0; i<ori_img.rows; i++)
		{
			uchar* data = gray_img.ptr<uchar>(i);
			for (int j=0; j<ori_img.cols; j++)
			{
				data[j] = uchar(0.114*ori_img.at<Vec3b>(i,j)[0]
								+0.587*ori_img.at<Vec3b>(i,j)[1]
								+0.299*ori_img.at<Vec3b>(i,j)[2]);
			}
		}
	}
	
	return gray_img;
}