#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string cadena;

    int com = 0,com2=0,com3=0,com4=0;
    while(getline(cin,cadena)){
        string aux(cadena.begin(), cadena.end());
        reverse(aux.begin(), aux.end());
        for(int i =0; i <=cadena.size()-1 ; i++){
            if(cadena[i]=='0'){break;}
            if (cadena[i] ==aux[i]){
                if(cadena[i]=='A'||cadena[i]=='M'||cadena[i]=='H'||cadena[i]=='I'||cadena[i]=='O'||cadena[i]=='T'||cadena[i]=='U'||cadena[i]=='V'||cadena[i]=='W'||cadena[i]=='X'||cadena[i]=='Y'||cadena[i]=='1'||cadena[i]=='8'){com++;}
                else{com4++;}
            }
            else if((cadena[i]=='E'&& aux[i]=='3')||(cadena[i]=='3'&& aux[i]=='E')||(cadena[i]=='J'&& aux[i]=='L')||(cadena[i]=='L'&& aux[i]=='J')||(cadena[i]=='2'&& aux[i]=='S')||(cadena[i]=='S'&& aux[i]=='2')||(cadena[i]=='5'&& aux[i]=='Z')||(cadena[i]=='Z'&& aux[i]=='5')){com2++;}
            else{com3++;}


        }
        if (com3>=1){cout<<cadena<<" -- is not a palindrome."<<endl;}
        else if ((com>=1 || com4>=1)&& com2==0 ){cout<<cadena<<" -- is a regular palindrome."<<endl;}
        else if((com2>=1 || com>=1) && com4==0){cout<<cadena<<" -- is a mirrored palindrome."<<endl;}
        else if(com2>=1&& com>=1 && com4 ==0){ cout<<cadena<<" -- is a mirrored string."<<endl;}
        com =0;com2=com3=com4=com;
    }

    return 0;
}
