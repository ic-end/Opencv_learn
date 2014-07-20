/**
 *@brief �ԻҶ�ͼ����д���,type��Ӧ��ͬ������
 *@param[in] ori_ima Mat��  CV_8U ��; type=0,1,2,3,4,5,6;
 *@param[out]
 *@return    new_ima Mat��  CV_8U
 *@pre       �����Mat�����ݱ����ǵ�ͨ��CV_8U�͵�
 *@post      �����Mat�������ǵ�ͨ��CV_8U�͵�
 *@code
   Mat test_ima=imread("Lena.bmp");
   Mat test_ima1(test_ima.rows, test_ima.cols, CV_8U, Scalar(0));
   test_ima1=Opert_ima(test_ima, 1);
 *@endcode

 *@since 2013.10.16
 *@author lichao
*/
#include "OPert_ima.h"

Mat OPert_ima(Mat& ori_ima,int type)
{
	if( (type<0) || (type>6) )
	{
		cout<<"��������ȷ��type(0,1,2,3,4,5,6)!"<<endl;
		Sleep(2000);
		exit(-1);
	}
	float operat[][9] = {{1.0/9, 1.0/9, 1.0/9, 1.0/9, 1.0/9, 1.0/9, 1.0/9, 1.0/9, 1.0/9},
						  {0, -1.0/4, 0, -1.0/4, 1.0, -1.0/4, 0, -1.0/4, 0},
						  {-1, 0, 1, -1, 0, 1, -1, 0, 1},
						  {-1, -1, -1, 0, 0, 0, 1, 1, 1},
						  {-3, 0, 3, -10, 0, 10, -3, 0, 3},
						  {-3, -10, -3, 0, 0, 0, 3, 10, 3},
						  {0, 0, 0, 0, 1, 0, 0, 0, 0}};

	Mat new_ima(ori_ima.rows, ori_ima.cols, CV_8U, Scalar(0)); // �������ͼ��
	Mat float_ima(ori_ima.rows, ori_ima.cols, CV_32F, Scalar(0)); // �м�floatͼ�񣬱�֤����
	//float_ima=uchar2float(ori_ima); // uchar��ͼ��ת��Ϊfloat��ͼ��

	for (int i=1; i<ori_ima.rows-1; i++)
	{
		float* data  = float_ima.ptr<float>(i);
		uchar* data0 = ori_ima.ptr<uchar>(i-1);
		uchar* data1 = ori_ima.ptr<uchar>(i);
		uchar* data2 = ori_ima.ptr<uchar>(i+1);
		for (int j=1; j<ori_ima.cols; j++)
		{
			data[j] = data0[j-1] * operat[type][0] + data0[j] * operat[type][1] + data0[j+1] * operat[type][2]
					+ data1[j-1] * operat[type][3] + data1[j] * operat[type][4] + data1[j+1] * operat[type][5]
					+ data2[j-1] * operat[type][6] + data2[j] * operat[type][7] + data2[j+1] * operat[type][8];
		}
	}

	new_ima=float2uchar(float_ima); // float��ͼ��ת��Ϊuchar��ͼ��
	return new_ima;
}