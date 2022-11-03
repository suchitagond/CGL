#include<iostream>
#include<math.h>
#include<graphics.h>
using namespace std;

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
	
	int x1,y1,x2,y2;
	cout<<"enter the coordinates";
	cin>>x1;
	cin>>x2;
	cin>>y1;
	cin>>y2;
	
	l(x1,y1,x2,y1);
	l(x2,y1,x2,y2);
	l(x2,y2,x1,y2);
	l(x1,y2,x1,y1);
	
	delay(60000);
	closegraph();
	return 0;
}
