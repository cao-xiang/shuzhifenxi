#include <graphics.h>
#include <conio.h>
#include<iostream>
using namespace std;
int main()
{
	initgraph(500,500);                           /*初始化图形系统*/
	COLORREF picture[6][6]={RGB(0,0,0)},          /*用数组表示像素*/ 
	col = RGB(255,255,255),                       /*图形的颜色*/ 
	colb,c,c1,c2,c3,c4,                           /*背景颜色，所需计算的颜色及其四周颜色*/ 
	r1,r2,r3,r4,g1,g2,g3,g4,b1,b2,b3,b4;          /*四周颜色的RGB的值*/ 
	colb=RGB(0,0,0);
	setbkcolor(colb);                           /*填充背景颜色*/ 
	/***开始绘制图形***/  
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
         	    setfillcolor(picture[i][j]);      /*这个函数用于设置当前设备填充颜色*/
    		    bar(20*(i-1),20*(j-1),20*i,20*j); /*输出图形*/ 
    	    }
		}
	}
    getch();
	cleardevice();                                /*清屏。这个函数用于清空绘图设备。具体的，是用当前背景色清空绘图设备，并将当前点移至 (0, 0)。*/
	/*将原背景点移动到放大后的图形上*/ 
	for (int i = 0; i <= 500; i++)
	{
		for (int j = 0; j <= 500; j++)
		{
			putpixel(i, j, colb);

		}
	}
	/*将原图形移动到放大后的图形上*/ 
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
	/*利用双线性插值算法计算像素插值，用待插值像素周围的四个像素颜色值计算其他空点的像素插值*/ 
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
	/*获取像素点的RGB中的R,G,B值*/ 
	    	r1=GetRValue(c1);r2=GetRValue(c2);
    		r3=GetRValue(c3);r4=GetRValue(c4);
	    	g1=GetGValue(c1);g2=GetGValue(c2);
    		g3=GetGValue(c3);g4=GetGValue(c4);
    		b1=GetBValue(c1);b2=GetBValue(c2);
	    	b3=GetBValue(c3);b4=GetBValue(c4);
	    	/*原公式为f(x,y)=f(Q11)(x2-x)(y2-y)/(x2-x1)(y2-y1)+f(Q21)(x-x1)(y2-y)/(x2-x1)(y2-y1)+f(Q12)(x2-x)(y-y1)/(x2-x1)(y2-y1)+f(Q21)(x-x1)(y-y1)/(x2-x1)(y2-y1) */
            c=RGB(int((r1+r2+r3+r4)/4),int((g1+g2+g3+g4)/4),int((b1+b2+b3+b4)/4));
	    	if(getpixel(i,j)!=col)
			{
				putpixel(i,j,c);
			}                                                   
		}
	}
    getch();
}
