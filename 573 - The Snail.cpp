#include <iostream>

using namespace std;

int main(){
    double T=0,H,U,D,F;
    int day=0;
    while(cin>>H>>U>>D>>F){
        if(H==0){break;}
            double Fl=F*U/100;
            day=T=0;
            while(T<=H){
                //cout<<H<<" "<<T<<" "<<U<<" "<<day<<endl;
                day++;
                if(U>=0){T+=U;}
                if(T>H){cout<<"success on day ";break;}
                T-=D;
                if(T<0){cout<<"failure on day ";break;}
                U-=Fl;
                }

            cout<<day<<endl;
            }


    }


