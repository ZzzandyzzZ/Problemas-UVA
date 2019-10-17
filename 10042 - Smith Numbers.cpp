#include <iostream>
#include <cmath>
using namespace std;
bool esprimo(int a){
    for (int i=2;i<=sqrt(a);i++){
        if(a%i==0){
            return false;
        }
    }
    return true;

}
int suma(int a){
    int aux=0;
    while(a>9){
        aux+=a%10;
        a/=10;
    }
    aux+=a;
    return aux;
}
int division(int t){
    if(esprimo(t)){return suma(t);}
    for(int i=2;i<=t;i++){
        if(t%i==0 && esprimo(i)){
            //cout<<i<<endl;
            return suma(i) + division(t/i);
        }
    }
}
int main(){
    long N;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>N;
        N++;
        while(true){
            if(!esprimo(N)&&division(N)==suma(N)){
                cout<<N<<endl;
                break;
            }
            N++;
        }

    }
}
