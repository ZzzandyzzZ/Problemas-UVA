
#include <iostream>

using namespace std;

int main()
{
    int h,mi;
    double angulo,aux;
    char pts;
    cout.precision(3);
    cout.setf(ios::fixed, ios::floatfield);
    while (cin >> h>>pts>> mi){
        if (h ==0 && mi ==0){break;}
        angulo = 30.0*h -(11.0*mi/2.0);
        if (angulo<0){angulo *=-1.0;}
        if (angulo >180.0){cout<<360.0 -angulo<<endl;}
        else{cout<<angulo<<endl;}
    }
    return 0;
}
