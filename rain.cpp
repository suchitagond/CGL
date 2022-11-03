#include<iostream>
#include<graphics.h>
#include<math.h>

void man()
{
	int i,x,y;
	line(0,450,getmaxx(),450);
	for(i=0;i<getmaxx()-180;i++)
	{
		cleardevice();
		rectangle(10+i,300,60+i,400);
		rectangle(70+i,363,80+i,383);
		line(75+i,350,75+i,363);
		line(15+i,400,55+i,450);
		line(15+i,450,55+i,400);
		circle(35+i,280,20);
		line(35+i,310,75+i,350);
		line(60+i,340,75+i,310);
		line(75+i,310,75+i,250);
		line(0+i,250,150+i,250);
		arc(75+i,250,180,0,75);
		for(int j=0;j<100;j++)
		{
			x=rand()%getmaxx();
			y=rand()%getmaxy();
			line(x,y,x+4,y+4);
		}
	}
}
int main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	man();
	delay(10000);
	closegraph();
	return 0;
}
