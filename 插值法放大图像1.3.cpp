#include<iostream>


using namespace std;



//lagrange1和lagrange2是计算扩大数组时产生空白格时的不同情况；

//计算扩大后在原5*5之间的像素块；
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

//计算扩大后产生的新列中的像素块
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
	//构建一个5*5的矩阵；
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			gray1[i][j] = 255;
		}
	}
	//构建一个10*10的矩阵；
	for (int i = 0; i < 10;i++)
	{
		for (int j = 0; j < 10;j++)
		{
			gray2[i][j] = 0;
		}
	}
	//在矩阵中画出数字6的图像；
	gray1[0][1] = 11; gray1[0][2] = 18; gray1[0][3] = 13;
	gray1[1][1] = 78;
	gray1[2][1] = 56; gray1[2][2] = 95; gray1[2][3] = 45;
	gray1[3][1] = 89;                   gray1[3][3] = 48;
	gray1[4][1] = 12; gray1[4][2] = 94; gray1[4][3] = 15;
	cout << "扩大之前的图像" << endl;
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
	//将5*5中的数字放入10*10的数组中；
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			gray2[i * 2][j * 2] = gray1[i][j];
		}
	}
	cout << endl;
	cout << "扩大之后的图像" << endl;
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
	//计算扩大后在原5*5之间的像素块；
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j = j+2)
		{
			//根据情况判断是内插还是外插
			if (gray2[i][j] == 0 && i != 9) //内插
			{
				int v = 0;
				gray2[i][j] = lagrange1(gray2, i, j, v);
			}
			else
			{
				if (gray2[i][j] == 0 && i == 9) //外插
				{
					int  v = 1;
					gray2[i][j] = lagrange1(gray2, i, j, v);
				}
			}
		}
	}
	//计算扩大后产生的新列中的像素块
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			//根据情况判断是内插还是外插
			if (gray2[i][j] == 0 && i != 9)  //内插
			{
				int v = 0;
				gray2[i][j] = lagrange2(gray2, i, j, v);
			}
			else
			{
				if (gray2[i][j] == 0 && i == 9) //外插
				{
					int  v = 1;
					gray2[i][j] = lagrange2(gray2, i, j, v);
				}
			}
		}
	}


	cout << endl;
	cout << "计算其中的差值后的图像" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << endl;
		//下面的判断作用和上面一样；
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
