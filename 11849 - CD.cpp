//11849 - CD
#include <iostream>
#include <map>
using namespace std;

int main(){
    int N,M,aux,con=0;
    map<long,long> m;
    map<long,long> ::iterator it;
    while(cin>>N>>M,M!=0,N!=0){
        con=0;
        for(int i=0;i<N+M;i++){
            cin>>aux;
            it=m.find(aux);
            if(it==m.end()){
                m[aux]=1;
            }
            else{
                m[aux]++;
                con++;
            }



        }
        m.clear();
        cout<<con<<endl;
    }


}
