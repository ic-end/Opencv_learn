/**
 *@brief float��ͼ��ת��Ϊuchar��ͼ��,�����������������ת��Ϊuchar��
 *@param[in] float_img Mat��  CV_32F �� 
 *@param[out]
 *@return    uchar_img Mat��  CV_8U
 *@pre       �����Mat�����ݱ����ǵ�ͨ��CV_32F�͵�
 *@post      �����Mat�������ǵ�ͨ��CV_8U�͵�
 *@code
   Mat test_img(100, 100, CV_32F, Scalar(100.0));
   Mat test_img1(test_img.rows, test_img.cols, CV_8U, Scalar(0));
   test_img1=float2uchar(test_img);
 *@endcode

 *@since 2013.10.16
 *@author lichao
*/
// �˺���������Mat�е�convertTo�滻

#include "float2uchar.h"

Mat float2uchar(Mat& float_img)
{	
	if (float_img.depth() != 5)
	{
		cout << "��������룬������float��ͼ��" << endl;
		Sleep(2000);
		exit(-1);
	}
	normalize(float_img, float_img, 1.0, 0.0, NORM_MINMAX); // float���ݹ�һ��
	float_img=255*float_img; // �������ݳ���255

	Mat uchar_img(float_img.rows, float_img.cols, CV_8U, Scalar(0));

	// float_img.convertTo(uchar_img, CV_8U); 
	for (int i=0; i<uchar_img.rows; i++)
	{
		uchar* data = uchar_img.ptr<uchar>(i);
		float* data1  = float_img.ptr<float>(i);
		for (int j=0; j<float_img.cols; j++)
		{
			data[j] = uchar(data1[j]);
		}
	}

	return uchar_img;
}