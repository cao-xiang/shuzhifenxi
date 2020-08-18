#include<iostream>


using namespace std;



//lagrange1��lagrange2�Ǽ�����������ʱ�����հ׸�ʱ�Ĳ�ͬ�����

//�����������ԭ5*5֮������ؿ飻
float lagrange1(float gray2[10][10],int n,int m,int k)
{
	float yresult = 0.0;
	int x1, x2;
	int y1, y2;
	int x;
	x = n;
	if (k ==0)
	{
		x1 = n - 1;
		x2 = n + 1;
		y1 = gray2[n - 1][m];
		y2 = gray2[n + 1][m];
		yresult = ((x - x2) * y1) / (x1 - x2) + ((x - x1) * y2) / (x2 - x1);

	}
	else
	{
		x1 = n - 2;
		x2 = n - 1;
		y1 = gray2[n - 2][m];
		y2 = gray2[n - 1][m];
		yresult = ((x - x2) * y1) / (x1 - x2) + ((x - x1) * y2) / (x2 - x1);
	}
	return yresult;

}

//�������������������е����ؿ�
float lagrange2(float gray2[10][10], int n, int m, int k)
{

	float yresult = 0.0;
	int x1, x2;
	int y1, y2;
	int x;
	x = m;
	if (k == 0)
	{
		x1 = m - 1;
		x2 = m + 1;
		y1 = gray2[n][m - 1];
		y2 = gray2[n][m + 1];
		yresult = ((x - x2) * y1) / (x1 - x2) + ((x - x1) * y2) / (x2 - x1);
	}
	else
	{
		x1 = m - 2;
		x2 = m - 1;
		y1 = gray2[n][m - 2];
		y2 = gray2[n][m - 1];
		yresult = ((x - x2) * y1) / (x1 - x2) + ((x - x1) * y2) / (x2 - x1);
	}
	return yresult;
}
int main()
{
	float  gray1[5][5];
	float	gray2[10][10];
	//����һ��5*5�ľ���
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			gray1[i][j] = 255;
		}
	}
	//����һ��10*10�ľ���
	for (int i = 0; i < 10;i++)
	{
		for (int j = 0; j < 10;j++)
		{
			gray2[i][j] = 0;
		}
	}
	//�ھ����л�������6��ͼ��
	gray1[0][1] = 11; gray1[0][2] = 18; gray1[0][3] = 13;
	gray1[1][1] = 78;
	gray1[2][1] = 56; gray1[2][2] = 95; gray1[2][3] = 45;
	gray1[3][1] = 89;                   gray1[3][3] = 48;
	gray1[4][1] = 12; gray1[4][2] = 94; gray1[4][3] = 15;
	cout << "����֮ǰ��ͼ��" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << endl;
		for (int j = 0; j < 5; j++)
		{
			if (gray1[i][j] > 100)
			{
				cout << gray1[i][j] << "    ";
			}
			else
			{
				cout << gray1[i][j] << "     ";
			}
		}
	}
	//��5*5�е����ַ���10*10�������У�
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			gray2[i * 2][j * 2] = gray1[i][j];
		}
	}
	cout << endl;
	cout << "����֮���ͼ��" << endl;
	for (int i = 0; i < 10;i++)
	{
		cout << endl;
		for (int j = 0; j < 10;j++)
		{
			if (gray2[i][j] > 100)
			{
				cout << gray2[i][j] << "    ";
			}
			else
			  if(gray2[i][j]>10)
			{
				cout << gray2[i][j] << "     ";
			}
			  else
			  {
				  cout << gray2[i][j] << "      ";
			  }
		}
	}
	//�����������ԭ5*5֮������ؿ飻
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j = j+2)
		{
			//��������ж����ڲ廹�����
			if (gray2[i][j] == 0 && i != 9) //�ڲ�
			{
				int v = 0;
				gray2[i][j] = lagrange1(gray2, i, j, v);
			}
			else
			{
				if (gray2[i][j] == 0 && i == 9) //���
				{
					int  v = 1;
					gray2[i][j] = lagrange1(gray2, i, j, v);
				}
			}
		}
	}
	//�������������������е����ؿ�
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			//��������ж����ڲ廹�����
			if (gray2[i][j] == 0 && i != 9)  //�ڲ�
			{
				int v = 0;
				gray2[i][j] = lagrange2(gray2, i, j, v);
			}
			else
			{
				if (gray2[i][j] == 0 && i == 9) //���
				{
					int  v = 1;
					gray2[i][j] = lagrange2(gray2, i, j, v);
				}
			}
		}
	}


	cout << endl;
	cout << "�������еĲ�ֵ���ͼ��" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << endl;
		//������ж����ú�����һ����
		for (int j = 0; j < 10; j++)
		{
			if (gray2[i][j] < -100)
			{
				cout << gray2[i][j] << "   ";
			}
			else
			if (gray2[i][j] < -10)
			{
				cout << gray2[i][j] << "    ";
			}
			else
			if (gray2[i][j] <0)
			{
				cout << gray2[i][j] << "     ";
			}
			else
			if (gray2[i][j] > 100)
			{
				cout << gray2[i][j] << "    ";
			}
			else
			if (gray2[i][j] > 10)
			{
				cout << gray2[i][j] << "     ";
			}
			else
			{
				cout << gray2[i][j] << "      ";
			}
		}
	}

	return 0;
}
