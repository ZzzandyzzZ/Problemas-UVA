

#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
vector <int> p(200000,1);
bool primo(int a){
    for(int i=2;i<=sqrt(a);i++){
        if(a%i==0){return false;}
    }
    return true;
}
void Nprimos(int a){
    int con=0;
    int i=7;
    while(con<a){
        if(primo(i)){p[con]=i;con++;}
        i++;
    }
}
bool feo(int a){
    for(int i=0;p[i]<=a;i++){
        if(a%p[i]==0){return false;}
    }
    return true;
}
void mostrar(vector<int> p){
    for(int i=0;i<p.size();i++){
        cout<<p[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int con=2;
    int se=2;
    int rpta=0;
    int aux=0;
    Nprimos(200000);
    while(con<1501){
        aux=se;
        if(se%2==0){while(se%2==0)se/=2;}
        if(se%3==0){while(se%3==0)se/=3;}
        if(se%5==0){while(se%5==0)se/=5;}
        if(feo(se)){con++;rpta=aux;se=aux+1;cout<<rpta<<endl;}
        else{se=aux+1;}

    }
    cout<<"A "<<con<<endl;
    return 0;
}
