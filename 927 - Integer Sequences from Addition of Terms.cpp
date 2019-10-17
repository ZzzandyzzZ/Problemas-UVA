//927 - Integer Sequences from Addition of Terms
#include <bits/stdc++.h>

using namespace std;
vector <int> P;
int main(){
    int cas,d,k,n,g;
    long long total;
    cin>>cas;
    while(cas--){

        cin>>g;
        P.resize(g);
        n=1;
        total=0;
        for(int i=0;i<=g;i++)cin>>P[i];
        cin>>d;
        cin>>k;
        while(n*(n+1)/2*d<k){
            n++;
        }
        for(int i=0;i<=g;i++){
            total+=(P[i]*pow(n,i));
        }
        cout<<total<<endl;
    }
    return 0;

}
