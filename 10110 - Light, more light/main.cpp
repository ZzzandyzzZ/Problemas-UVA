#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    unsigned int n,aux;
    while(cin>>n){
        if (n==0){break;}
        aux =sqrt(n);
        if (aux*aux==n){cout<<"yes"<<endl;}
        else{cout<<"no"<<endl;}
    }
    return 0;
}
