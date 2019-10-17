//11933 - Splitting Numbers
#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,a,b,p;
	bool com;
	while(cin>>n,n!=0){
		com=a=b=p=0;
		while(n!=0){
			if(n%2==1){
				if(com){
					a+=pow(2,p);
				}	
				else{
					b+=pow(2,p);
				}
				com=!com;
			}
			p++;
			n/=2;
			//cout<<a<<" "<<b<<endl;
		}
		cout<<b<<" "<<a<<endl;
	}



}