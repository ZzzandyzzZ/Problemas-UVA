//315 - Network
#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
#define UNVISITED -1
vector<int> dfs_num,dfs_low,dfs_parent,articulation_vertex;
int dfsNumberCounter,dfsRoot,rootChildren,total,V;
vector<vector<bool> > AdjList;
void articulationPointAndBridge(int u) {
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++; 
    for (int j = 1; j<=V; j++) {
        if(AdjList[u][j]==0)continue;
        int v =j;
        if (dfs_num[v] == UNVISITED) { 
            dfs_parent[v] = u;
            if (u == dfsRoot) rootChildren++; 
            articulationPointAndBridge(v);
            if (dfs_low[v] >= dfs_num[u]){
                articulation_vertex[u] = true; 
            }
            dfs_low[u] = min(dfs_low[u], dfs_low[v]); 
        }
        else if (v != dfs_parent[u]) 
            dfs_low[u] = min(dfs_low[u], dfs_num[v]); 
    } 
}
int main(){
    int u,v;
    string line;
    while(cin>>V,V){
        dfsNumberCounter = total=0;
        dfs_num.assign(V+1, UNVISITED);
        dfs_low.assign(V+1, 0);
        dfs_parent.assign(V+1, 0);
        articulation_vertex.assign(V+1, 0);
        AdjList.assign(V+1,{});

        for(int i=0;i<=V;i++)
            AdjList[i].assign(V+1,0);
        cin.ignore();
        while(getline(cin,line)){
            istringstream iss(line);
            iss>>u;
            if(u==0)break;
            while(iss>>v){
                AdjList[u][v]=1;
                AdjList[v][u]=1;  
                //cout<<v<<endl; 
            }
        }
        /*
        for(int i=1;i<=V;i++){
            for(int j=1;j<=V;j++)
                cout<<AdjList[i][j]<<" ";
            cout<<endl;
        }
        */
        for (int i = 1; i <=V; i++)
            if (dfs_num[i] == UNVISITED) {
                dfsRoot = i; rootChildren = 0; 
                articulationPointAndBridge(i);
                articulation_vertex[dfsRoot] = (rootChildren > 1); 
            }

        for(int i=1;i<=V;i++){
            //cout<<i<<" "<<articulation_vertex[i]<<endl;
            if(articulation_vertex[i])total++;
        }
        cout<<total<<endl;
    }
}