//11242 Tour de France

#include <bits/stdc++.h>

using namespace std;


int main(){
    int n,m;
    double ma,temp;
    vector<int> N,M;
    priority_queue<double> P;
    while(cin>>m>>n){
        if(n==0)return 0;
        N.resize(n);
        M.resize(m);
        for(int i=0;i<m;i++)cin>>M[i];
        for(int i=0;i<n;i++)cin>>N[i];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                P.push(double(N[i])/M[j]);
            }
        }
        /*
        while(!P.empty()){
            cout<<P.top()<<endl;
            P.pop();
        }
        */
        temp=P.top();
        P.pop();
        ma=temp/P.top();
        while(!P.empty()){
            temp=P.top();
            P.pop();
            if(temp/P.top()>ma)ma=temp/P.top();
        }
        printf("%.2f\n",ma);
    }



}
