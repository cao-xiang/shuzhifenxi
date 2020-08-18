#include<iostream>
using namespace std;
int main()
{
	double a[10][10];    //建立扩展数组
	for (int i = 0; i < 10; i = i + 2)
	{
		for(int j = 0; j < 10; j = j + 2)
			cin >> a[i][j];    //将25个值附给数组
	}
	for (int i = 0; i < 10; i = i + 2)
	{
		for (int j = 1; j < 9; j = j + 2)
		{
 a[i][j] = a[i][j - 1] + (a[i][j - 1] + a[i][j + 1]) / 2;//    将奇数行（不含第9行）            的中间的空间附值                      （用一阶牛顿内插法）
		}
		a[i][9] = a[i][7] + (a[i][7] + a[i][8]) / 2;//将第9行用外插赋值

	}
	for (int j = 0; j < 10; j++)
	{
		for (int i = 1; i < 9; i = i + 2)
		{
a[i][j] = a[i - 1][j] + (a[i - 1][j] + a[i + 1][j])/2;//奇数行间的偶数行空白用两行之间   一阶牛顿内插                                                                                                                                              
		}
		a[9][j] = a[7][j] + (a[7][j] + a[8][j]) / 2;//将第9行用外插
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
			cout << a[i][j] << ",";//将矩阵所有数输出
	}

}
