//12250 Language Detection

#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
int main(){
    string a;
    int con=1;
    while(cin>>a){
        if(a=="#")return 0;
        if(a=="HELLO")printf("Case %d: ENGLISH\n",con++);
        else if(a=="HOLA")printf("Case %d: SPANISH\n",con++);
        else if(a=="HALLO")printf("Case %d: GERMAN\n",con++);
        else if(a=="BONJOUR")printf("Case %d: FRENCH\n",con++);
        else if(a=="CIAO")printf("Case %d: ITALIAN\n",con++);
        else if(a=="ZDRAVSTVUJTE")printf("Case %d: RUSSIAN\n",con++);
        else printf("Case %d: UNKNOWN\n",con++);

    }


}
