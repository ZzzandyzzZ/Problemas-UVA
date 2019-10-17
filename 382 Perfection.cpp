#include <iostream>
#include <string>
using namespace std;
int divisores(int n){
    int co=1;
    for(int i=2;i<=n/2;i++){
        if(n%i==0){co+=i;}
    }
    return co;
}
void salida(int a){
    int aux=4;
    int salida[5]={10,10,10,10,10};
    while(a>0){
        salida[aux]=a%10;
        a/=10;
        aux--;
    }
    for(int i=0;i<5;i++){
        if(salida[i]==10){cout<<" ";}
        else{cout<<salida[i];}
    }

}
int main(){
    int N;
    cout<<"PERFECTION OUTPUT"<<endl;
    while(cin>>N,N!=0){
        int aux=divisores(N);
        salida(N);
        if(N>aux || N==1){cout<<"  DEFICIENT"<<endl;}
        else if(N==aux){cout<<"  PERFECT"<<endl;}
        else{cout<<"  ABUNDANT"<<endl;}
    }
    cout<<"END OF OUTPUT"<<endl;
}
