#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <cstdio>
using namespace std;
vector<vector<int> > re(101,vector<int>(4,0));
int equi,problem,time,casos,co=0;
string input;
char L;
void ingresar(){
    while(getline(cin,input)){
        if(input=="" && co>0) {break;}
        else{
        stringstream ss(input);
        ss>>equi; ss>>problem; ss>>time; ss>>L;
        if (L=='C'){re[co][0]=equi;re[co][1]=problem;re[co][2]=time;re[co][3]=1;co++;}
        else if (L=='I'){re[co][0]=equi;re[co][1]=problem;re[co][2]=0;re[co][3]=0;co++;}
        }
    }
}
void mostrar(){
    int aux=0;
    while(re[aux][0]!=0){
        cout<<re[aux][0]<<" "<<re[aux][1]<<" "<<re[aux][2]<<endl;
        aux++;
    }

}
void verificar(){
     for(int i=0;i<co;i++){
        if(re[i][3]==0){re[i][2]+=re[i][2]+20;}
        for(int j=1+i;j<co;j++){
            if(re[i][0]==re[j][0]){
                if(re[j][3]==0){re[i][2]+=20;}
                else if (re[j][3]==1){re[i][2]+=re[j][2];}
                re[j][0]=0;
            }

        }
     }

}
int main()
{
    while(cin>>casos){
        if(casos==0){break;}
        cout<<endl;
        for (int i=0;i<casos;i++){
            ingresar();
            verificar();
            mostrar();
            co=0;
            re.clear();
        }
    }
    return 0;
}
