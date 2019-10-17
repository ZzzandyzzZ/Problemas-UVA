#include <iostream>
#include <vector>
#include <algorithm>
#define M 200000

using namespace std;

struct union_find{
	int S[M];
	void init (int n){
		for(int i=0;i<n;i++){
			S[i]=i;
		}
	};
	int find_s(int x){
		if (x ==S[x])return x;
		return S[x] = find_s(S[x]);
	};
	bool union_s(int x,int y){
		x = find_s(x);
		y = find_s(y);
		if (x==y) return false;
		S[x]=y;
		return true;
	};
};

struct edge_t
{
	int x,y,w;
};

bool operator < (edge_t a,edge_t b){
	return a.w < b.w;
}

union_find uf;
edge_t G[M];

int Kruskal(int m, int n){
	uf.init(n);
	int r=0;
	sort(G, G + m);
    //for(auto e:G){
	for(int j=0 ;j<m;j++){
		if (uf.union_s(G[j].x,G[j].y)){
			r +=G[j].w;
		}
	}
	return r;
}
int main(){
	int m,n;
	int x,y,w;

	while(cin>>n>>m){
        int co=0;
        if(n==0 || m==0){return 0;}
        for(int i=0;i<m;i++){
            cin>>x>>y>>w;

            G[i].x=x;
            G[i].y=y;
            G[i].w=w;
            co+=w;

        }
        cout<<co-Kruskal(m,n)<<endl;
	}

}
