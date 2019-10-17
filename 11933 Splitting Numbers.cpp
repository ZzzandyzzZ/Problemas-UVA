#include <iostream>

using namespace std;
int main(){
    int n,a,b;
    int pos,aux;
    while(cin>>n,n!=0){
        pos=a=b=0;
        aux=1;
        while(n!=0){
            if(n&1==1){
                if(pos&1){
                    a=a|aux;
                }else{
                    b=b|aux;
                }
                pos++;
            }
            aux=aux<<1;
            n=n>>1;

        }
        cout<<b<<" "<<a<<endl;
    }
}

