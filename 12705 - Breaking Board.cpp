#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> defecto(36,0);
void mostrar(vector<int>&tabla){
    for(int i=0;i<91;i++){
        //cout<<i<<"("<<tabla[i]<<")"<<" ";
        cout<<tabla[i]<<" ";
    }
    cout<<endl;

}
bool ord(int i,int j){return i>j;}
void crear(){
    int co=0;
    for(int i=2;i<=7;i++){
        for(int j=1;j<=i-1;j++){
            defecto[co]=i;
            co++;}
    }
    for(int i=8;i<=12;i++){
        for(int j=12;j-i+1>0;j--){
            defecto[co]=i;
            co++;}
    }
}
int minimo(vector<int>&tabla,string b){
    int to=0;
    for(int i=0;i<b.size();i++){
        if(b[i]==' '){continue;}
        tabla[int(b[i])]++;
    }
    sort(tabla.begin(),tabla.end(),ord);
    for(int i=0;i<=36;i++){
        to+=(tabla[i]*defecto[i]);
    }
    return to;

}

int main(){
    int T;
    string L;
    cin>>T;
    cin.ignore();
    crear();
    for(int i=0;i<T;i++){
        vector<int> tabla(91,0);
        getline(cin,L);
        cout<<minimo(tabla,L)<<endl;
    }
    return 0;
}
