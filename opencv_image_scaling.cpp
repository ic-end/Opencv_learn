#include <iostream>
#include <opencv2\highgui\highgui.hpp>

using namespace std;
using namespace cv;

void decide_boud(double in,double low,double high)//�жϲ��������Ƿ�׼ȷ
{
	if ((in<=low)||(in>high))
	{
		cout<<"����Ĳ���������Χ��"<<endl;
		_sleep(2000);
		exit(0) ;
	}
}
int main()
{
	Mat ori_ima=imread("D:\\Document\\vidpic\\pictures\\LenaRGB.bmp");//ԭʼͼ��
	double scale_R=1;//�е����ű�
	double scale_C=1;//�е����ű�
	int new_R;//��ͼ�����
	int new_C;//��ͼ�����

	//�������ű�������
	cout<<"�������е����űȣ�0,2����"<<endl;
	cin>>scale_R;
	decide_boud(scale_R,0,2);
	cout<<"�������е����űȣ�0,2����"<<endl;
	cin>>scale_C;
	decide_boud(scale_C,0,2);

	//������ͼ����к���
	new_R=int(scale_R*ori_ima.rows);
	new_C=int(scale_C*ori_ima.cols);

	//��ʼ���µ�ͼ��
	Mat new_ima(new_R,new_C,CV_8UC3,Scalar(0,0,0));

	double pix11=0,pix12=0,pix21=0,pix22=0;//˫���Ա任��Χ����

	for(int i=0;i<new_R;i++)
		for(int j=0;j<new_C;j++)
		{
			double old_i=i/scale_R;//old_i��Ӧԭʼͼ�������
			double old_j=j/scale_C;
			if((old_i/double(int(old_i))==1.0)&&(old_j/double(int(old_j))==1.0))//��������ֱ�ӷ�ֵ
			{
				new_ima.at<Vec3b>(i,j)[0]=ori_ima.at<Vec3b>(old_i,old_j)[0];
				new_ima.at<Vec3b>(i,j)[1]=ori_ima.at<Vec3b>(old_i,old_j)[1];
				new_ima.at<Vec3b>(i,j)[2]=ori_ima.at<Vec3b>(old_i,old_j)[2];
			}
			else//���������꣬��˫���Բ�ֵ�㷨
			{
				int old_ii=double(int(old_i));
				int old_jj=double(int(old_j));
				for (uchar k=0;k<3;k++)
				{
					//ȡ��old_i,old_j����Χ���ĸ�����
					if((old_ii==ori_ima.rows-1)&&(old_jj!=ori_ima.cols-1))//�±߽紦��
					{
						pix11=double(ori_ima.at<Vec3b>(old_ii,old_jj)[k]);
						pix12=double(ori_ima.at<Vec3b>(old_ii,old_jj+1)[k]);
						pix21=double(ori_ima.at<Vec3b>(old_ii,old_jj)[k]);
						pix22=double(ori_ima.at<Vec3b>(old_ii,old_jj+1)[k]);
					}
					else if((old_jj==ori_ima.cols-1)&&(old_ii!=ori_ima.rows-1))//�ұ߽紦��
					{
						pix11=double(ori_ima.at<Vec3b>(old_ii,old_jj)[k]);
						pix12=double(ori_ima.at<Vec3b>(old_ii,old_jj)[k]);
						pix21=double(ori_ima.at<Vec3b>(old_ii+1,old_jj)[k]);
						pix22=double(ori_ima.at<Vec3b>(old_ii+1,old_jj)[k]);
					}
					else if((old_jj==ori_ima.cols-1)&&(old_ii==ori_ima.rows-1))//���½Ǵ���
					{
						pix11=double(ori_ima.at<Vec3b>(old_ii,old_jj)[k]);
						pix12=double(ori_ima.at<Vec3b>(old_ii,old_jj)[k]);
						pix21=double(ori_ima.at<Vec3b>(old_ii,old_jj)[k]);
						pix22=double(ori_ima.at<Vec3b>(old_ii,old_jj)[k]);
					}

					else
					{
						pix11=double(ori_ima.at<Vec3b>(old_ii,old_jj)[k]);
						pix12=double(ori_ima.at<Vec3b>(old_ii,old_jj+1)[k]);
						pix21=double(ori_ima.at<Vec3b>(old_ii+1,old_jj)[k]);
						pix22=double(ori_ima.at<Vec3b>(old_ii+1,old_jj+1)[k]);
					}
					new_ima.at<Vec3b>(i,j)[k]=uchar((old_jj+1-old_j)*((old_i-old_ii)*pix21+(old_ii+1-old_i)*pix11)+(old_j-old_jj)*((old_i-old_ii)*pix22+(old_ii+1-old_i)*pix12));

				}
			}
		}
		namedWindow("ԭʼͼ��");
		imshow("ԭʼͼ��",ori_ima);
		namedWindow("���ź��ͼ��");
		imshow("���ź��ͼ��",new_ima);
		waitKey(0);
}