//893   Y3K Problem
#include <bits/stdc++.h>
using namespace std;
vector<int> v(12);

bool bis(int a){
    return ( a % 4 == 0 ? 1 : 0 ) && a % 100 != 0 ? 1 : ( a % 400 == 0 ) ? 1 : 0;
}
int main(){
    int n,D,M,Y;
    v[0]=31;v[1]=28;v[2]=31;v[3]=30;v[4]=31;v[5]=30;
    v[6]=31;v[7]=31;v[8]=30;v[9]=31;v[10]=30;v[11]=31;
    while(scanf("%d %d %d %d",&n,&D,&M,&Y)){
        if(n==0&&D==0&&M==0&&Y==0)break;
        while(n>0){
            bis(Y) ? v[1]=29:v[1]=28;
            if(n>=365){
                if(M>2&&bis(Y+1)){
                    n-=366;
                }
                else if(M<=2&&bis(Y)){
                    n-=366;
                }
                else n-=365;
                Y++;
                continue;
            }

            if(D+n>v[M-1]){
                n+=D;
                n-=v[M-1];
                M++;
                D=0;
            }
            else{
                D+=n;
                n=0;
            }
            if(M>12){
                M=1;Y++;
            }
            //printf("%d %d %d %d\n",n,D,M,Y);
        }
        printf("%d %d %d\n",D,M,Y);
    }
    
}