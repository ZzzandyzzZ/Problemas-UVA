#include <iostream>
#include <string>
#include <queue>
using namespace std;

queue <int> d;
void divisores(int tam){
    for(int i=1;i<=tam/2;i++){
        if(tam%i==0){d.push(i);}}
    d.push(tam);
}
void mostrar(){
    while(!d.empty()){
        cout<<d.front()<<endl;
        d.pop();
    }
}
void limpiar(){
    while(!d.empty()){
        d.pop();
    }
}
int Nperiods(string cad){
    bool com = true;
    while(!d.empty()){
        //cout<<"------"<<endl;
        int div = d.front();
        string aux = cad.substr(0,div);
        //cout<<div<<endl;
        //cout<<aux<<endl;
        com=true;
        for(int i=0;i<cad.size()/div;i++){
            //cout<<cad.substr(i*div,div)<<endl;
            if(aux!= cad.substr(i*div,div)){
                com=false;
                break;}
        }

        if(com==true){limpiar();return div;}
        d.pop();
    }
}
int main(){

    string cad;
    int n;
    cin>>n;
    for(int i =0;i<n;i++){
        cin>>cad;
        divisores(cad.size());
        //mostrar();
        cout<<Nperiods(cad)<<endl;
        if(i!=n-1){cout<<endl;}


    }
}
