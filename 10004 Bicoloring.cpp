//10004	Bicoloring

#include <bits/stdc++.h>
using namespace std;

vector<vector<int> >AdjList;
vector<int> vis;
int N,u,v,E;

void mostrar(){
    for(int i=0;i<N;i++){
            for(int j=0;j<N;j++)
                cout<<AdjList[i][j]<<" ";
            cout<<endl;
        }
        
}

bool bfs(){
    int c=0;
    queue<int> q;
    vis[0]=1;
    q.push(0);
    while(!q.empty()){
        c=q.front();q.pop();
        for(int i=0;i<N;i++){
            if(AdjList[c][i]==0)continue;
            if(vis[i]==0){
                if(vis[c]==1)
                    vis[i]=2;
                else
                    vis[i]=1;
                q.push(i);
            }
            else{
                if(vis[i]==vis[c])
                    return false;
            }
        }
    }
    return true;

}

int main(){

    
    while(cin>>N,N){
        vis.assign(N,0);
        AdjList.assign(N,{});
        for(int i=0;i<N;i++)
            AdjList[i].assign(N,0);
        cin>>E;
        while(E--){
            cin>>u>>v;
            AdjList[u][v]=1;
            AdjList[v][u]=1;
        }
        //mostrar();
        if(bfs())
            cout<<"BICOLORABLE."<<endl;
        else
            cout<<"NOT BICOLORABLE."<<endl;


    }

}