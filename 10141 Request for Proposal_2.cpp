//10141 Request for Proposal
#include <bits/stdc++.h>

using namespace std;

int main(){
	double RFP,precio,precior;
	int n,p,prop,con=1;
	string aux,rpta;
	while(cin>>n>>p,n||p){
		//cout<<"A1"<<endl;
		RFP=0;
		for(int i=0;i<n;i++){
			cin.ignore();
			getline(cin,aux);
		}
		//cout<<"B"<<endl;
		
		for(int i=0;i<p;i++){
			getline(cin,aux);
			scanf("%lf %d",&precio,&prop);
			if(prop>RFP){
				rpta=aux;
				RFP=prop;
				precior=precio;
			}
			else if(prop==RFP&&precior>precio){
				rpta=aux;
				RFP=prop;
				precior=precio;
			}
			cin.ignore();
			for(int j=0;j<prop;j++){
				getline(cin,aux);
			}
			//cout<<"C"<<endl;
		}
		if (con>1)
			cout<<endl;
		cout<<"RFP #"<<con++<<endl;
		cout<<rpta<<endl;
	}



}