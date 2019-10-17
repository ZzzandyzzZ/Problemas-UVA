#include <iostream>
#include <string.h>
#include <ctype.h> //<---aqui se encuentran las funciones toupper y tolower
using namespace std;

int invertir(string cadena){
    string aux_cadena ="";
    string cadena2="";
    int tam =cadena.size();
    for (int i = tam-1; i >=0 ; i--){
        if(cadena[i]==' '||cadena[i]=='.'||cadena[i]==','||cadena[i]=='?'|| cadena[i]=='!'){continue;}
        aux_cadena += tolower(cadena[i]);
        }
    for (int i = 0; i<tam ; i++){
        if(cadena[i]==' '||cadena[i]=='.'||cadena[i]==','||cadena[i]=='?'|| cadena[i]=='!'){continue;}
        cadena2 +=tolower(cadena[i]);
    }
    if(cadena2==aux_cadena){return 1;}
    return 0;
}
int main(){
    char p[50];
    while (cin.getline(p,50)){
        if(p[0]=='D' &&p[1]=='O' && p[2]=='N'&&p[3]=='E'){break;}
        if (invertir(p)==1){
            cout<<"You won't be eaten!"<<endl;
        }
        else{cout<<"Uh oh.."<<endl;}

    }
    return 0;

}
