#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
using namespace std;
void mostrar(vector <string> a){
    for(int i=0;i<5;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;


}
int main(){
    int N,ma,con;
    vector<string> aux(5);
    map<string,int> m;
    string tmp;
    while(cin>>N,N!=0){
        m.clear();
        for(int i=0;i<N;i++){
            tmp="";
            for(int j=0;j<5;j++){
                cin>>aux[j];
            }
            sort(aux.begin(),aux.begin()+5);

            for(int j=0;j<5;j++){
                tmp+=aux[j];
            }
            //cout<<tmp<<endl;
            m[tmp]++;

        }
        ma=0;
        con=0;
        for(map<string,int>::const_iterator it = m.begin();it != m.end(); ++it){
            if((it->second)>ma){ma=it->second;con=ma;}
            else if((it->second)==ma){con+=ma;}
            //cout<<it->first<<" "<<it->second<<endl;
        }

        cout<<con<<endl;
    }


}
