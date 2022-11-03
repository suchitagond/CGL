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
void cc(int xc,int yc,int r)
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
void l(int x1 , int y1 , int x2, int y2 )
{
	int dx=x2-x1, dy=y2-y1,steps;
	float xinc , yinc , x=x1 ,y=y1;
	
	if (abs(dx)>abs(dy))
		steps=abs(dx);
	else
		steps=abs(dy);
		
	xinc=(float)dx/(float)steps;
	yinc=(float)dy/(float)steps;
	
	for(int i=0;i<=steps;i++)
	{
		putpixel(round(x),round(y),WHITE);
		
		x=x+xinc;
		y=y+yinc;
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
	cc(xc,yc,r/2);
	
	l(xc,yc-r,xc+0.86*r,yc+0.5*r);
	l(xc+0.86*r,yc+0.5*r,xc-0.86*r,yc+0.5*r);
	l(xc-0.86*r,yc+0.5*r,xc,yc-r);

	
	delay(6000);
	closegraph();
	return 0;
	
}
