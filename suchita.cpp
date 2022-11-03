#include<iostream>
#include<math.h>
#include<graphics.h>
using namespace std;

void drawcircle(int xc, int yc, int x, int y)
	{
		putpixel(xc+x,yc+y,WHITE);
		putpixel(xc-x,yc+y,WHITE);
		putpixel(xc+x,yc-y,WHITE);
		putpixel(xc-x,yc-y,WHITE);
		putpixel(xc+y,yc+x,WHITE);
		putpixel(xc-y,yc+x,WHITE);
		putpixel(xc+y,yc-x,WHITE);
		putpixel(xc-y,yc-x,WHITE);
	}
void c(int xc,int yc,int r)
{
	int x=0,y=r,D=3-2*r;
	
	while(x<=y)
	{
		drawcircle(xc,yc,x,y);
		x=x+1;
		if (D<0)
			D=D+4*x+6;
		else
		{
			y=y-1;
			D=D+4*(x-y)+10;
		}
	}		
}


int main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	
	int xc,yc,r;
	cout<<"enter coordinates";
	cin>>xc;
	cin>>yc;
	cin>>r;
	c(xc,yc,r);
	
	
	delay(6000);
	closegraph();
	return 0;
	
}
