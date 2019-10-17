#include <iostream>
#include <string>
using namespace std;

string invertir(string cad){
    string aux;
    for(int i=cad.size()-1;i>=0;i--){
        aux+=cad[i];
    }
    return aux;

}

int main(){
    string cad;
    string inv="";
    string aux="";
    while(getline(cin, cad)){
        inv="";aux="";
        for(int i=0;i<cad.size();i++){
            if(cad[i]==' '){inv+=cad[i];}
            else if(cad[i+1]=='b'){
                aux+=cad[i];
                inv+=invertir(aux);
                aux="";
            }
            else if(i==cad.size()-1){aux+=cad[i];inv+=invertir(aux);}
            else{aux+=cad[i];}

        }
        if(inv[cad.size()-1]!=' '){inv+=" ";}
        cout<<inv<<endl;
    }
    return 0;
}
