//11094 - Continents

#include <bits/stdc++.h>

using namespace std;
vector<string> ms;
vector<vector<int> > mi;
char simbolo;
int M,N,X,Y;
void mostrar(){
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++)
            cout<<mi[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;

}
int DFS(int x,int y,char a,int aux=0){
    
    if(x<0)return 0;
    if(y<0)y=N-1;
    if(x==M)return 0;
    if(y==N)y=0;
    if(mi[x][y]!=0||ms[x][y]!=a)return 0;
    //cout<<x<<" "<<y<<endl;
    //mostrar();
    if(aux==1||ms[x][y]!=simbolo)mi[x][y]=1;
    else mi[x][y]=2;
    return 1+DFS(x+1,y,a,aux)+DFS(x,y+1,a,aux)+
            DFS(x-1,y,a,aux)+DFS(x,y-1,a,aux);

}


int main(){
    
    string l;
    int ma;
    while(scanf("%d %d",&M,&N)!=EOF){
        ms.clear();
        mi.assign(M,{});
        ma=0;
        if(M==0&&N==0)break;
        for(int i=0;i<M;i++)
            mi[i].assign(N,0);

        for(int i=0;i<M;i++){
            cin>>l;
            ms.push_back(l);
        }
        cin>>X>>Y;
        simbolo=ms[X][Y];
        DFS(X,Y,simbolo,1);
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
               // cout<<"valor "<<i<<" "<<j<<"="<<<<endl;
                if((ms[i][j])==simbolo){
                    ma=max(DFS(i,j,ms[i][j]),ma);
                }
                else
                    DFS(i,j,ms[i][j]);
            }
        }
        //mostrar();
        cout<<ma<<endl;
    }


}