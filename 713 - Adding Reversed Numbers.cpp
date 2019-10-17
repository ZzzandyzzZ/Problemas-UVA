//713 - Adding Reversed Numbers

#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,ac,sum,t1,t2,i;
    bool ini;
    string n1,n2,rpta;
    cin>>N;
    while(N--){
        cin>>n1>>n2;
        rpta="";
        ac=0;
        ini=false;
        if(n1.size()<n2.size())swap(n1,n2);
        t1=min(n1.size(),n2.size());
        t2=max(n1.size(),n2.size());
        for(i=0;i<t1;i++){
            sum=n1[i]+n2[i]-96+ac;
            if(sum>=10){ac=1;sum-=10;}
            else ac=0;
            if(sum!=0)ini=true;
            if(ini)rpta+=char(sum+48);
        }
        for(;i<t2;i++){
            sum=n1[i]+ac-48;
            if(sum>=10){ac=1;sum-=10;}
            else ac=0;
            if(sum!=0)ini=true;
            if(ini)rpta+=char(sum+48);
        }
        if(ac==1)rpta+='1';
        cout<<rpta<<endl;
    }



}