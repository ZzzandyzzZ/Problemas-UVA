#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    string T;
    cin>>n;

    //char abcd[28]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','ñ','o','p','q','r','s','t','u','v','w','x','y','z'};

    for (int j =0;j<n;j++){
        cin>>T;
        int tam=T.size();
        int co=1,aux=1;
        char p='*',s='*',com=T[0];

        vector <int> abc(123,0);
        abc[T[0]]++;
        for (int i =0;i<tam;i++){
            if(T[i]!='?'){
                if(T[i]!=com){com=T[i],abc[T[i]]++;}
                if(abc[T[i]]>=2){co=0;break;}
            }
            if(T[i]=='?' && T[0]!='?'){aux++;}
            if(T[i]!='?' && T[i+1]=='?' && T[i-1]!='?'){p=T[i];}
            if(T[i]!='?' && T[i+1]!='?' && T[i-1]=='?'){s=T[i];
                if(T[0]=='?'){co+=0;T[0]='*';}
                else {if(p==s){co+=0;}
                else {co*=aux;}
                aux=1;
                }}
        }
        cout<<co<<endl;
    }
    return 0;
}
