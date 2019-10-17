//11080 Place the Guards
#include <bits/stdc++.h>
using namespace std;

vector<vector<int> >AdjList;
vector<int> vis;
int V,u,v,E,total,total2;

void mostrar(){
    for(int i=0;i<V;i++){
            for(int j=0;j<V;j++)
                cout<<AdjList[i][j]<<" ";
            cout<<endl;
        }
        
}

int bfs(int c){
    queue<int> q;
    total=1;
    total2=0;
    vis[c]=1;
    q.push(c);
    while(!q.empty()){
        c=q.front();q.pop();
        for(int j=0;j<V;j++){
            if(AdjList[c][j]==0)continue;
            if(vis[j]==0){
                if(vis[c]==1){
                    total2++;
                    vis[j]=2;
                }
                else{
                    total++;
                    vis[j]=1;
                }
                q.push(j);
            }
            else{
                if(vis[j]==vis[c])
                    return -1;
            }
        }
    }
    if(min(total,total2)==0)
        return max(total,total2);
    else
        return min(total,total2);

}

int main(){
    int N,i,temp,rpta;
    bool com;

    cin>>N;    
    while(N--){
        cin>>V>>E;
        vis.assign(V,0);
        AdjList.assign(V,{});
        for(i=0;i<V;i++)
            AdjList[i].assign(V,0);
        rpta=0;
        com=true;
        while(E--){
            cin>>u>>v;
            AdjList[u][v]=1;
            AdjList[v][u]=1;
        }
        //mostrar();
        for(i=0;i<V;i++){
            if(vis[i]==0){
                temp=bfs(i);
                if(temp==-1){
                    cout<<"-1"<<endl;
                    com=false;
                    break;
                }
                else
                    rpta+=temp;
            }
        }
        if(com){
           // cout<<V<<"="<<total<<"+"<<total2<<endl;
            cout<<rpta<<endl;
        }
        /*
        for(int i=0;i<V;i++)
            cout<<vis[i]<<" ";
        cout<<endl;
        */

    }

}