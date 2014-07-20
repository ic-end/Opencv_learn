/**
 *@brief �ԻҶ�ͼ������˲�����operat�����˲�����
 *@param[in] ori_img Mat��  CV_8U ��; operat Mat�� CV_32F ��;
 *@param[out]
 *@return    new_img Mat��  CV_8U
 *@pre       �����Mat�����ݱ����ǵ�ͨ��CV_8U�͵�
 *@post      �����Mat�������ǵ�ͨ��CV_8U�͵�
 *@code
   Mat test_img=imread("Lena.bmp");
   Mat test_img1(test_img.rows, test_img.cols, CV_8U, Scalar(0));
   test_img1=Opert_img(test_img, operat);
 *@endcode

 *@since 2013.10.17
 *@author lichao
*/
#include "filterImg.h"
Mat filterImg(Mat& ori_img, Mat& operat)
{
	if(ori_img.channels()!=1)
	{
		cout<<"������Ҷ�ͼ��"<<endl;
		Sleep(2000);
		exit(-1);
	}
	Mat new_img(ori_img.rows, ori_img.cols, CV_8U, Scalar(0));
	Mat float_img(ori_img.rows, ori_img.cols, CV_32F, Scalar(0.0)); // �м�ͼ�����
	Mat float_img_mid(ori_img.rows, ori_img.cols, CV_32F, Scalar(0.0));  //
	Mat imgRoi;

	float_img_mid=uchar2float(ori_img);
	int k=operat.rows/2;
	int windrow=operat.rows;
	int windcol=operat.cols;
	Mat midMat(operat.rows, operat.cols, CV_32F, Scalar(0.0));
	for(int i=k; i<ori_img.rows-k; i++)
	{
		float* data=float_img.ptr<float>(i);
		for(int j=k; j<ori_img.cols-k; j++)
		{
			imgRoi=float_img_mid(Rect(j-k,i-k,windcol,windrow)); // ��ȡ����Ȥ����
			midMat=imgRoi.mul(operat);
			data[j]=sum(midMat).val[0]; // ���
		}		
	}
	new_img=float2uchar(float_img);
	return new_img;
}