//12015 Google is Feeling Lucky
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
    int T,V,ma,total,cas=1;
    vector <string> lista(10);
    string pag;
    cin>>T;
    while(T--){
        total=0;
        cin>>pag>>V;
        ma=V;
        lista[total]=pag;
        for(int j=1;j<10;j++){
            cin>>pag>>V;
            if(ma>V){continue;}
            else if(ma<V){ma=V;total=0;}
            else if(ma==V){total++;}
            lista[total]=pag;

        }
        cout<<"Case #"<<cas++<<":"<<endl;
        for(int i=0;i<=total;i++){
            cout<<lista[i]<<endl;

        }

    }

}
