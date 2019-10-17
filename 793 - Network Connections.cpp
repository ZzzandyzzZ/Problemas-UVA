//793 - Network Connections
#include <bits/stdc++.h>

using namespace std;
class UnionFind{
private:
     vector<int>  p,rank;
public:
    UnionFind(int N){
        rank.assign(N+1,0);
        p.assign(N+1,0);
        for(int i=1;i<=N;i++)p[i]=i;
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
    int cas,V,u,v,co,inco;
    char op;
    string linea;
    cin>>cas;

    while(cas--){
        scanf("\n%d\n",&V);
        co=inco=0;
        UnionFind uf(V);
      
        while(getline(cin,linea)){
            if(linea.empty())break;
            sscanf(linea.c_str(),"%c %d %d",&op,&u,&v);
           // cout<<op<<endl;
            if(op=='c')uf.unionSet(u,v);
            else{
                if(uf.isSameSet(u,v))co++;
                else inco++;
            
            }
            
        }
        printf("%d,%d\n",co,inco);

        if(cas!=0)printf("\n");
    }


}