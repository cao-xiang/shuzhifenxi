#include <graphics.h>
#include <conio.h>
#include<iostream>
using namespace std;
int main()
{
	initgraph(500,500);                           /*��ʼ��ͼ��ϵͳ*/
	COLORREF picture[6][6]={RGB(0,0,0)},          /*�������ʾ����*/ 
	col = RGB(255,255,255),                       /*ͼ�ε���ɫ*/ 
	colb,c,c1,c2,c3,c4,                           /*������ɫ������������ɫ����������ɫ*/ 
	r1,r2,r3,r4,g1,g2,g3,g4,b1,b2,b3,b4;          /*������ɫ��RGB��ֵ*/ 
	colb=RGB(0,0,0);
	setbkcolor(colb);                           /*��䱳����ɫ*/ 
	/***��ʼ����ͼ��***/  
	picture[2][1] = col;picture[3][1] = col;picture[4][1] = col;
	picture[2][2] = col;picture[2][3] = col;picture[3][3] = col;
	picture[4][3] = col;picture[2][4] = col;picture[4][4] = col;
	picture[2][5] = col;picture[3][5] = col;picture[4][5] = col;
    for(int i=0;i<=5;i++)
    {
    	for(int j=0;j<=5;j++)
    	{
    		if(picture[i][j]==col)
    		{
         	    setfillcolor(picture[i][j]);      /*��������������õ�ǰ�豸�����ɫ*/
    		    bar(20*(i-1),20*(j-1),20*i,20*j); /*���ͼ��*/ 
    	    }
		}
	}
    getch();
	cleardevice();                                /*�������������������ջ�ͼ�豸������ģ����õ�ǰ����ɫ��ջ�ͼ�豸��������ǰ������ (0, 0)��*/
	/*��ԭ�������ƶ����Ŵ���ͼ����*/ 
	for (int i = 0; i <= 500; i++)
	{
		for (int j = 0; j <= 500; j++)
		{
			putpixel(i, j, colb);

		}
	}
	/*��ԭͼ���ƶ����Ŵ���ͼ����*/ 
	for(int i=0;i<=5;i++)
    {
    	for(int j=0;j<=5;j++)
    	{
    		if(picture[i][j]==col)
    		{
        		setfillcolor(picture[i][j]);
    	    	bar(40*(i-1),40*(j-1),40*i-20,40*j-20);
    	    }
		}
	}
	getch();
	/*����˫���Բ�ֵ�㷨�������ز�ֵ���ô���ֵ������Χ���ĸ�������ɫֵ���������յ�����ز�ֵ*/ 
		for (int i = 0; i <= 480; i++)
	{
		for (int j = 0; j <= 480; j++)
		{
		    if(i<20) 
		    {
		        c1=colb;
		    }
		    if(j<20)
		    {
	        	c3=colb;
		    }
	    	if(i>=20&&j>=20)
		    {
	        	c1=getpixel(i-20,j);
	        	c3=getpixel(i,j-20);
	        }
	    	c2=getpixel(i+20,j);
	    	c4=getpixel(i,j+20);
	/*��ȡ���ص��RGB�е�R,G,Bֵ*/ 
	    	r1=GetRValue(c1);r2=GetRValue(c2);
    		r3=GetRValue(c3);r4=GetRValue(c4);
	    	g1=GetGValue(c1);g2=GetGValue(c2);
    		g3=GetGValue(c3);g4=GetGValue(c4);
    		b1=GetBValue(c1);b2=GetBValue(c2);
	    	b3=GetBValue(c3);b4=GetBValue(c4);
	    	/*ԭ��ʽΪf(x,y)=f(Q11)(x2-x)(y2-y)/(x2-x1)(y2-y1)+f(Q21)(x-x1)(y2-y)/(x2-x1)(y2-y1)+f(Q12)(x2-x)(y-y1)/(x2-x1)(y2-y1)+f(Q21)(x-x1)(y-y1)/(x2-x1)(y2-y1) */
            c=RGB(int((r1+r2+r3+r4)/4),int((g1+g2+g3+g4)/4),int((b1+b2+b3+b4)/4));
	    	if(getpixel(i,j)!=col)
			{
				putpixel(i,j,c);
			}                                                   
		}
	}
    getch();
}
