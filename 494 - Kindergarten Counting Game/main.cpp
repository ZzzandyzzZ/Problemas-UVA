
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string line;
    int con =0;
    while(getline(cin,line)){
        int tam = line.size();
        for(int i=0;i<tam;i++){
            if((line[i]>='A' && line[i]<='Z')||(line[i]>='a' && line[i]<='z')){
                              con++;
                              for(;(line[i]>='A' && line[i]<='Z')||(line[i]>='a' && line[i]<='z') && i<tam;i++){

                              }
            }

        }
    cout<<con<<endl;
    con=0;

    }
    return 0;
}



