#include <iostream>
#include<vector>
using namespace std;

int L(int x){return 2*x+1;}
int R(int x){return 2*x+2;}
vector <int> V(1000000);
vector <int> T(4000000);
int filltree(int n,int i , int j){
    if(i==j){
        T[n]=V[i];
        return V[i];
    }
    int m =(i+j)/2;
    int hl = filltree(L(n),i,m);
    int hr = filltree(R(n),m+1,j);
    T[n]=hl*hr;
    return T[n];
}
int cambiar(int n,int i,int j,int p,int c){
    if (i==j && i==p){
        T[n]=c;
        return T[n];}
    if(i<=p && p<=j ){
    int m =(i+j)/2;
    int hl = cambiar(L(n),i,m,p,c);
    int hr = cambiar(R(n),m+1,j,p,c);
    T[n]=hl*hr;
    return T[n];}
    return 1;

}
int consulta(int n,int i,int j,int l,int r){
    if(r<i || l>j)return 1;
    if(i<=l && j<=r)return T[n];
    int m =(i+j)/2;
    int hl = consulta(L(n),i,m,l,r);
    int hr = consulta(R(n),m+1,j,l,r);
    return hl*hr;

}
int main()
{
    int N,K,a,b,con=0;
    char CP;

    while(cin>>N,N!=0){
        cin>>K;
        con=0;
        V.clear();
        T.clear();
        for(int i =0;i<N;i++){
            cin>>V[i];con++;
        }
        filltree(0,0,con-1);
        mostrar(4*con);
        for(int i =0;i<K;i++){
            cin>>CP;
            if(CP=='C'){cin>>a>>b;cambiar(0,0,con-1,a-1,b);mostrar(4*con);}
            if(CP=='P'){cin>>a>>b;cout<<consulta(0,0,con-1,a-1,b-1)<<endl;}
        }
    }
    return 0;
}
