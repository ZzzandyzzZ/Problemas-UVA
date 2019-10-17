#include <iostream>
#include <string>
using namespace std;

int main(){
    string cad;
    bool pal=false;
    int con =0;
    while(getline(cin,cad)){
        con=0;
        for(int i=0;i<cad.size();i++){
            if((cad[i]>='A' && cad[i]<='Z')||(cad[i]>='a' && cad[i]<='z')){
                if(pal==false){pal=true;con++;}
            }
            else{pal=false;}
        }
        cout<<con<<endl;

    }
    return 0;


}
