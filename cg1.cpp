#include <iostream>
#include<graphics.h>
#include<math.h>
using namespace std;
int l = 1, r = 2, t = 8, b = 4;
    
int xmin = 100, ymin = 100;
int xmax = 300, ymax = 300;

int bitcode(int x, int y)
{
    int bcode = 0;
    if (x < xmin)
    {
        bcode = bcode | l;
    }
    if (x > xmax)
    {
        bcode = bcode | r;
    }
    if (y < ymin)
    {
        bcode = bcode | t;
    }
    if (y > ymax)
    {
        bcode = bcode | b;
    }
    return bcode;
}
int main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
   
    rectangle(xmin, ymin, xmax, ymax);

    int x1 = 50, y1 = 50;
    int x2 = 200, y2 = 200;
    line(x1, y1, x2, y2);
    
    int x,y,xx,yy,a,b,m;
	setcolor(RED);
    a = bitcode(x1, y1);
    b = bitcode(x2, y2);

    if (a == 0 & b == 0)
    {
    		
        line(x1, y1, x2, y2);
        cout << "line completely inside"<<endl;
    }
    else if ((a & b) == 0)
    {
        m = (y2 - y1) / (x2 - x1);
        cout<<"line partialy inside"<<endl;
        if (a != 0)
        {
            if (y1 < ymin)
            {
                x = x1 + (ymin - y1) / m;
                y = ymax;
            }
            if (y1 > ymax)
            {
                x = x1 + (ymax - y1) / m;
                y = ymax;
            }
            if (x1 < xmin)
            {
                y = y1 + (xmin - x1) * m;
                x = xmin;
            }
            if (x1 > xmax)
            {
                y = y1 + (xmax - x1) * m;
                x = xmax;
            }
        }
        else
        {
            x = x1;
            y = y1;
        }

        if (b != 0)
        {
            if (y2 < ymin)
            {
                xx = x2 + (ymin - y2) / m;
                yy = ymax;
            }
            if (y2 > ymax)
            {
                xx = x2 + (ymax - y2) / m;
                yy = ymax;
            }
            if (x2 < xmin)
            {
                yy = y2 + (xmin - x2) * m;
                xx = xmin;
            }
            if (x2 > xmax)
            {
                yy = y2 + (xmax - x2) * m;
                xx = xmax;
            }
        }
        else
        {
            xx = x2;
            yy = y2;
        }
        
        line(x, y, xx, yy);
    }
    delay(10000);
    return 0;

}
