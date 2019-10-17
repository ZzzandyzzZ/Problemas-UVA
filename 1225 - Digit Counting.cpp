//1225 - Digit Counting

#include <bits/stdc++.h>
using namespace std;
vector <int> dig(10);


void d(int i){
    while(i>9){

        dig[i%10]++;
        i/=10;
    }

    dig[i]++;

}
void digit(int n){
    for(int i=1;i<=n;i++){
        d(i);
    }
}

int main(){
    int cas,N;
    cin>>cas;
    while(cas--){
        dig.assign(10,0);
        cin>>N;
        digit(N);
        for(int i=0;i<10;i++){
            cout<<dig[i];
            if(i!=9)cout<<" ";
        }
        cout<<endl;
    }

}
