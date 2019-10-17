#include <iostream>
#include<algorithm>
using namespace std;
int ciclo(int x);

int main()
{
    int p,u,c=0;
    int ma =0,b;
    while(cin>>p,cin>>u){
        if (u<p){swap(u,p);c++;}
        for(int i=p;i<=u;i++){
            b =ciclo(i);
            if(b>ma){ma=b;}
        }
        if(c>0){swap(u,p);}
        cout<<p<<" "<<u<<" "<<ma<<endl;
        ma=0;c=0;
    }
    return 0;
}
int ciclo(int x){
    if (x==1){return 1;}
    else if (x%2!=0){return 1+ciclo(3*x+1);}
    else{return 1+ ciclo(x/2);}
}
