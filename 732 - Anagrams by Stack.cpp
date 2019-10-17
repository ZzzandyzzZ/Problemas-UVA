//732 - Anagrams by Stack
#include <bits/stdc++.h>

using namespace std;

string w1,w2;
int size;
stack<char> pil;
void secuencias(char op,int i,int o,string cad,stack<char> pila,string se){
    //cout<<i<<" "<<o<<" "<<cad<<endl;
    if(i>size||o>size||o>i)return;
    //if(op=='o'&&pila.empty())return;
    if(op=='i'){
        pila.push(w1[i-1]);
    }
    else{
        cad+=pila.top();
        pila.pop();
        if(w2.substr(0,o)!=cad){
         
            return;
        }
    }
    if(cad.size()==size&&cad==w2){
        //cout<<cad<<endl;
        cout<<se<<endl;
        return;
    }
    secuencias('i',i+1,o,cad,pila,se+" i");
    secuencias('o',i,o+1,cad,pila,se+" o");
}
int main(){
    
    while(cin>>w1){
        cin>>w2;
        size=w1.size();
        
        cout<<"["<<endl;
        if(size==w2.size())
            secuencias('i',1,0,"",pil,"i");
        cout<<"]"<<endl;
        
    }

}