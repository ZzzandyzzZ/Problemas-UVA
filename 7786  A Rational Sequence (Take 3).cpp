//7786  A Rational Sequence (Take 3)

#include <bits/stdc++.h>

using namespace std;

int main(){
    int P,k;
    vector<bool> v;
    int long long N,a,b;
    cin>>P;
    while(P--){
        scanf("%d %lld",&k,&N);
        v.clear();
        a=b=1;
        while(N!=1){
          //  cout<<N<<endl;
            if(N%2==0){
                v.push_back(1);
            }
            else v.push_back(0);
            N=N/2;
        }
        if(v.size()!=0)
            for(int i=v.size()-1;i>=0;i--){
                //cout<<v[i]<<endl;
                if(v[i]){
                    b=a+b;
                }
                else{
                    a=a+b;
                }
               // printf("%d %lld/%lld\n",k,a,b);
            }
        printf("%d %lld/%lld\n",k,a,b);
    }
}