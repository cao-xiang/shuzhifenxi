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
	int picture0[6][6];//����ԭ���ؾ���
	int picture1[11][11];//�������������ؾ���
	for (int i = 0; i <= 10; i++)
	{
		for (int j = 0; j <= 10; j++)
		{
			picture1[i][j] = 0;
		}
	}//�����������ؾ����ʼ��Ϊ0
	for (int i = 1; i <= 5; i++)
	{
		picture0[0][i] = 255;
	}//��ԭ����ĵ����г�ʼֵ����Ϊ255
	for (int i = 1; i <= 5; i++)
	{
		picture0[i][1] = 255;
		picture0[i][5] = 255;
	}//��ԭ�����һ�м������г�ʼֵ����Ϊ255
	picture0[1][2] = 9; picture0[1][3] = 9; picture0[1][4] = 7;
	picture0[2][2] = 5; picture0[2][3] = 255; picture0[2][4] = 255;
	picture0[3][2] = 6; picture0[3][3] = 7; picture0[3][4] = 8;
	picture0[4][2] = 6; picture0[4][3] = 255; picture0[4][4] = 5;
	picture0[5][2] = 8; picture0[5][3] = 6; picture0[5][4] = 9;
	//�Զ����ʼ����ĻҶ�ֵ
	while (line0 <= 5)
	{
		double x = 1.5;
		n2 = 2 * n - 1;
		int pot = (2 - x) * picture0[line0][1] + (x - 1) * picture0[line0][2];
		picture1[n2][2] = pot;//��ԭ�����1��2��Ϊ��ֵ�ӵ㣬�����������ղ�ֵ�������������ڶ��еĻҶ�ֵ
		x = 4.5;
		pot = (5 - x) * picture0[line0][4] + (x - 4) * picture0[line0][5];
		picture1[n2][8] = pot;//��ԭ����4��5��Ϊ��ֵ�ӵ㣬���ù�ʽ�������������ڰ��еĻҶ�ֵ
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
	}//��2��3��4Ϊ��ֵ�ڵ㣬�������������У������лҶ�ֵ
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
	}//��ԭ5*5���ؾ��������ֵ����������10*10����
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

		}//��ԭ�����1��2��3��4��5��Ϊ��ֵ�ڵ㣬�������������2��4��6��8�еĻҶ�ֵ
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
	}//��1��2��3Ϊ��ֵ�ڵ㣬�������������6��8���ĵ�7��8�еĻҶ�ֵ
	cout << "ԭ���ؾ���Ϊ��" << endl;
	for (int i = 1; i <= 5; i++)
	{
		for (int j = 1; j <= 5; j++)
		{
			printf("%-6d", picture0[i][j]);
		}
		cout << endl;
	}//���ԭ���ؾ���
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= 10; j++)
		{
			if (picture1[i][j] == 0)
				picture1[i][j] = 255;
		}
	}//��֮ǰ���лҶ�ֵΪ0�ĸ�ֵΪ255
	cout << "���������ؾ���Ϊ:" << endl;
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= 10; j++)
		{
			printf("%-6d", picture1[i][j]);
		}
		cout << endl;
	}
}//������������ؾ���
