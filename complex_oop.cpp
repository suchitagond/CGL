#include<iostream>
using namespace std;

//take complex class
class complex
{
    public:
        int real, imaginary;

    //constructure
    complex(int tempreal=0,int tempimaginary=0)
    {
        real=tempreal;
        imaginary=tempimaginary;
    };

    //define addcomplex
    complex addcomplex(complex c1,complex c2)

    //define s variable
    {
        complex s;
        s.real=c1.real+c2.real;
        s.imaginary=c1.imaginary+c2.imaginary;
        return s;
    };
};

//main class
int main()
{
    //1st complex no.
    int x1,y1,x2,y2,x3,y3;

    cout<<"enter 1st complex real no : ";
    cin>>x1;
    cout<<"enter 1st complex imaginary no : ";
    cin>>y1;

    complex c1(x1,y1);
    cout<<"1st complex no. is "<<c1.real<<"+i"<<c1.imaginary<<"\n";
    cout<<"\n";

    //2nd complex NO.
    cout<<"enter 2st complex real no : ";
    cin>>x2;
    cout<<"enter 2st complex imaginary no : ";
    cin>>y2;

    complex c2(x2,y2);
    cout<<"2nd complex is "<<c2.real<<"+i"<<c2.imaginary<<"\n";
    cout<<"\n";

    //ADDITION
    complex c3;
    {
        c3=c3.addcomplex(c1,c2);
        cout<<"addition of complex is "<<c3.real<<"+i"<<c3.imaginary<<"\n";
        cout<<"\n";
    };

    //MULTIPLICATION:
    x3=(x1*x2)-(y1*y2);
    y3=(x1*y2)+(x2*y1);
    cout<<"multiplication of complex is "<<x3<<"+i"<<y3<<"\n";
};
