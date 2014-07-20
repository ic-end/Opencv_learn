/**
 *@brief ��ģ������({{1/8, 1/9, 1/9}, {1/9, 1/9, 1/9}, {1/9, 1/9, 1/9}})
		 �ԻҶ�ͼ����д���, ƽ��������ͨ�˲�
 *@param[in] ori_ima Mat��  CV_8U ��
 *@param[out]
 *@return    new_ima Mat��  CV_8U
 *@pre       �����Mat�����ݱ����ǵ�ͨ��CV_8U�͵�
 *@post      �����Mat�������ǵ�ͨ��CV_8U�͵�
 *@code
   Mat test_ima=imread("Lena.bmp");
   Mat test_ima1(test_ima.rows, test_ima.cols, CV_8U, Scalar(0));
   test_ima1=Blur_ima(test_ima);
 *@endcode

 *@since 2013.10.16
 *@author lichao
*/
#include "Blur_ima.h"

Mat Blur_ima(Mat& ori_ima)
{
	Mat new_ima(ori_ima.rows, ori_ima.cols, CV_8U, Scalar(0));
	Mat float_ima(ori_ima.rows, ori_ima.cols, CV_32F, Scalar(0)); // �м�floatͼ�񣬱�֤����

	float_ima=uchar2float(ori_ima); // uchar��ͼ��ת��Ϊfloat��ͼ��
	for (int i=1; i<ori_ima.rows-1; i++)
	{
		float* data  = float_ima.ptr<float>(i);
		uchar* data0 = ori_ima.ptr<uchar>(i-1);
		uchar* data1 = ori_ima.ptr<uchar>(i);
		uchar* data2 = ori_ima.ptr<uchar>(i+1);
		for (int j=1; j<ori_ima.cols; j++)
		{
			data[j] = (data0[j-1] + data0[j] + data0[j+1] + data1[j-1] + 
				       data1[j] + data1[j+1] + data2[j-1] + data2[j] + data2[j+1])/9;
		}
	}
	new_ima=float2uchar(float_ima); // float��ͼ��ת��Ϊuchar��ͼ��
	return new_ima;
}