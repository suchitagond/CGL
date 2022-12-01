#include<iostream>
#include<graphics.h>
//#include<conio.h>
//#include<stdlib.h>
using namespace std;

class point
{
	int x,y,inter[20],v,xmin,ymin,xmax,ymax;
	friend class polygon;
};

class polygon:public point
{
	point p[20];
public:
	int c;
	void read();
	void display();
	void calcs();
	void ints(float);
	void sort(int);
};

void polygon::read()
{
	int i;
	cout<<"enter the no. of vertices of a polygon : ";
	cin>>v;
	if(v>2)
	{
		for(i=0;i<v;i++)
		{
			cout<<"enter the vertex "<<i+1<<" : "<<endl;
			cout<<"X"<<i+1;
			cin>>p[i].x;
			cout<<"Y"<<i+1;
			cin>>p[i].y;
		}
		p[i].x=p[0].x;
		p[i].y=p[0].y;
		xmin=xmax=p[0].x;
		ymin=ymax=p[0].y;
	}
	else
	{
		cout<<"enter valid no of vertices: "<<endl;
	}
}

void polygon::display()
{
	int ch1;
	char ch;
	float s,s2;
	do
	{
		cout<<"1)scan line fill\n2)exit\n";
		cout<<"enter your choice : ";
		cin>>ch1;
		switch(ch1)
		{
			case 1:
				s=ymin+0.01;
				delay(100);
				cleardevice();
				while(s<=ymax)
				{
					ints(s);
					sort(s);
					s++;
				}
				break;
			case 2:
				exit(0);
		}
		cout<<"do you wamt to continue (y/n) : ";
		cin>>ch;
	}while(ch=='y');
}

void polygon::ints(float z)
{
	int x1,x2,y1,y2,temp,c=0;
	for(int i=0;i<v;i++)
	{
		x1=p[i].x;
		y1=p[i].y;
		x2=p[i+1].x;
		y2=p[i+1].y;
		if(y2<y1)
		{
			temp=x1;
			x1=x2;
			x2=temp;
			temp=y1;
			y1=y2;
			y2=temp;
		}
		if(z<=y2 && z>y1)
		{
			if((y1-y2)==0)
			{
				x=x1;
			}
			else
			{
				x=((x2-x1)*(z-y1)/(y2-y1));
				x=x+1;
			}
			if(x<=xmax && x>=xmin)
			{
				inter[c++]=x;
			}
		}
	}
}

void polygon:: sort(int z)
{
	int temp;
	for(int i=0;i<v;i++)
	{
		line(p[i].x,p[i].y,p[i+1].x,p[i+1].y);
	}
	delay(100);
	for(int i=0;i<c;i++)
	{
		delay(100);
		line(inter[i],z,inter[i+1],z);
	}
}

void polygon:: calcs()
{
	for(int i=0;i<v;i++)
	{
		if(xmin>p[i].x)
		{
			xmin=p[i].x;
		}
		if(xmax>p[i].x)
		{
			xmax=p[i].x;
		}
		if(ymin>p[i].y)
		{
			ymin=p[i].y;
		}
		if(ymax>p[i].y)
		{
			ymax=p[i].y;
		}
	}
}

int main()
{
	int c1;
	initwindow(500,600);
	cleardevice();
	polygon obj;
	obj.read();
	obj.calcs();
	cleardevice();
	cout<<"enter the color you want (0-15) : ";
	cin>>c1;
	setcolor(c1);
	obj.display();
	closegraph();
	getch();
	return 0;
}
