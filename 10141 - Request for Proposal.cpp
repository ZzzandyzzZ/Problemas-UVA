#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

vector <string> Req(1000);
int casos =1;
struct prop{
    string N;
    float d;
    float RFP;
};
bool operator <(prop a,prop b){
    return a.RFP < b.RFP;
}
priority_queue <prop> Prop;
bool buscar(int n,string prop){
    for(int i=0;i<n;i++){
        if(Req[i]==prop){return true;}
    }
    return false;
}
void mostrar(){
    prop aux= Prop.top();
    cout<<aux.N<<"-"<<aux.d<<"-"<<aux.RFP<<endl;

}
void mostrarP(){
    while(!Prop.empty()){
        mostrar();
        Prop.pop();
    }
}

void limpiar(){
    while(!Prop.empty()){
        Prop.pop();
    }

}

void barato(int Nm,prop auxP){
    int N=0;
    float maxi;
    prop aux;
    for(int i=0;i<Nm;i++){
        if(i==0){aux=Prop.top();maxi=Prop.top().d;Prop.pop();N++;}
        else if(maxi==Prop.top().d){N++;Prop.pop();}
        else if(maxi>Prop.top().d){aux=Prop.top();maxi=Prop.top().d;N=1;Prop.pop();}

    }
    if(N>1){
        cout<<"RFP #"<<casos<<endl;
        cout<<auxP.N<<endl;
        casos++;
    }
    else{
        cout<<"RFP #"<<casos<<endl;
        cout<<aux.N<<endl;
        casos++;
    }

}
int main(){
    int n,r,Nm;
    float p,d,maxi=0;
    string N,pro;
    prop cas,auxP;
    while(cin>>n>>p){
        if(n==0||p==0){break;}
        Nm=maxi=0;
        cin.ignore();
        for(int i =0;i<n;i++){
            getline(cin,Req[i]);}
        for(int i =0;i<p;i++){
            cin>>N;
            cin>>d>>r;
            float aux=r;
            cin.ignore();
            for(int j=0;j<r;j++){
                getline(cin,pro);
                if(buscar(n,pro)==false){aux--;}
            }

            cas.N=N; cas.d=d;cas.RFP=aux/p;
            Prop.push(cas);
            if(maxi==0){auxP=cas;maxi=cas.RFP;Nm++;}
            else if(maxi==cas.RFP){Nm++;}
            else if(maxi<cas.RFP){auxP=cas;maxi=cas.RFP;Nm=1;}
        }
        
        if(Nm==1){
            cout<<"RFP #"<<casos<<endl;
            cout<<Prop.top().N<<endl;
            casos++;}
        else{
            barato(Nm,auxP);
        }
        //cout<<maxi<<"-"<<Nm<<"-"<<endl;
        limpiar();
    }

}
