#include <iostream>
#include <graphics.h>
using namespace std;
int LEFT = 1, RIGHT = 2, bottom = 4, top = 8, xmin, xmax, ymin, ymax;
int getcode(int x, int y)
{
    int code = 0;
    if (y > ymax)
    {
        code |= bottom;
    }
    if (y < ymin)
    {
        code |= top;
    }
    if (x < xmin)
    {
        code |= LEFT;
    }
    if (x > xmax)
    {
        code |= RIGHT;
    }
    return code;
}
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    int x1, y1, x2, y2;
    cout << "enter top left and bottom right co-ordinates of window : ";
    cin >> xmin >> ymin >> xmax >> ymax;
    cout << "enter end points of line : ";
    cin >> x1 >> y1 >> x2 >> y2;
    setcolor(WHITE);
    cout << "before clipping : " << endl;
    rectangle(xmin, ymin, xmax, ymax);
    line(x1, y1, x2, y2);
    delay(10000);

    int a = 0;
    int outcode1 = getcode(x1, y1);
    int outcode2 = getcode(x2, y2);
    while (true)
    {
        float m = float(y2 - y1) / (x2 - x1);
        int x, y;
        if (outcode1 == 0 && outcode2 == 0)
        {
            a = 1;
            break;
        }
        else if ((outcode1 & outcode2) != 0)
        {
            break;
        }
        else
        {
            int temp;
            if (outcode1 == 0)
            {
                temp = outcode2;
            }
            else
            {
                temp = outcode1;
            }
            if (temp & top)
            {
                x = x1 + (ymin - y1) / m;
                y = ymin;
            }
            else if (temp & bottom)
            {
                x = x1 + (ymax - y1) / m;
                y = ymax;
            }
            else if (temp & LEFT)
            {
                x = xmin;
                y = y1 + m * (xmin - x1);
            }
            else if (temp & RIGHT)
            {
                x = xmax;
                y = y1 + m * (xmax - x1);
            }
            if (temp == outcode1){
                x1=x;
                y1=y;
                outcode1=getcode(x1,y1);
            }
            else{
                x2=x;
                y2=y;
                outcode2=getcode(x2,y2);
            }
        }
    }
    setcolor(YELLOW);
    if(a==1){
        rectangle(xmin,ymin,xmax,ymax);
        line(x1,y1,x2,y2);
        delay(10000);
    }
    else{
        rectangle(xmin,ymin,xmax,ymax);
        delay(10000);
    }
    closegraph();
}