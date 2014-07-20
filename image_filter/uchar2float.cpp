/**
 *@brief uchar��ͼ��ת��Ϊfloat��ͼ��,��֤ͼ��������еľ���
 *@param[in] uchar_img Mat��  CV_8U �� 
 *@param[out]
 *@return    float_img Mat��  CV_32F
 *@pre       �����Mat�����ݱ����ǵ�ͨ��CV_8U�͵�
 *@post      �����Mat�������ǵ�ͨ��CV_32F�͵�
 *@code
   Mat test_img(100, 100, CV_8U, Scalar(0));
   Mat test_img1(test_img.rows, test_img.cols, CV_32F, Scalar(0.0));
   test_img1=uchar2float(test_img);
 *@endcode

 *@since 2013.10.16
 *@author lichao
*/
// �˺���������Mat�е�convertTo�滻

#include "uchar2float.h"

Mat uchar2float(Mat& uchar_img)
{	
	if (uchar_img.depth() != 0)
	{
		cout << "��������룬������uchar��ͼ��" << endl;
		Sleep(2000);
		exit(-1);
	}
	Mat float_img(uchar_img.rows, uchar_img.cols, CV_32F, Scalar(0.0));

	// uchar_img.convertTo(float_img, CV_32F);
	for (int i=0; i<uchar_img.rows; i++)
	{
		uchar* data1 = uchar_img.ptr<uchar>(i); // Դͼ����ָ��
		float* data  = float_img.ptr<float>(i); // ��ͼ����ָ��
		for (int j=0; j<uchar_img.cols; j++)
		{
			data[j] = float(data1[j]);
		}
	}

	return float_img;
}