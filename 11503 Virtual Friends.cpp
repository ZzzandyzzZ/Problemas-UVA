//11503 Virtual Friends
#include <bits/stdc++.h>

using namespace std;
class UnionFind{
private:
     
public:
    vector<int>  p,rank,peso;
    UnionFind(int N){
        rank.assign(N+1,0);
        p.assign(N+1,0);
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
            if(rank[x]>rank[y])
                p[y]=x;

            else{
                p[x]=y;
                if(rank[x]==rank[y])rank[y]++;
            }
        }
    }
};

int main(){
    int cas,con,N,total;
    int aux,aux2;
    map<string,int> ::iterator it;
    string a,b;
    cin>>cas;
    while(cas--){
        cin>>N;
        con=0;
        map<string,int> A;
        UnionFind uf(N*2);
        while(N--){
            cin>>a>>b;
            total=0;
            it=A.find(a);
            if(it==A.end())A[a]=con++;
            it=A.find(b);
            if(it==A.end())A[b]=con++;
            uf.unionSet(A[a],A[b]);
            aux=uf.findSet(A[a]);
            aux2=uf.findSet(A[b]);
            /*
            for(int i=0;i<con;i++)
                cout<<i<<"="<<uf.p[i]<<" ";
            cout<<endl;
            */
            for(int i=0;i<con;i++){
                if(uf.findSet(i)==aux||uf.findSet(i)==aux2)total++;
            }
            cout<<total<<endl;
            //cout<<endl;
        }
        /*
        it=A.begin();
        while(it!=A.end()){
            cout<<it->first<<" "<<it->second<<endl;
            it++;
        }
        */
    }


}