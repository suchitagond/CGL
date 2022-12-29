#include <iostream>
#include <graphics.h>
void man()
{
    int x, y;
    line(0, 500, getmaxx(), 500);

    for (int i = 0; i < getmaxx() - 180; i++)
    {
        cleardevice();
        rectangle(10 + i, 300, 50 + i, 400);
        line(20 + i, 400, 40 + i, 500);
        line(40 + i, 400, 20 + i, 500);

        line(10 + i, 300, 60 + i, 350);
        line(50 + i, 350, 60 + i, 330);

        line(60 + i, 330, 60 + i, 200);
        line(10 + i, 200, 110 + i, 200);

        circle(30 + i, 250, 50);
        arc(60 + i, 200, 180, 0, 50);
    }
    for(int j=0;j<50;j++){
        x=rand()%getmaxx();
        y=rand()%getmaxy();
        line(x,y,x+4,y+4);
    }
}
int main(){
    int gd=DETECT,gm;
    initgraph(&gd,&gm,NULL);
    man();
    delay(1000);
    closegraph();
}