//11661 - Burger Time?
#include <bits/stdc++.h>

using namespace std;

int main(){
	int L,rpta,temp,RD;
	string pista;
	while(cin>>L,L){
		temp=1;
		rpta=L*2;
		RD=0;
		cin>>pista;
		for(int i=0;i<L;i++){
			//cout<<"i"<<i<<endl;
			if(pista[i]=='Z'){
				rpta=0;
				break;
			}
		
			if(pista[i]=='R'){
				if(RD==0)RD=1;
				else if(RD==1)temp=1;
				else {
					rpta=min(temp,rpta);
					RD=1;
					temp=1;
				}
			}
			else if(pista[i]=='D'){
				if(RD==0)RD=2;
				else if(RD==2)temp=1;
				else{
					rpta=min(temp,rpta);
					temp=1;
					RD=2;
				}
			}
			
			else if(RD>0&&pista[i]=='.')temp++;
			
		}
		cout<<rpta<<endl;
	}
	
}