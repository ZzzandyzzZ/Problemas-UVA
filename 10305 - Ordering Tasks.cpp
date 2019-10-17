//10305 - Ordering Tasks


#include <bits/stdc++.h>
using namespace std;

vector<int> ts,dfs_num; 
vector<vector<int> >AdjList;

void dfs2(int u) { 
    dfs_num[u] = 1;
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
        int v = AdjList[u][j];
        if (dfs_num[v] == -1)
            dfs2(v);
    }
    ts.push_back(u); 
}





int main(){
    int N,M,u,v;
    while(scanf("%d %d",&N,&M)){
        if(!N && !M)
            break;
        AdjList.assign(N+1,{});
        dfs_num.assign(N+1,-1);
        for(int i=1; i<=M; i++)
        {
            scanf("%d %d", &u, &v);
            AdjList[u].push_back(v);
        }
        
        for (int i = 1; i <=N; i++)
            if (dfs_num[i]==-1)
                dfs2(i);
        reverse(ts.begin(), ts.end());
        for(int x=0; x<ts.size(); x++){
            if(x<ts.size() - 1)
               printf("%d ", ts[x]);
            else
                printf("%d\n", ts[x]);
        }
        ts.clear();
    }
}