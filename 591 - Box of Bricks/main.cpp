#include <iostream>

using namespace std;

int main()
{
    int b[51]={},s=0,c=0,n,se=1;
    while(cin>>n){
        if(n==0){break;}
        cin>>b[0];
        s=b[0];
        for(int i=1;i<n;i++){
            cin>>b[i];
            s+=b[i];
        }
        s/=n;
        for(int i=0;i<n;i++){
            if(b[i]-s<0){c+=b[i]-s;}
        }
        cout<<"Set #"<<se<<endl;se++;
        cout<<"The minimum number of moves is "<<-c<<"."<<endl;
        cout<<endl;
        s=0;c=0;
    }
    return 0;
}
