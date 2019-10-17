//Count on Cantor

#include <bits/stdc++.h>

using namespace std;

int main(){
    long long N,num,den;
    while(scanf("%d",&N)!=EOF){
        double in=(1+sqrt(8*N+1))/2;
        den=in;
        if(!(den-in))den--;
        if(den&1){
            num=(den*(den+1))/2-N+1;
        }
        else{
            den--;
            num=N-(den*(den+1))/2;
            den++;
        }
        den=den-num+1;
        cout<<"TERM "<<N<<" IS "<<num<<"/"<<den<<endl;


    }

}
