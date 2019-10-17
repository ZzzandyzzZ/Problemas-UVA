#include<iostream>

using namespace std;


int main(){
    int R,N;
    int con=0;
    while(cin>>R>>N,R!=0,N!=0){
        int rpta=R/N;
        con++;
        if(R%N==0){
            rpta--;
        }
        if(rpta>=27){cout<<"Case "<<con<<": impossible"<<endl;}
        else{cout<<"Case "<<con<<": "<<rpta<<endl;}

    }
}
