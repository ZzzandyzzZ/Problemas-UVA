

//11831 Sticker Collector Robot
#include <bits/stdc++.h>

using namespace std;

int N,M,S;
int ox,oy,aux,px,py,con;
string linea;
vector<string> ma;


void mostrar(){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(i==px&&j==py)cout<<"R";
            else cout<<ma[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}
int main(){

    while(scanf("%d %d %d",&N,&M,&S)){
        if(N==0&&M==0&&S==0)break;
        ma.clear();
        con=0;
        for(int i=0;i<N;i++){
            cin>>linea;
            ma.push_back(linea);
            for(int j=0;j<M;j++){
                if(linea[j]!='*'&&linea[j]!='#'&&linea[j]!='.'){
                    px=i;py=j;
                    switch (linea[j]){
                        case 'N':
                            ox=-1;oy=0;
                            break;
                        case 'O':
                            ox=0;oy=-1;
                            break;
                        case 'S':
                            ox=1;oy=0;
                            break;
                        case 'L':
                            ox=0;oy=1;
                            break;
                    }
                }
            }
            
        }
        //cout<<ox<<" "<<oy<<endl;
        //cout<<px<<" "<<py<<endl;
        cin>>linea;
        for(int i=0;i<linea.size();i++){
           // cout<<linea[i]<<" "<<ox<<" "<<oy<<"*"<<px<<" "<<py<<endl;
            //mostrar();
            if(linea[i]=='F'){
                //cout<<px<<" "<<py<<endl;
                if(px+ox<0||py+oy<0||px+ox==N||py+oy==M)continue;
                if(ma[px+ox][py+oy]=='#')continue;
                ma[px][py]='.';
                if(ma[px+ox][py+oy]=='*'){
                    con++;
                }
                px+=ox;py+=oy;
            }
            else{
                if(linea[i]=='D'&&(ox==1||ox==-1)){
                    ox*=-1;
                }
                else if(linea[i]=='E'&&(oy==1||oy==-1)){
                    oy*=-1;
                }
                aux=ox;
                ox=oy;
                oy=aux;
            }
            //cout<<ox<<" "<<oy<<endl;
            
        }
        cout<<con<<endl;




    }

}