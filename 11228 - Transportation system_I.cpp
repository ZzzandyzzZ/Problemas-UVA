//11228 - Transportation system.

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;


class UnionFind{
	 
public:
	vector<int>  p,rank;
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

float dis(pair<int,int> a,pair<int,int> b){
	return sqrt(float(pow((a.first-b.first),2))+pow((a.second-b.second),2));
}
int main(){
	int T,n,r,x,y,E,roads,railroads,estados;
	vector<ii> ini;
	vector<pair<float,ii> >EdgeList;
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>n>>r;
		E=n*(n-1)/2;
		ini.resize(n);
		EdgeList.clear();
		for(int j=0;j<n;j++){
			cin>>x>>y;
			ini[j]=make_pair(x,y);
		}
		for(int j=0;j<n;j++){
			for(int k=j+1;k<n;k++){
				EdgeList.push_back(make_pair(dis(ini[j],ini[k]),ii(j,k)));
			}
		}
		/*
		for(int j=0;j<E;j++){
			cout<<EdgeList[j].first<<" "<<
			EdgeList[j].second.first<<" "<<
			EdgeList[j].second.second<<endl;
		}
		*/
		sort(EdgeList.begin(),EdgeList.end());
		roads=0;
		railroads=0;
		estados=0;
		UnionFind UF(n);
		for(int i=0;i<E;i++){
			pair<int,ii> front=EdgeList[i];
			if(!UF.isSameSet(front.second.first,front.second.second)){
				if(front.first>=r)railroads+=front.first;
				else roads+=front.first;
				UF.unionSet(front.second.first,front.second.second);
			}
		}
		/*
		cout<<"A"<<UF.p.size()<<"****";
		for(int j=0;j<=E;j++){
			cout<<UF.p[j]<<" ";
			if(UF.p[j]==j)estados++;
		}
		cout<<endl;
		for(int j=0;j<=E;j++){
			cout<<UF.rank[j]<<" ";
			if(UF.rank[j]==j)estados++;
		}
		*/
		printf("Case #%d: %d %d %d\n",i,estados,roads,railroads);

	}




	

	
}