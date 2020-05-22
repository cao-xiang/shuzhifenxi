#include<iostream>
using namespace std;

int main()
{
	int n = 1;
	int n2 = 0;
	int n3 = 1;
	int n4 = 0;
	int line0 = 1;
	int line1 = 1;
	int column = 1;
	int picture0[6][6];//定义原像素矩阵
	int picture1[11][11];//定义扩大后的像素矩阵
	for (int i = 0; i <= 10; i++)
	{
		for (int j = 0; j <= 10; j++)
		{
			picture1[i][j] = 0;
		}
	}//将扩大后的像素矩阵初始化为0
	for (int i = 1; i <= 5; i++)
	{
		picture0[0][i] = 255;
	}//将原矩阵的第六列初始值定义为255
	for (int i = 1; i <= 5; i++)
	{
		picture0[i][1] = 255;
		picture0[i][5] = 255;
	}//将原矩阵第一列及第五列初始值定义为255
	picture0[1][2] = 9; picture0[1][3] = 9; picture0[1][4] = 7;
	picture0[2][2] = 5; picture0[2][3] = 255; picture0[2][4] = 255;
	picture0[3][2] = 6; picture0[3][3] = 7; picture0[3][4] = 8;
	picture0[4][2] = 6; picture0[4][3] = 255; picture0[4][4] = 5;
	picture0[5][2] = 8; picture0[5][3] = 6; picture0[5][4] = 9;
	//自定义初始矩阵的灰度值
	while (line0 <= 5)
	{
		double x = 1.5;
		n2 = 2 * n - 1;
		int pot = (2 - x) * picture0[line0][1] + (x - 1) * picture0[line0][2];
		picture1[n2][2] = pot;//以原矩阵的1，2列为插值接点，利用拉格朗日插值计算出扩大后矩阵第二列的灰度值
		x = 4.5;
		pot = (5 - x) * picture0[line0][4] + (x - 4) * picture0[line0][5];
		picture1[n2][8] = pot;//以原矩阵4，5列为插值接点，利用公式计算出扩大后矩阵第八列的灰度值
		if (line0 == 1 || line0 == 3 || line0 == 5)
		{
			x = 2.5;
			pot = ((x - 3) * (x - 4) * picture0[line0][2]) / 2 - ((x - 2) * (x - 4) * picture0[line0][3]) + ((x - 2) * (x - 3) * picture0[line0][4]) / 2;
			picture1[n2][4] = pot;
			x = 3.5;
			pot = ((x - 3) * (x - 4) * picture0[line0][2]) / 2 - ((x - 2) * (x - 4) * picture0[line0][3]) + ((x - 2) * (x - 3) * picture0[line0][4]) / 2;
			picture1[n2][6] = pot;
		}
		line0++;
		n++;
	}//以2，3，4为插值节点，计算扩大后第四列，第六列灰度值
	while (line1 <= 5)
	{
		n4 = 2 * n3 - 1;
		picture1[n4][1] = picture0[line1][1];
		picture1[n4][3] = picture0[line1][2];
		picture1[n4][5] = picture0[line1][3];
		picture1[n4][7] = picture0[line1][4];
		picture1[n4][9] = picture0[line1][5];
		line1++;
		n3++;
	}//将原5*5像素矩阵的所有值赋给扩大后的10*10矩阵
	while (column <= 10)
	{
		if ( column == 2 || column == 3)
		{
			double x2 = 1.5;
			n = 1; n2 = 0;
			while (x2 < 5.5)
			{
				n2 = 2 * n;
				int pot1 = ((x2 - 2) * (x2 - 3) * (x2 - 4) * (x2 - 5) * picture1[1][column]) / 24 - ((x2 - 1) * (x2 - 3) * (x2 - 4) * (x2 - 5) * picture1[3][column]) / 6 + ((x2 - 1) * (x2 - 2) * (x2 - 4) * (x2 - 5) * picture1[5][column]) / 4 - ((x2 - 1) * (x2 - 2) * (x2 - 3) * (x2 - 5) * picture1[7][column]) / 6 + ((x2 - 1) * (x2 - 2) * (x2 - 3) * (x2 - 4) * picture1[9][column]) / 24;
				picture1[n2][column] = pot1;
				x2++;
				n++;
			}

		}//以原矩阵的1，2，3，4，5列为插值节点，计算扩大后矩阵的2，4，6，8行的灰度值
		else if (column == 7 || column == 8)
		{
			double x2 = 1.5;
			int pot1 = ((x2 - 2) * (x2 - 3) * picture1[5][column]) / 2 - ((x2 - 1) * (x2 - 3) * picture1[7][column]) + ((x2 - 1) * (x2 - 2) * picture1[9][column]) / 2;
			picture1[6][column] = pot1;
			x2 = 2.5;
			pot1 = ((x2 - 2) * (x2 - 3) * picture1[5][column]) / 2 - ((x2 - 1) * (x2 - 3) * picture1[7][column]) + ((x2 - 1) * (x2 - 2) * picture1[9][column]) / 2;
			picture1[8][column] = pot1;
		}
		column++;
	}//以1，2，3为插值节点，计算扩大后矩阵第6，8，的第7，8列的灰度值
	cout << "原像素矩阵为：" << endl;
	for (int i = 1; i <= 5; i++)
	{
		for (int j = 1; j <= 5; j++)
		{
			printf("%-6d", picture0[i][j]);
		}
		cout << endl;
	}//输出原像素矩阵
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= 10; j++)
		{
			if (picture1[i][j] == 0)
				picture1[i][j] = 255;
		}
	}//把之前所有灰度值为0的赋值为255
	cout << "扩大后的像素矩阵为:" << endl;
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= 10; j++)
		{
			printf("%-6d", picture1[i][j]);
		}
		cout << endl;
	}
}//输出扩大后的像素矩阵
