#include<iostream>
#include<windows.h>
#include<fstream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
using namespace std;
unsigned char *pBmpBuf;//����ͼ�����ݵ�ָ��
int bmpWidth;//ͼ��Ŀ�
int bmpHeight;//ͼ��ĸ�
RGBQUAD *pColorTable;//��ɫ��ָ��
int biBitCount;//ͼ�����ͣ�ÿ����λ��
bool readBmp(char *bmpName) 
{
    FILE *fp=fopen(bmpName,"rb");//�����ƶ���ʽ��ָ����ͼ���ļ�

    if(fp==0)
    return 0;
        //����λͼ�ļ�ͷ�ṹBITMAPFILEHEADER
    fseek(fp, sizeof(BITMAPFILEHEADER),0);
    //����λͼ��Ϣͷ�ṹ��������ȡλͼ��Ϣͷ���ڴ棬����ڱ���head��
    BITMAPINFOHEADER head;  
    fread(&head, sizeof(BITMAPINFOHEADER), 1,fp); //��ȡͼ����ߡ�ÿ������ռλ������Ϣ
    bmpWidth = head.biWidth;
    bmpHeight = head.biHeight;
    biBitCount = head.biBitCount;//�������������ͼ��ÿ��������ռ���ֽ�����������4�ı�����
    int lineByte=(bmpWidth * biBitCount/8+3)/4*4;//�Ҷ�ͼ������ɫ������ɫ�����Ϊ256
    if(biBitCount==8)
    {
        //������ɫ������Ҫ�Ŀռ䣬����ɫ����ڴ�
        pColorTable=new RGBQUAD[256];
        fread(pColorTable,sizeof(RGBQUAD),256,fp);
    }

    //����λͼ��������Ҫ�Ŀռ䣬��λͼ���ݽ��ڴ�
    pBmpBuf=new unsigned char[lineByte * bmpHeight];
    fread(pBmpBuf,1,lineByte * bmpHeight,fp);
    fclose(fp);//�ر��ļ�
    return 1;//��ȡ�ļ��ɹ�
} 
bool saveBmp(char *bmpName, unsigned char *imgBuf, int width, int height, int biBitCount, RGBQUAD *pColorTable)
{

    //���λͼ����ָ��Ϊ0����û�����ݴ��룬��������
    if(!imgBuf)
        return 0;
    //��ɫ���С�����ֽ�Ϊ��λ���Ҷ�ͼ����ɫ��Ϊ1024�ֽڣ���ɫͼ����ɫ���СΪ0
    int colorTablesize=0;
    if(biBitCount==8)
        colorTablesize=1024;
    //���洢ͼ������ÿ���ֽ���Ϊ4�ı���
    int lineByte=(width * biBitCount/8+3)/4*4;
    //�Զ�����д�ķ�ʽ���ļ�
    FILE *fp=fopen(bmpName,"wb");
    if(fp==0)
        return 0;
    //����λͼ�ļ�ͷ�ṹ��������д�ļ�ͷ��Ϣ
    BITMAPFILEHEADER fileHead;
    fileHead.bfType = 0x4D42;//bmp����
    //bfSize��ͼ���ļ�4����ɲ���֮��
    fileHead.bfSize= sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + colorTablesize + lineByte*height;
    fileHead.bfReserved1 = 0;
    fileHead.bfReserved2 = 0;
    //bfOffBits��ͼ���ļ�ǰ3����������ռ�֮��
    fileHead.bfOffBits=54+colorTablesize;
    //д�ļ�ͷ���ļ�
    fwrite(&fileHead, sizeof(BITMAPFILEHEADER),1, fp);
    //����λͼ��Ϣͷ�ṹ��������д��Ϣͷ��Ϣ
    BITMAPINFOHEADER head; 
    head.biBitCount=biBitCount;
    head.biClrImportant=0;
    head.biClrUsed=0;
    head.biCompression=0;
    head.biHeight=height;
    head.biPlanes=1;
    head.biSize=40;
    head.biSizeImage=lineByte*height;
    head.biWidth=width;
    head.biXPelsPerMeter=0;
    head.biYPelsPerMeter=0;
    //дλͼ��Ϣͷ���ڴ�
    fwrite(&head, sizeof(BITMAPINFOHEADER),1, fp);
    //����Ҷ�ͼ������ɫ��д���ļ� 
    if(biBitCount==8)
        fwrite(pColorTable, sizeof(RGBQUAD),256, fp);
    //дλͼ���ݽ��ļ�
    fwrite(imgBuf, height*lineByte, 1, fp);
    //�ر��ļ�
    fclose(fp);
    return 1;
}
void image_scaling_doubleline()
{ 	
    char readPath[] = "F:\\555.bmp";
	readBmp(readPath); 	
	unsigned char *imagedata ; //��̬����洢ԭͼƬ��������Ϣ�Ķ�ά����
	unsigned char *imagedataScal ;//��̬����洢���ź��ͼƬ��������Ϣ�Ķ�ά����
	imagedata = pBmpBuf; 	
	float ExpScalValue = 0; ////���������ű���������С����
	int FloatToIntwidth, FloatToIntheight;/////С���������(float To Int)
	int RotateAngle = 90;//Ҫ���ŵĽǶȣ�Ĭ��90 	//ͼƬ���Ŵ���
	cout << "������Ҫ���ŵı���:" << endl;	
	cin >> ExpScalValue; 	///���ExpScalValue����С������Ҫ������	///�����������Ž��ȡ��	
	FloatToIntwidth = (int)(ExpScalValue*bmpWidth);
	FloatToIntheight = (int)(ExpScalValue*bmpHeight);	//ͼ��ÿһ�е��ֽ���������4��������	
	int lineByte = (bmpWidth * biBitCount / 8 + 3) / 4 * 4;
	int lineByte2 = (FloatToIntwidth * biBitCount / 8 + 3) / 4 * 4;	
	imagedataScal = new unsigned char[lineByte2 * FloatToIntheight];///Ϊ���ź�ͼ�����洢�ռ�
	for (int i = 0; i < FloatToIntheight; i++)	
		for (int j = 0; j < FloatToIntwidth; j++)	
	    	{	
				float d_original_img_hnum = i / ExpScalValue;	
		        float d_original_img_wnum = j / ExpScalValue;
		        int i_original_img_hnum = d_original_img_hnum;	
				int i_original_img_wnum = d_original_img_wnum;
				float distance_to_a_x = d_original_img_wnum - i_original_img_wnum;//��ԭͼ������a���ˮƽ���� 
				float distance_to_a_y = d_original_img_hnum - i_original_img_hnum;//��ԭͼ������a��Ĵ�ֱ���� 
				int original_point_a = i_original_img_hnum*lineByte + i_original_img_wnum * 3;//����λ��ƫ��������Ӧ��ͼ��ĸ����ص�RGB�����,�൱�ڵ�A  
				int original_point_b = i_original_img_hnum* lineByte + (i_original_img_wnum + 1) * 3;//����λ��ƫ��������Ӧ��ͼ��ĸ����ص�RGB�����,�൱�ڵ�B 
		    	int original_point_c = (i_original_img_hnum + 1)* lineByte + i_original_img_wnum * 3;//����λ��ƫ��������Ӧ��ͼ��ĸ����ص�RGB�����,�൱�ڵ�C   
			  	int original_point_d = (i_original_img_hnum + 1)* lineByte + (i_original_img_wnum + 1) * 3;//����λ��ƫ��������Ӧ��ͼ��ĸ����ص�RGB�����,�൱�ڵ�D  
				if (i_original_img_hnum  == bmpHeight - 1)
				    {	
				    original_point_c = original_point_a;
					original_point_d = original_point_b;
             		}
				if (i_original_img_wnum  == bmpWidth - 1)
					{		
					original_point_b = original_point_a;
				    original_point_d = original_point_c;		
					} 
					int pixel_point = i*lineByte2 + j * 3;//ӳ��߶ȱ任ͼ������λ��ƫ����    
	            for (int k = 0; k < 3; k++)		
					{		
						imagedataScal[pixel_point + k] =
							imagedata[original_point_a + k] * (1 - distance_to_a_x)*(1 - distance_to_a_y) +	
							imagedata[original_point_b + k ]* distance_to_a_x*(1 - distance_to_a_y) +
							imagedata[original_point_c + k ]* distance_to_a_y*(1 - distance_to_a_x) +
							imagedata[original_point_d + k ]* distance_to_a_y*distance_to_a_x;
														/*assert((pixel_point + k)<(lineByte2 * FloatToIntheight));	
										      	     	assert((original_point_a + k)<(lineByte * bmpHeight));	
													 	assert((original_point_b + k)<(lineByte * bmpHeight));	
														assert((original_point_c + k)<(lineByte * bmpHeight));
														assert((original_point_d + k)<(lineByte * bmpHeight));*/ 
					} 	
	        }	
			char writePath[] = "F:\\444.bmp";
			saveBmp(writePath, imagedataScal, FloatToIntwidth, FloatToIntheight, biBitCount, pColorTable);
			printf("���ű任��ɣ���鿴Scalresult.bmp�ļ���\n\n");	//�ͷ��ڴ�	
			delete[] imagedata;	
			delete[] imagedataScal;
}

int main()
{
	image_scaling_doubleline();
	return 0; 
}
