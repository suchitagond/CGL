#include <iostream>
#include <graphics.h>
using namespace std;
int LEFT=1,RIGHT=2,BOTTOM=4,TOP=8,xmin,ymin,xmax,ymax;
int getcode(int x,int y){
    int code=0;
    if(y>ymax){
        code|=BOTTOM;
    }
    if(y<ymin){
        code|=TOP;
    }
    if(x>xmax){
        code|=RIGHT;
    }
    if(x<xmin){
        code|=LEFT;
    }
    return code;
}

int main(){
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int x1, y1, x2, y2;
    cout << "enter top left and bottom right co-ordinates of window : ";
    cin >> xmin >> ymin >> xmax >> ymax;
    cout << "enter end points of line : ";
    cin >> x1 >> y1 >> x2 >> y2;

    setcolor(WHITE);
    rectangle(xmin, ymin, xmax, ymax);
    line(x1, y1, x2, y2);
    delay(10000);

    
}