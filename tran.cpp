#include<iostream>
#include<graphics.h>
using namespace std;
void trans(float a[3][3]){
    float b[3][3],c[3][3];
    float tx,ty;
    cout<<"enter tx ty :";
    cin>>tx>>ty;
    b[2][0]=tx;
    b[2][1]=ty;
    b[0][0]=b[1][1]=b[2][2]=1;
    b[0][1]=b[0][2]=b[1][0]=b[1][2]=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            c[i][j]=0;
            for(int k=0;k<3;k++){
                c[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
    setcolor(WHITE);
    line(c[0][0],c[0][1],c[1][0],c[1][1]);
    line(c[1][0],c[1][1],c[2][0],c[2][1]);
    line(c[2][0],c[2][1],c[0][0],c[0][1]);
    delay(500);
}
void rot(float a[3][3]){
    float b[3][3],c[3][3];
    float A,R;
    cout<<"enter angle in thita ";
    cin>>A;
    R=(A*3.14)/180;
    b[0][0]=b[1][1]=(cos(R));
    b[0][1]=(sin(R));
    b[1][0]=(-sin(R));
    b[2][2]=1;
    b[0][2]=b[1][2]=b[2][0]=b[2][1]=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            c[i][j]=0;
            for(int k=0;k<3;k++){
                c[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
    setcolor(WHITE);
    line(c[0][0],c[0][1],c[1][0],c[1][1]);
    line(c[1][0],c[1][1],c[2][0],c[2][1]);
    line(c[2][0],c[2][1],c[0][0],c[0][1]);
    delay(500);
}
void sca(float a[3][3]){
    float b[3][3],c[3][3];
    float sx,sy;
    cout<<"enter sx sy :";
    cin>>sx>>sy;
    b[0][0]=sx;
    b[1][1]=sy;
    b[2][2]=1;
    b[0][1]=b[0][2]=b[1][0]=b[1][2]=b[2][0]=b[2][1]=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            c[i][j]=0;
            for(int k=0;k<3;k++){
                c[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
    setcolor(WHITE);
    line(c[0][0],c[0][1],c[1][0],c[1][1]);
    line(c[1][0],c[1][1],c[2][0],c[2][1]);
    line(c[2][0],c[2][1],c[0][0],c[0][1]);
    delay(500);
}
int main(){
    int gd=DETECT,gm;
    initgraph(&gd,&gm,NULL);
    float A[3][3];
    char ch1;
    int ch;
    cout<<"enter x1,y1 ";
    cin>>A[0][0]>>A[0][1];
    cout<<"enter x2,y2 ";
    cin>>A[1][0]>>A[1][1];
    cout<<"enter x3,y3 ";
    cin>>A[2][0]>>A[2][1];
    setcolor(YELLOW);
    line(A[0][0],A[0][1],A[1][0],A[1][1]);
    line(A[1][0],A[1][1],A[2][0],A[2][1]);
    line(A[2][0],A[2][1],A[0][0],A[0][1]);
    delay(500);
    do{
        cout<<" 1)translation of object\n2)scaling of object\n3)rotation of object "<<endl;
        cout<<"enter your choice : ";
        cin>>ch;
        switch(ch){
            case 1:
                trans(A);
                break;
            case 2:
                sca(A);
                break;
            case 3:
                rot(A);
                break;
        }
        cout<<"do you want to continue(y/n) : ";
        cin>>ch1;
    }while(ch1=='y'||ch1=='Y');
    closegraph();
}