//12503 Robot Instructions
#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int t,n,cas,P;
    string a;
    vector<int> lista;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        P=0;
        while(n--){
            cin>>a;
            if(a=="LEFT"){
                P--;
                lista.push_back(-1);
            }
            else if(a=="RIGHT"){
                P++;
                lista.push_back(1);
            }
            else if(a=="SAME"){
                cin>>a;
                scanf("%d",&cas);
                lista.push_back(lista[cas-1]);
                P+=lista[cas-1];
            }
        }
        printf("%d\n",P);
        lista.clear();

    }



}
