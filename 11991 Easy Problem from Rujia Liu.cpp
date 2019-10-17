#include <iostream>
#include <vector>
using namespace std;

int main(){
    int m,n,aux,con;
    int k,v;
    bool c=false;
    vector<vector<int> > l;
    while(cin>>m>>n){
    l.assign(1000000, vector<int>());
    for(int i=0;i<m;i++){
        cin>>aux;
        l[aux].push_back(i+1);
    }
    while(n--){
        cin>>k>>v;
        if(k>l[v].size()){cout<<"0"<<endl;}
        else{
            cout<<l[v][k-1]<<endl;
        }


    }

    }

}
