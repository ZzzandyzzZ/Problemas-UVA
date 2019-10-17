//10487 Closest Sums
#include <bits/stdc++.h>

using namespace std;
vector <int> lista(1000);



int main(){
    int n,m,mi,cas,aux,ncas=1;
    while(cin>>n,n!=0){
        cout<<"Case "<<ncas++<<":"<<endl;
        for(int i=0;i<n;i++){
            cin>>lista[i];
        }
        cin>>m;
        while(m--){
            cin>>cas;
            mi=999999999;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(i==j)continue;
                    aux=lista[i]+lista[j];
                    if(abs(cas-aux)<abs(cas-mi)){
                        mi=aux;
                    }
                    //cout<<abs(cas-aux)<<"*"<<abs(mi-aux)<<endl;
                    //cout<<mi<<endl;
                }
            }
            cout<<"Closest sum to "<<cas<<" is "<<mi<<"."<<endl;

        }
    }


}
