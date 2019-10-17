//820 - Internet Bandwidth
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

int main(){
    int V,s,t,E,u,v,w,cas=1;
    vector<vector<int> > AdjList;
    vector<int> dist;
    while(cin>>V,V){
        cin>>s>>t>>E;
        dist.assign(V+1,INT_MAX);
        AdjList.assign(V+1,{});
        int pesos[V+1][V+1]={0};
        bool visit[V+1][V+1]={false};
        priority_queue<ii,vector<ii>,greater<ii> > pq;
        for(int i=1;i<=E;i++){
            cin>>u>>v>>w;
            AdjList[u].push_back(v);
            AdjList[v].push_back(u);
            pesos[u][v]+=w;
            pesos[v][u]+=w;
        }

        dist[s]=0;
        pq.push(ii(0, s));
        while (!pq.empty()) { 
            ii front = pq.top(); pq.pop();
            int d = front.first, u = front.second;
            if (d > dist[u]) continue; 
            for (int j = 0; j < (int)AdjList[u].size(); j++) {
                int v = AdjList[u][j];
                if(visit[u][v])continue;
                visit[u][v]=true;
                if (dist[u] + pesos[u][v] < dist[v]) {

                    dist[v] = dist[u] + pesos[u][v]; 
                    pq.push(ii(dist[v], v));
                } 
            } 
        }
        /*
        for(int i=0;i<V+1;i++){
            for(int j=0;j<V+1;j++){
                cout<<pesos[i][j]<<" ";
            }
            cout<<endl;
        }
        */
        for(int i=1;i<=dist.size();i++){
            cout<<dist[i]<<" ";
        }
        cout<<endl;

        printf("Network %d\n",cas++);
        printf("The bandwidth is %d.\n\n",dist[t]);
    }
    
}



/*
int main(){
    int V,s,t,E,u,v,w;
    vector<vector<ii> > AdjList;
    vector<int> dist;
    map <int<pair<int,int> >edges;
    map <int<pair<int,int> >::iterator it;
    while(cin>>V){
        cin>>s>>t>>E;
        dist.assign(V+1,INT_MAX);
        AdjList.assign(V+1,{});
        priority_queue<ii,vector<ii>,greater<ii> > pq;
        for(int i=1;i<=E;i++){
            cin>>u>>v>>w;
            if(u<v){
                it=edges.find(u);
            }
            else{
                it=edges.find(v);
            }
            v->second.second+=w;
        }
            AdjList[u].push_back(make_pair(v,w));
            AdjList[v].push_back(make_pair(u,w));
        }

        dist[s]=0;
        pq.push(ii(0, s));
        while (!pq.empty()) { 
            ii front = pq.top(); pq.pop();
            int d = front.first, u = front.second;
            if (d > dist[u]) continue; 
            for (int j = 0; j < (int)AdjList[u].size(); j++) {
                ii v = AdjList[u][j]; 
                if (dist[u] + v.second < dist[v.first]) {
                    dist[v.first] = dist[u] + v.second; 
                    pq.push(ii(dist[v.first], v.first));
                } 
            } 
        }
        for(int i=1;i<=dist.size();i++){
            cout<<dist[i]<<endl;
        }
    }
    
}
*/