#include <iostream>

using namespace std;

int main(){
    int T;
    int N;
    int cas;
    cin>>T;
    for(int i=1;i<=T;i++){
        cin>>N;
        int maxi;
        for(int j=0;j<N;j++){
            cin>>cas;
            if(j==0){maxi=cas;}
            else{
                if(maxi<cas){maxi=cas;}
            }


        }
        cout<<"Case "<<i<<": "<<maxi<<endl;

    }


}
