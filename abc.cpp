#include<iostream>
#include<graphics.h>
#include<math.h>

void lines(int x1,int y1, int x2, int y2)
{
	int dx=x2-x1, dy=y2-y1,steps;
	float xinc,yinc,x=x1,y=y1;
	
	if(abs(dx)>abs(dy))
		steps=abs(dx);
	else
		steps=abs(dy);
		
	xinc=(float)dx/(float)steps;
	yinc=(float)dy/(float)steps;
	
	for(int i=0;i<=steps;i++)
	{
		putpixel(round(x),round(y),WHITE);
		x+=xinc;
		y+=yinc;
	}
}
 
int main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	
	lines(50,70,60,80);
	delay(6000);
	closegraph();
	return 0;
}
