//11060	Beverages

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;


int main(){

    int N,M,cas=1;
    string b1,b2;
    vector<int> nivel;
    vector<string> T;
    vector<vector<int> >AdjList;

    while(scanf("%d",&N)!=EOF){

        priority_queue<ii,vector<ii>,greater<ii> > pq;
        map<string,int> B;
        nivel.assign(N,0);
        AdjList.assign(N,{});
        T.clear();
        printf("Case #%d: Dilbert should drink beverages in this order:",cas++);
        for(int i=0;i<N;i++){
            cin>>b1;
            B[b1]=i;
            T.push_back(b1);
        }
        scanf("%d",&M);
        while(M--){
            cin>>b1>>b2;
            AdjList[B[b1]].push_back(B[b2]);
            nivel[B[b2]]++;
        }
        for(int i=0;i<N;i++){
            if(nivel[i]==0)pq.push(make_pair(0,i));
        }
        while(!pq.empty()){
            ii a =pq.top();pq.pop();
            if(a.first!=nivel[a.second])continue;
            cout<<" "<<T[a.second];
            for(int i=0;i<AdjList[a.second].size();i++){
                int aux=AdjList[a.second][i];
                nivel[aux]--;
                pq.push(make_pair(nivel[aux],aux));
            }

        }
        cout<<"."<<endl<<endl;

    }
}