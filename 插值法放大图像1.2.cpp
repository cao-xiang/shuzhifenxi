#include <iostream>
#include <math.h>
using namespace std;

double nudun (double m,double n,double b,double v,double h)
{
double M[100][100];
double X=1,xx=0,w=1,N=0,P,R=1;
M[0][0]=m;
M[0][1]=n;
M[1][0]=b;
M[1][1]=v;
M[1][2]=(M[1][1]-M[0][1])/(M[1][0]-M[0][0]);
xx=h;
X*=xx-m;
N+=M[1][2]*X;
P=M[0][1]+N;
return P;
}

int main()
{
  double TX[5][5];
  double FD[10][10]={0};
  for(int i=0;i<5;i++)
  {
    for(int j=0;j<5;j++)
   { cin>>TX[i][j];
    FD[2*i][2*j]=TX[i][j];
    }
    }
   
   for(int i=0;i<10;i++) 
    {
      for(int j=0;j<10;j+=2)
      {
        if(FD[i][j]==0&&i!=9)
          FD[i][j]=nudun(double(i-1),FD[i-1][j],double(i+1),FD[i+1][j],double(i));
          if(FD[i][j]==0&&i==9)
          FD[i][j]=nudun(double(i-2),FD[i-2][j],double(i-1),FD[i-1][j],double(i));
          }
          }     
    for(int i=0;i<10;i++)
   { 
   for(int j=0;j<10;j++)
   {
     if(FD[i][j]==0&&i!=9)
      FD[i][j]=nudun(double(j-1),FD[i][j-1],double(j+1),FD[i][j+1],double(j));
        if(FD[i][j]==0&&i==9)
          FD[i][j]=nudun(double(j-2),FD[i][j-2],double(j-1),FD[i][j-1],double(j));
    }
    }
       for(int i=0;i<10;i++)
   { 
   for(int j=0;j<10;j++)
   cout<<FD[i][j]<<"\t";
   cout<<endl;
    }
    
  
}
