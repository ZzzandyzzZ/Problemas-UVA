#include <iostream>
#include <string>

using namespace std;
int main(){
    int N;
    string cas;
    cin>>N;
    for(int i =0;i<N;i++){
        string aux="";
        cin>>cas;
        for(int j=0;j<cas.size();j+=2){
            for(int h=cas[j+1]-48;h>0;h--){
                aux+=cas[j];
            }

        }
        cout<<"Case "<<i+1<<": "<<aux<<endl;

    }



}
