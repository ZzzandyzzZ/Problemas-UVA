//820 - Internet Bandwidth

#include <bits/stdc++.h>  
using namespace std;

typedef vector<int> vi;


int V,E,a,b,w,cas=1;
int  mf, f, s, t; 
vector<vi> res;
vi p; 

void mostrar(){
    for(int i=1;i<=V;i++){
        for(int j=1;j<=V;j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i=0;i<=V;i++){
        cout<<p[i]<<" ";
    }
    cout<<endl;
}
void augment(int v, int minEdge)
{
    if (v == s) 
    {
    f = minEdge; 
    return;
    } 
    else if (p[v] != -1)
    {
        augment(p[v], min(minEdge, res[p[v]][v]));
        res[p[v]][v] -= f;
        res[v][p[v]] += f; 
    } 
}


int main(){
    while(scanf("%d",&V),V){
        cin>>s>>t>>E;

        res.assign(V+1,{});
        for(int i=0;i<V+1;i++)res[i].assign(V+1,0);

        while(E--){
            cin>>a>>b>>w;
            res[a][b]+=w;
            res[b][a]+=w;
        }

        

        mf = 0; 
        while (1) {
            
            vi dist(V+1,INT_MAX);
            queue<int> q;
            p.assign(V+1, -1);
            dist[s] = 0;
            q.push(s);
            f = 0;
            while (!q.empty()){
                int u = q.front(); q.pop();
              //  cout<<"u"<<u<<endl;
                if (u == t) break; 
                for (int v = 1; v <=V; v++)
                    if (res[u][v] > 0 && dist[v] == INT_MAX){
                        //cout<<v<<endl;
                        dist[v] = dist[u] + 1, q.push(v), p[v] = u; 
                    }
            }
            //mostrar();
            augment(t, INT_MAX); 
            if (f == 0) break; 
            mf += f; 
        }
        printf("Network %d\n",cas++);
        printf("The bandwidth is %d.\n", mf);    
        printf("\n");

    }




}