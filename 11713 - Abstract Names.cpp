#include <iostream>
#include <string>
using namespace std;


bool yesno(string cas,string CAS){
    int tam = cas.size();
    int TAM = CAS.size();
    if(tam!=TAM){return false;}
    for(int i =0;i<tam;i++){
        if(cas[i]!='a'&&cas[i]!='e'&&cas[i]!='i'&&cas[i]!='o'&&cas[i]!='u'){
            if((cas[i]!=CAS[i])){return false;}

        }
        else{
            if(CAS[i]!='a'&&CAS[i]!='e'&&CAS[i]!='i'&&CAS[i]!='o'&&CAS[i]!='u'){return false;}
        }


    }
    return true;



}


int main(){
    int n;
    string cas,CAS;
    cin>>n;
    for(int i =0;i<n;i++){
        cin>>cas;
        cin>>CAS;
        if(yesno(cas,CAS)==true){cout<<"Yes"<<endl;}
        else{cout<<"No"<<endl;}

    }


}
