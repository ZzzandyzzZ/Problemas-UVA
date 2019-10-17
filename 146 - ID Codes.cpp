//146 - ID Codes
#include <bits/stdc++.h>

using namespace std;

int main(){

	string cas;
	int i,j,len,k;
	char aux;
	while(cin>>cas,cas!="#"){
		len=cas.size();
		for(i=len-1;i>=0;i--){
			if(cas[i]>cas[i-1]){
				break;
			}
		}
		if(i==0){
			cout<<"No Successor"<<endl;
			continue;
		}
		aux=cas[i-1];
		for(j=i;j<len;j++){
			if(cas[j]<=aux)break;

		}
		/*
		cout<<i<<endl;
		cout<<j<<endl;
		*/
		
		if(i==j)swap(cas[j-1],cas[j]);
		else swap(cas[i-1],cas[j-1]);
		//cout<<cas<<endl;
		k=1;
		for(j=i;j<(len+i)/2;j++){
			swap(cas[j],cas[len-k]);
			k++;
			//cout<<cas<<endl;
		}
		cout<<cas<<endl;
	}

}
