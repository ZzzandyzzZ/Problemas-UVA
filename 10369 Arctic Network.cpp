//10369 Arctic Network
#include <bits/stdc++.h>
using namespace std;
typedef pair<double,double> ii;
class UnionFind{
    vector<int>p,rank;
public:
    UnionFind(int V){
        rank.assign(V,0);
        p.resize(V);
        for(int i=0;i<V;i++)
            p[i]=i;
    }
    int findSet(int i){
        return(p[i]==i)?i:(p[i]=findSet(p[i]));
    }
    bool isSameSet(int i,int j){
        return findSet(i)==findSet(j);
    }
    void unionSet(int i,int j){
        if(!isSameSet(i,j)){
            int x=findSet(i),y=findSet(j);
            if(rank[x]>rank[y])p[y]=x;
            else{
                p[x]=y;
                if(rank[x]==rank[y])rank[y]++;
            }
        }
    }

};

double dis(pair<double,double> a,pair<double,double> b){
    return sqrt(pow(a.first-b.first,2)+pow(a.second-b.second,2));
}

int main(){
    double N,P,x,y;
    int S;
    vector<pair<double,pair<double,double> > > EdgeList;
    vector<pair<double,double> >post;
    cin>>N;
    while(N--){
        cin>>S>>P;
        post.clear();
        EdgeList.clear();
        priority_queue <double> pq;
        for(int i=0;i<P;i++){
            cin>>x>>y;
            post.push_back(make_pair(x,y));
        }
        for(int i=0;i<P;i++){
            for(int j=i+1;j<P;j++){
                EdgeList.push_back(make_pair(dis(post[i],post[j]),make_pair(i,j)));
            }
        }
        sort(EdgeList.begin(),EdgeList.end());
        UnionFind UF(P);
        for(int i=0;i<EdgeList.size();i++){
            pair<double,ii> front=EdgeList[i];
            if(!UF.isSameSet(front.second.first,front.second.second)){
                pq.push(front.first);
                UF.unionSet(front.second.first,front.second.second);
            }
        }
        
        S--;
        while(!pq.empty()&&S){
            pq.pop();
            S--;
        }
        printf("%.2lf\n",pq.top());
        
        /*
        while(!pq.empty()){
            cout<<pq.top()<<endl;
            pq.pop();
        }

        for(int i=0;i<EdgeList.size();i++){
            cout<<EdgeList[i].first<<" ";
        }
        cout<<endl;
        */

    }

}