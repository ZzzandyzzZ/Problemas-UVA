//11631 - Dark roads

#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
class UnionFind{
private:
     vector<int>  p,rank;
public:
    UnionFind(int N){
        rank.assign(N,0);
        p.assign(N,0);
        for(int i=0;i<N;i++)p[i]=i;
    }
    int findSet(int i){
        return(p[i]==i)?i:(p[i]=findSet(p[i]));
    }
    bool isSameSet(int i,int j){
        return findSet(i)==findSet(j);
    }
    void unionSet(int i,int j){
        if(!isSameSet(i,j)){
            int x =findSet(i),y=findSet(j);
            if(rank[x]>rank[y])p[y]=x;
            else{
                p[x]=y;
                if(rank[x]==rank[y])rank[y]++;
            }
        }
    }
};
int main(){
    int m,n,u,v,w,cost,total;
    
    while(cin>>m>>n,m,n){
        cost=total=0;
        vector<pair<int ,ii> >EdgeList;
        for(int i=0;i<n;i++){
            cin>>u>>v>>w;
            total+=w;
            EdgeList.push_back(make_pair(w,ii(u,v)));
        }
        sort(EdgeList.begin(),EdgeList.end());
        UnionFind UF(m);
        for(int i=0;i<n;i++){
            pair<int,ii> front=EdgeList[i];
            if(!UF.isSameSet(front.second.first,front.second.second)){
                cost+=front.first;
                UF.unionSet(front.second.first,front.second.second);
            }
        }
        cout<<total-cost<<endl;
    }


}