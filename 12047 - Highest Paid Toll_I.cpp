
//12047 - Highest Paid Toll
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;


vector <vii> AdjList;
vb dfs_num;
int Ma,t,p;
void DFS(int u,int ma,int dis){
	//

	cout<<u<<" "<<ma<<" "<<Ma<<endl;
	dfs_num[u]=1;
	for(int i=0;i<(int)AdjList[u].size();i++){
		ii v=AdjList[u][i];
		if(dis+v.second>p)continue;
		if(v.first==t){
			if(Ma<ma)Ma=ma;
			continue;
		}
		if(dfs_num[v.first]==0)
			DFS(v.first,max(ma,v.second),dis+v.second);

	}
	dfs_num[u]=0;
}

int main(){
	int T,N,M,s,u,w,j;
	cin>>T;
	while(T--){
		cin>>N>>M>>s>>t>>p;
		AdjList.assign(N+1,{});
		dfs_num.assign(N+1,0);
		Ma=-1;
		while(M--){
			cin>>u>>j>>w;
			AdjList[u].push_back({j,w});
		}
		/*
		for(int i=1;i<=N;i++){
			for(int k=0;k<AdjList[i].size();k++){
				cout<<AdjList[i][k].first<<" ";
			}
			cout<<endl;
		}
		*/
		DFS(s,0,0);
		cout<<Ma<<endl;
	}
	

}