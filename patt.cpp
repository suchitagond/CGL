#include<iostream>
#include<graphics.h>

void l(int x1,int y1,int x2,int y2){
    int dx=x2-x1,dy=y2-y1,steps;
    float xinc,yinc,x=x1,y=y1;
    if(abs(dx)>=abs(dy)){
        steps=dx;
    }
    else{
        steps=dy;
    }
    xinc=float (dx/steps);
    yinc=float (dy/steps);

    for(int i=0;i<steps;i++){
        putpixel(round(x),round(y),WHITE);
        x+=xinc;
        y+=yinc;
    }
}
void circle(int xc,int yc,int x,int y){
    putpixel(xc+x,yc+y,WHITE);
    putpixel(xc-x,yc+y,WHITE);
    putpixel(xc+x,yc-y,WHITE);
    putpixel(xc-x,yc-y,WHITE);
    putpixel(xc+y,yc+x,WHITE);
    putpixel(xc-y,yc+x,WHITE);
    putpixel(xc+y,yc-x,WHITE);
    putpixel(xc-y,yc-x,WHITE);
}
void c(int xc,int yc,int r){
    int x=0 ,y=r,D=3-2*r;
    while(x<=y){
        circle(xc,yc,x,y);
        x++;
        if(D<0){
            D=D+4*x+6;
        }
        else{
            y--;
            D=D+4*(x-y)+10;
        }
    }
}

int main(){
    int gd=DETECT,gm;
    initgraph(&gd,&gm,NULL);

    int x1=80,y1=70,x2=160,y2=150;
    l(x1,y1,x2,y1);
    l(x2,y1,x2,y2);
    l(x2,y2,x1,y2);
    l(x1,y2,x1,y1);

    l((x1+x2)/2,y1,x2,(y1+y2)/2);
    l(x2,(y1+y2)/2,(x1+x2)/2,y2);
    l((x1+x2)/2,y2,x1,(y1+y2)/2);
    l(x1,(y1+y2)/2,(x1+x2)/2,y1);

    int xc = 100, yc = 200, r = 20;
    c(xc, yc, r);
    
    delay(1000);
    closegraph();
}