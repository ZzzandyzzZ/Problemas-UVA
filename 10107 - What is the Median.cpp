//10107 - What is the Median?
#include <bits/stdc++.h>

using namespace std;

int main(){
	vector<int> lista;
	int size,cas;
	while(scanf("%d",&cas)!=EOF){
		lista.push_back(cas);
		sort(lista.begin(),lista.end());
		size=lista.size();
		if(size&1){
			cout<<lista[size/2]<<endl;
		}
		else{
			cout<<(lista[size/2]+lista[size/2-1])/2<<endl;
		}
	}

}