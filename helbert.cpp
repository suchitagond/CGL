#include<iostream>
#include<graphics.h>
#include<math.h>

using namespace std;

//helbert curve
void move(int dir)
{
	if(dir==down)
	{
		y=y+10;
	}
	if(dir==up)
	{
		y=y-10;
	}
	if(dir==right)
	{
		x=x+10;
	}
	if(dir==left)
	{
		x=x-10;
	}
}
void hilbert(int shape,int a)
{
	if(a>=0)
	{
		a--;
		hilbert(left,a);
		move(down);
		hilbert(up,a);
		move(right);
		hilbert(up,a);
		move(up);
		hilbert(right,a);
		break;
	}
}
int main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	int down=1,up=2,right=3,left=4;
	int a;
	cout<<"no. of itrations";
	cin>>a;
	hilbert(up,a);
	
	return 0;
}
