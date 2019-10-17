//11159 Factors and Multiples

#include <cstdio>
#include <vector>
std::vector<bool> vis;
std::vector<int> match;
std::vector<std::vector<int> > Grafo(100);
void mostrar(){
    for(int i=0;i<match.size();i++){
        printf("*%d*",match[i]);
    }
    printf("\n");
}
int Aug(int n){
    printf("%d*\n",n);
	if(vis[n])return 0;
	vis[n]=1;
	for(int i=0;i<Grafo[n].size();i++){
		int m=Grafo[n][i];
		if(match[m]==-1||Aug(match[m])){
			match[m]=n;
			mostrar();
			return 1;
		}
	}
	mostrar();
	return 0;
}




int main(){
	int T,n,m,cas=1,MCBM;
	std::vector<int> A(100);
	std::vector<int> B(100);

	scanf("%d",&T);
	while(T--){
		MCBM=0;
		scanf("%d",&n);

		for(int i=0;i<n;i++){
			scanf("%d",&A[i]);
			Grafo[i].clear();

		}
		scanf("%d",&m);
		for(int i=0;i<m;i++){
			scanf("%d",&B[i]);
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(A[i]!=0&&B[j]%A[i]==0){
					Grafo[i].push_back(j);
				}
				else if(A[i]==0&&B[j]==0){
					Grafo[i].push_back(j);
				}
			}
		}
		match.assign(m,-1);

		for(int i=0;i<n;i++){
			printf("%d::",i);
			for(int j=0;j<Grafo[i].size();j++){
				printf("%d*",Grafo[i][j]);
			}
			printf("\n");
		}

		for(int i=0;i<n;i++){
			vis.assign(n,0);
			MCBM+=Aug(i);
		}
		printf("Case %d: %d\n",cas++,MCBM);

	}


}
