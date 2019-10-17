//10324 - Zeros and Ones
#include <bits/stdc++.h>

using namespace std;

int main(){
	string cas;
	int n,i,j,cont=1;
	bool con;
	while(cin>>cas){
		cin>>n;
		cout<<"Case "<<cont++<<":"<<endl;
		while(n--){
			cin>>i>>j;
			con=true;
			for(int k=min(i,j);k<max(i,j);k++){
				if(cas[k]!=cas[k+1]){
					con=false;
					break;
				}
				//cout<<cas[k]<<endl;
			}
			if(con)cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
	}
}