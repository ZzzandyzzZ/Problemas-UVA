#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

int main(){
    string cad;
    int T[8][8]={0};
    int j=0;
    getline(cin,cad);
    for(int i=0;i<cad.size();i++){
        cout<<cad[i]<<endl;
        if(isdigit(cad[i])){
            j+=(int)cad[i]-'0'-1;
        }
        else if(islower(cad[i])){

        }
        else{

        }
    }

}
