#include <iostream>

using namespace std;

int main()
{
    int t,num,ma,co=1;
    string letra,lis[10]={};
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>letra;cin>>num;
        lis[0]=letra;
        ma = num;
        for(int j=0;j<9;j++){
            cin>>letra;cin>>num;
            if (ma<num){ma=num;lis[0]=letra;co=1;}
            else if(ma==num){lis[co]=letra;co++;}
        }
        cout<<"Case #"<<i+1<<":"<<endl;
        for(int i=0;i<co;i++){
            cout<<lis[i]<<endl;}
        co=1;
        }




    return 0;
}
