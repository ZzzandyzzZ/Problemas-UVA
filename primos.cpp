#include <iostream>
#include <cmath>
using namespace std;
bool esprimo(int a){
    if(a==1)return false;
    for(int i=2;i<=sqrt(a);i++)
        if(a%i==0)return false;
    return true;
}
int main(){
    int L,U,aux=0,aux2=0;
    int c1,c2,d1,d2;
    int con=0;
    while(cin>>L>>U){
        con=0;
        aux=0;aux2=0;
        if(L==2&&U==3){
            cout<<2<<","<<3<<" are closest, "<<2<<","<<3<<" are most distant."<<endl;
        }
        else if(L==U||U-L==1){
            cout<<"There are no adjacent primes."<<endl;
        }
        else{
       for(int i=L;i<=U;i++){
            if(esprimo(i)&&con==0){
                c1=i;
                con++;
            }
            else if(esprimo(i)&&con==1){
                c2=i;
                d1=i;
                aux=d1;
                con++;
            }
            else if(esprimo(i)){
                if(con==2){d2=i,aux2=d2,con++;}
                else if((d2-d1)<(i-aux2)){
                    d1=aux2;
                    d2=i;
                    aux=d1;
                    aux2=d2;
                }
                else if((d2-d1)==(i-d2)){
                    aux=aux2;
                    aux2=i;

                }
                else{
                    aux=aux2;
                    aux2=i;
                }
            }
            //cout<<i<<":"<<c1<<" "<<c2<<" "<<aux<<" "<<aux2<<" "<<d1<<" "<<d2<<endl;

        }
        if(con<=1){
            cout<<"There are no adjacent primes."<<endl;
        }else{
            cout<<c1<<","<<c2<<" are closest, "<<d1<<","<<d2<<" are most distant."<<endl;
        }

    }
    }
}
