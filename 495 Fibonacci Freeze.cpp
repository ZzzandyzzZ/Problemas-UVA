#include<iostream>
#include<vector>

using namespace std;
vector<int> a;
vector<int> multi(vector<int> a,vector<int> b){
    vector<int> c;
    c.resize(4);
    c[0]=a[0]*b[0]+a[1]*b[2];
    c[1]=a[0]*b[1]+a[1]*b[3];
    c[2]=a[2]*b[0]+a[3]*b[2];
    c[3]=a[2]*b[1]+a[3]*b[3];
    //cout<<c[0]<<"-"<<c[1]<<"-"<<c[2]<<"-"<<c[3]<<endl;
    return c;
}
vector<int> potencia(vector<int> x, int y){
    if(y==1)return x;
    else{
        if(y%2==0){return potencia(multi(x,x),y/2);}
        return multi(x,potencia(multi(x,x),(y-1)/2));
    }
}
int fibonacci(int x){
    vector<int>aux=potencia(a,x);
    //cout<<aux[0]<<"-"<<aux[1]<<"-"<<aux[2]<<"-"<<aux[3]<<endl;
    return aux[1];
}

int main(){
    a.resize(4);
    a[0]=0;a[1]=1;
    a[2]=1;a[3]=1;
    int N;
    while(cin>>N){
        cout<<"The Fibonacci number for "<<N<<" is " <<fibonacci(N)<<endl;

    }

}
