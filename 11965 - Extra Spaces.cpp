#include <iostream>
#include <string>
using namespace std;
void notspace(string cad){
    bool com =false;
    string aux="";
    for(int i =0;i<cad.size();i++){
        if(cad[i]==' '){
            if(com==false){com=true;}
            else if(com==true){continue;}
        }
        else {
            if(com==true){aux+=' ';aux+=cad[i];com=false;}
            else{aux+=cad[i];}
        }
    }
    cout<<aux<<endl;
}
int main(){
    string cad;
    int T,N;
    cin>>T;
    for(int i=1;i<=T;i++){
        if(i!=1){cout<<endl;}
        cin>>N;
        cin.ignore();
        cout<<"Case "<<i<<":"<<endl;
        for(int j=0;j<N;j++){
            getline(cin,cad);
            notspace(cad);
        }

    }
    return 0;
}
