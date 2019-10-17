
#include<iostream>
#include<stdio.h>
#include<vector>
#include<math.h>
#include<queue>
using namespace std;
int G,G2,con=0;
void mostrar(vector<vector<pair<int,bool> > > &M,int fil,int col){
    for(int i=0;i<fil;i++){
        for(int j=0;j<col;j++){
            cout<<M[i][j].first;
        }
        cout<<endl;
    }

    cout<<endl;
}
void convertir(vector<vector<pair<int,bool> > > &M,string&linea,char num,int&co,int i,int j){

    if(linea[j]=='1'){M[i][co+3].first=1;co+=4;}
    else if(linea[j]=='2'){M[i][co+2].first=1;co+=4;}
    else if(linea[j]=='3'){M[i][co+2].first=1;M[i][co+3].first=1;co+=4;}
    else if(linea[j]=='4'){M[i][co+1].first=1;co+=4;}
    else if(linea[j]=='5'){M[i][co+1].first=1;M[i][co+3].first=1;co+=4;}
    else if(linea[j]=='6'){M[i][co+1].first=1;M[i][co+2].first=1;co+=4;}
    else if(linea[j]=='7'){M[i][co+1].first=1;M[i][co+2].first=1;M[i][co+3].first=1;co+=4;}
    else if(linea[j]=='8'){M[i][co].first=1;co+=4;}
    else if(linea[j]=='9'){M[i][co].first=1;M[i][co+2].first=0;M[i][co+3].first=1;co+=4;}
    else if(linea[j]=='a'){M[i][co].first=1;M[i][co+2].first=1;co+=4;}
    else if(linea[j]=='b'){M[i][co].first=1;M[i][co+2].first=1;M[i][co+3].first=1;co+=4;}
    else if(linea[j]=='c'){M[i][co].first=1;M[i][co+1].first=1;co+=4;}
    else if(linea[j]=='d'){M[i][co].first=1;M[i][co+1].first=1;M[i][co+3].first=1;co+=4;}
    else if(linea[j]=='e'){M[i][co].first=1;M[i][co+1].first=1;M[i][co+2].first=1;co+=4;}
    else if(linea[j]=='f'){M[i][co].first=1;M[i][co+1].first=1;M[i][co+2].first=1;M[i][co+3].first=1;co+=4;}
}

void DFS (vector<vector<pair<int,bool> > > &M,int f,int c,int etiqueta,int i,int j){

    if(i<0||j<0)return;
    if(i>=f||j>=c)return;
    if(M[i][j].first==0||M[i][j].second==true)return;

    M[i][j].first=etiqueta;
    M[i][j].second=true;
    DFS(M,f,c,etiqueta,i,j+1);
    DFS(M,f,c,etiqueta,i+1,j);
    DFS(M,f,c,etiqueta,i-1,j);
    DFS(M,f,c,etiqueta,i,j-1);


}
int DFS2 (vector<vector<pair<int,bool> > >&M,vector<int>&L,int f,int co,int i,int j){
    //cout<<i<<"-"<<j<<endl;
    mostrar(M,f,co);
    if(i<0||j<0){return 0;}
    if(i>=f||j>=co){return 0;}
    if(M[i][j].first!=0){return M[i][j].first;}
    if(M[i][j].second==true)return -1;
    M[i][j].second=true;
    M[i][j].first=1;
    int a=DFS2(M,L,f,co,i,j+1);
    int b=DFS2(M,L,f,co,i+1,j);
    int c=DFS2(M,L,f,co,i-1,j);
    int d= DFS2(M,L,f,co,i,j-1);

    //cout<<i<<" "<<j<<":"<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    if(a!=0&&b!=0&&c!=0&&d!=0)return a;
    return 0;


}

int main(){
    int H,W,et;
    string linea;
    int co;
    int cas=1;
    vector <int> L;
    priority_queue<char, vector<char>, greater<char> > O;
    //priority_queue <char> O;
    while(cin>>H>>W,H!=0&&W!=0){
        vector<vector<pair<int,bool> > > M(H);
        for(int i = 0; i<H; i++){
            M[i].assign(W*4,{0,false});}

        et=1;

        for(int i=0;i<H;i++){
            co=0;
            cin>>linea;
            for(int j=0;j<W;j++){
                if(linea[j]=='0'){co+=4;}
                else{
                    convertir(M,linea,linea[j],co,i,j);
                }
            }
        }
       // mostrar(M,H,W*4);

        for(int i=0;i<H;i++){
            for(int j=0;j<W*4;j++){
                if (M[i][j].first==1){
                    et++;
                    DFS(M,H,W*4,et,i,j);

                }
            }
        }
        //mostrar(M,H,W*4);
        L.assign(et+1,0);
        for(int i=0;i<H;i++){
            for(int j=0;j<W*4;j++){
                if (M[i][j].first==0){
                    //mostrar(M,H,W*4);
                    //cout<<DFS2(M,L,H,W*4,i,j)<<endl;
                    L[DFS2(M,L,H,W*4,i,j)]++;
                }
            }
        }
        //mostrar(M,H,W*4);
        for(int i=2;i<=et;i++){
            if(L[i]==0)O.push('W');
            else if(L[i]==1)O.push('A');
            else if(L[i]==2)O.push('K');
            else if(L[i]==3)O.push('J');
            else if(L[i]==4)O.push('S');
            else if(L[i]==5)O.push('D');
            }
        printf("Case %d: ",cas++);
        while(!O.empty()){
            cout<<O.top();
            O.pop();
        }
        printf("\n");
        //for(int i=0;i<=et;i++){cout<<L[i]<<" ";}
        //cout<<endl;
    }

}
