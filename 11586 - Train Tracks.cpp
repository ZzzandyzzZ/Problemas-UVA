//11586 - Train Tracks
#include <bits/stdc++.h>

using namespace std;

int main(){
	string linea;
	int T,conF,conM;
	cin>>T;
	cin.ignore();
	while(T--){
		conM=conF=0;
		getline(cin,linea);
		for(int i=0;i<linea.size();i++){
			if(linea[i]=='M')conM++;
			else if(linea[i]=='F')conF++;
		}
		if(conF==conM&&conF!=1)cout<<"LOOP"<<endl;
		else cout<<"NO LOOP"<<endl;
	}

}