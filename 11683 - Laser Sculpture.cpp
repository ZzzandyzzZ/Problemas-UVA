//11683 - Laser Sculpture

#include <bits/stdc++.h>

using namespace std;

int main(){
	int A,L,ma,con;
	vector<int>lista;
	while(cin>>A,A){
		cin>>L;
		con=0;
		lista.resize(L);
		for(int i=0;i<L;i++){
			cin>>lista[i];
		}
		ma=lista[0];
		for(int i=0;i<L-1;i++){
			if(lista[i]>=lista[i+1]){
				con+=(lista[i]-lista[i+1]);
			}
			else{
				if(lista[i+1]>ma){
					con+=(lista[i+1]-ma);
					ma=lista[i+1];
				}
			}

		}
		con+=(A-ma);
		cout<<con<<endl;
	}
	
}