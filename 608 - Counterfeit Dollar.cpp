//608 - Counterfeit Dollar
#include <bits/stdc++.h>

using namespace std;
vector<int> L;
bool cou;
void marcar(string a,int b,int c){
    for(int j=0;j<a.size();j++){
        if(L[a[j]-'A']==0){
            if(cou)L[a[j]-'A']=1;
            else L[a[j]-'A']=b;
        }
        else if(L[a[j]-'A']==c){
            L[a[j]-'A']=1;
        }
    }
}
int main(){
    
    string a,b,c,aux;
    int n;
    scanf("%d",&n);
    while(n--){
        L.assign(15,0);
        cou=false;
        for(int i=0;i<3;i++){
            cin>>a>>b>>c;
            if(c=="even"){
                for(int j=0;j<a.size();j++){
                    L[a[j]-'A']=1;
                    L[b[j]-'A']=1;
                }
            }
            if(c=="up"){ 
                 marcar(a,2,3);marcar(b,3,2);
                if(cou){
                    aux=a+b;
                    for(int i=0;i<15;i++){
                        if(L[i]==0||L[i]==1)continue;
                        for(int j=0;j<aux.size();j++){
                            if(aux[j]==i+'A'){
                                break;
                            }
                            if(j==aux.size()-1)L[i]=1;
                        }
                    }
                 }
                
                cou=true;
            }
            if(c=="down"){
                marcar(a,3,2);marcar(b,2,3);
                if(cou){
                    aux=a+b;
                    for(int i=0;i<15;i++){
                        if(L[i]==0||L[i]==1)continue;
                        for(int j=0;j<aux.size();j++){
                            if(aux[j]==i+'A'){
                                break;
                            }
                            if(j==aux.size()-1)L[i]=1;
                        }
                    }
                 }
                cou=true;
            }
            
        }
        for(int i=0;i<15;i++){
            //cout<<L[i]<<" ";
            if(L[i]==3){
                printf("%c is the counterfeit coin and it is light.\n",i+'A');
            }
            else if(L[i]==2){
                printf("%c is the counterfeit coin and it is heavy.\n",i+'A');
            }
        }
    }
}