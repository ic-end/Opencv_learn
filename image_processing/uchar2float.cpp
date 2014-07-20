/**
 *@brief uchar��ͼ��ת��Ϊfloat��ͼ��,��֤ͼ��������еľ���
 *@param[in] uchar_ima Mat��  CV_8U �� 
 *@param[out]
 *@return    float_ima Mat��  CV_32F
 *@pre       �����Mat�����ݱ����ǵ�ͨ��CV_8U�͵�
 *@post      �����Mat�������ǵ�ͨ��CV_32F�͵�
 *@code
   Mat test_ima(100, 100, CV_8U, Scalar(0));
   Mat test_ima1(test_ima.rows, test_ima.cols, CV_32F, Scalar(0.0));
   test_ima1=uchar2float(test_ima);
 *@endcode

 *@since 2013.10.16
 *@author lichao
*/

#include "uchar2float.h"

Mat uchar2float(Mat& uchar_ima)
{	
	if (uchar_ima.depth() != 0)
	{
		cout << "��������룬������uchar��ͼ��" << endl;
		Sleep(2000);
		exit(-1);
	}
	Mat float_ima(uchar_ima.rows, uchar_ima.cols, CV_32F, Scalar(0.0));

	//for (int i=0; i<uchar_ima.rows; i++)
	//{
	//	uchar* data1 = uchar_ima.ptr<uchar>(i); // Դͼ����ָ��
	//	float* data  = float_ima.ptr<float>(i); // ��ͼ����ָ��
	//	for (int j=0; j<uchar_ima.cols; j++)
	//	{
	//		data[j] = float(data1[j]);
	//	}
	//}

	uchar_ima.convertTo(float_ima, CV_32F);

	return float_ima;
}