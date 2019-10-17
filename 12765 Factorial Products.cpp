#include <iostream>
#include <vector>
using namespace std;

void descomponer(vector <int>&a,int b){
    for(int i=2;i<=b;i++){
        if(i==4){a[2]+=2;}
        else if(i==6){a[2]++;a[3]++;}
        else if(i==8){a[2]+=3;}
        else if(i==9){a[3]+=2;}
        else{a[i]++;}
    }
}
bool comp(const vector <int>&a,const vector <int>&b){
    for(int i=2;i<=9;i++){
        if(a[i]!=b[i]){return false;}
    }
    return true;
}
void mostrar(vector <int> a){
    for(int i=0;i<10;i++){
        cout<<a[i]<<"-";
    }
    cout<<endl;

}
int main(){
    int n,m,aux;

    while(cin>>n>>m){
        if(n==0&&m==0){break;}
        vector<int> L1(10,0);
        vector<int> L2(10,0);
        for(int i=0;i<n;i++){
            cin>>aux;
            descomponer(L1,aux);

        }
        for(int i=0;i<m;i++){

            cin>>aux;
            descomponer(L2,aux);

        }
        if(comp(L1,L2)==true){
            cout<<"YES"<<endl;
        }
        else{cout<<"NO"<<endl;}
    }



}
