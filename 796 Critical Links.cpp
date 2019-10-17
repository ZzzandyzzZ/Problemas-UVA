//796   Critical Links
#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
#define UNVISITED -1
vector<int> dfs_num,dfs_low,dfs_parent,articulation_vertex;
int dfsNumberCounter,dfsRoot,rootChildren,V,total;
vector<vector<bool> > AdjList;
vector<ii> listP;
void articulationPointAndBridge(int u) {
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++; 
    for (int j = 0; j<V; j++) {
        if(AdjList[u][j]==0)continue;
        int v =j;
        if (dfs_num[v] == UNVISITED) { 
            dfs_parent[v] = u;
            if (u == dfsRoot) rootChildren++; 
            articulationPointAndBridge(v);
            if (dfs_low[v] > dfs_num[u]){
                listP.push_back(make_pair(min(u,v),max(u,v)));
                total++;
            }
            dfs_low[u] = min(dfs_low[u], dfs_low[v]); 
        }
        else if (v != dfs_parent[u]) 
            dfs_low[u] = min(dfs_low[u], dfs_num[v]); 
    } 
}
void mostrar(){
    for(int i=0;i<V;i++){
            for(int j=0;j<V;j++)
                cout<<AdjList[i][j]<<" ";
            cout<<endl;
        }
        
}
int main(){
    int u,v,e;
    char c;
    string line;
    while(cin>>V){
        dfsNumberCounter =total=0;
        dfs_num.assign(V, UNVISITED);
        dfs_low.assign(V, 0);
        dfs_parent.assign(V, 0);
        articulation_vertex.assign(V,0);
        AdjList.assign(V,{});
        listP.clear();
        for(int i=0;i<V;i++)
            AdjList[i].assign(V,0);


        for(int i=0;i<V;i++){
            cin>>u;
            scanf("%c%c%d%c",&c,&c,&e,&c);
            while(e--){
                cin>>v;
                AdjList[u][v]=1;
                AdjList[v][u]=1;
                //cout<<u<<"-"<<v<<endl;
            }
            
        }
       // mostrar();
        
        
        for (int i =0; i <V; i++)
            if (dfs_num[i] == UNVISITED) {
                dfsRoot = i; rootChildren = 0; 
                articulationPointAndBridge(i);
                articulation_vertex[dfsRoot] = (rootChildren > 1); 
            }
        printf("%d critical links\n",total);
        sort(listP.begin(),listP.end());
        for(int i=0;i<total;i++){
            printf("%d - %d\n",listP[i].first,listP[i].second);
        }
        cout<<endl;
    }
}