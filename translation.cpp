#include<graphics.h>
#include<iostream>
#include<math.h>

using namespace std;

void mult(float A[3][3],float B[3][3])
{
	float result[3][3];
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			result[i][j]=0;
			for(int k=0;k<3;k++)
			{
				result[i][j]+=A[i][j]+B[i][j];
			}
		}
	}
	line(result[0][0],result[0][1],result[1][0],result[1][1]);
	line(result[1][0],result[1][1],result[2][0],result[2][1]);
	line(result[0][0],result[0][1],result[2][0],result[2][1]);
}
void translation(float coord[3][3])
{
	int tx,ty;
	cout<<"enter tx and ty";
	cin>>tx>>ty;
	float trans[3][3]={{1,0,0},{0,1,0},{tx,ty,1}};
	setcolor(GREEN);
	mult(coord,trans);
}
void scaling(float coord[3][3])
{
	int sx,sy;
	cout<<"enter sx and sy";
	cin>>sx>>sy;
	float sca[3][3]={{sx,0,0},{0,sy,0},{0,0,1}};
	setcolor(BLUE);
	mult(coord,sca);
}
void rotation(float coord[3][3])
{
	int degree;
	cout<<"enter degree";
	cin>>degree;
	int radian;
	radian=(3.14/180)*degree
	float rot[3][3]={{cos(radian),sin(radian),0},{-sin(radian),cos(radian),0},{0,0,1}}
	setcolor(GREEN);
	mult(coord,rot);
}
int main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	
	float coord[3][3];
	for(int i=0;i<3;i++)
	{
		cout<<"enter x"<<i+1<<" : ";
		cin>>coord[i][0];
		cout<<"enter y"<<i+1<<" : ";
		cin>>coord[i][1];
		coord[i][2]=1;
	}
	
	line(coord[0][0],coord[0][1],coord[1][0],coord[1][1]);
	line(coord[1][0],coord[1][1],coord[2][0],coord[2][1]);
	line(coord[0][0],coord[0][1],coord[2][0],coord[2][1]);
	translation(coord);
	scaling(coord);
	rotation(coord);
	
	delay(10000);
	closegraph();
	return 0;
}
