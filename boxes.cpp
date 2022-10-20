#include<iostream>
#include<math.h>
#include<graphics.h>
using namespace std;

void lambada(int x1,int y1,int x2,int y2)
{
    int dx=x2-x1,dy=y2-y1,steps;
    float xinc,yinc,x=x1,y=y1;

    if (abs(dx)>abs(dy))
        steps=abs(dx);
    else
        steps=abs(dy);

    xinc=float(dx)/steps;
    yinc=float(dy)/steps;

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

    int x1=80,y1=70,x2=160,y2=150;
    // cout<<"enter the coordinates: ";
    // cin>>x1;
    // cin>>y1;
    // cin>>x2;
    // cin>>y2;

    lambada(x1,y1,x2,y1);
    lambada(x2,y1,x2,y2);
    lambada(x2,y2,x1,y2);
    lambada(x1,y2,x1,y1);

    lambada((x1+x2)/2,y1,x2,(y1+y2)/2);
    lambada(x2,(y1+y2)/2,(x1+x2)/2,y2);
    lambada((x1+x2)/2,y2,x1,(y1+y2)/2);
    lambada(x1,(y1+y2)/2,(x1+x2)/2,y1);

    lambada((3*x1+x2)/4,(3*y1+y2)/4,(3*x2+x1)/4,(3*y1+y2)/4);
    lambada((3*x2+x1)/4,(3*y1+y2)/4,(3*x2+x1)/4,(3*y2+y1)/4);
    lambada((3*x2+x1)/4,(3*y2+y1)/4,(3*x1+x2)/4,(3*y2+y1)/4);
    lambada((3*x1+x2)/4,(3*y2+y1)/4,(3*x1+x2)/4,(3*y1+y2)/4);

    delay(1000);
    closegraph();
    return 0;
}
