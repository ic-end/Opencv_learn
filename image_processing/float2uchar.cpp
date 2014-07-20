/**
 *@brief float��ͼ��ת��Ϊuchar��ͼ��,�����������������ת��Ϊuchar��
 *@param[in] float_ima Mat��  CV_32F �� 
 *@param[out]
 *@return    uchar_ima Mat��  CV_8U
 *@pre       �����Mat�����ݱ����ǵ�ͨ��CV_32F�͵�
 *@post      �����Mat�������ǵ�ͨ��CV_8U�͵�
 *@code
   Mat test_ima(100, 100, CV_32F, Scalar(100.0));
   Mat test_ima1(test_ima.rows, test_ima.cols, CV_8U, Scalar(0));
   test_ima1=float2uchar(test_ima);
 *@endcode

 *@since 2013.10.16
 *@author lichao
*/

#include "float2uchar.h"

Mat float2uchar(Mat& float_ima)
{	
	if (float_ima.depth() != 5)
	{
		cout << "��������룬������float��ͼ��" << endl;
		Sleep(2000);
		exit(-1);
	}
	normalize(float_ima, float_ima, 1.0, 0.0, NORM_MINMAX); // float���ݹ�һ��
	float_ima=255*float_ima; // �������ݳ���255

	Mat uchar_ima(float_ima.rows, float_ima.cols, CV_8U, Scalar(0));

	//for (int i=0; i<uchar_ima.rows; i++)
	//{
	//	uchar* data = uchar_ima.ptr<uchar>(i);
	//	float* data1  = float_ima.ptr<float>(i);
	//	for (int j=0; j<float_ima.cols; j++)
	//	{
	//		data[j] = uchar(data1[j]);
	//	}
	//}
	float_ima.convertTo(uchar_ima, CV_8U); // ����������Ĵ���ʵ����ͬ�Ĺ���
	return uchar_ima;
}