#include<iostream>
#include<math.h>
#include<graphics.h>

using namespace std;

void book()
{
    
    for(int k=0;k<3;k++)
    {
        int x=10;
        int y=10;
        for(int i=0;i<25;i++)
        {
            cleardevice();
            rectangle(85,200,175,330);
            rectangle(175,200,265,330);
        
            floodfill(86,201,WHITE);
            if(265-x>175)
            {
                line(175,330,265-x,330+y);
                line(265-x,330+y,265-x,200+y);
                line(175,200,265-x,200+y);
                x=x+10;
                y=y+10;
                delay(300);
            }
        }
        for(int j=0;j<25;j++)
        {
            cleardevice();
            rectangle(85,200,175,330);
            rectangle(175,200,265,330);
            floodfill(264,201,BLUE);
    
            if(265-x>85)
            {
                line(175,200,265-x,200+y);
                line(175,330,265-x,330+y);
                line(265-x,330+y,265-x,200+y);
                x=x+10;
                y=y-10;
                delay(300);
            }
        }
    }
}
int main(){
    int gd=DETECT,gm;
    initgraph(&gd,&gm,NULL);

    book();
    delay(10000);
    closegraph();
    return 0 ;
}
