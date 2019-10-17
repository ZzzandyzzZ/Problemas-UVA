#include <iostream>

using namespace std;

int main()
{
    int t,n,indi[105]={},co=0,num;
    string in,aux;
    cin>>t;
    for (int i=0;i<t;i++){
        cin>>n;
        for(int j=1;j<n+1;j++){
            cin>>in;
            if(in=="SAME"){
                cin>>aux;cin>>num;
                co+=indi[num];
                indi[j]=indi[num];
            }
            else if(in=="LEFT"){co+=-1;indi[j]=-1;}
            else if(in=="RIGHT"){co+=1;indi[j]=+1;}
        }
        cout<<co<<endl;
        co=0;



    }
    return 0;
}
