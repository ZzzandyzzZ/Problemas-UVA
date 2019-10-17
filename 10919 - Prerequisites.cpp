//10919 - Prerequisites?

//10324 - Zeros and Ones
#include <bits/stdc++.h>

using namespace std;
string k1;
set<string> lista;
int k,m,c,r,con;
bool comp;
bool comprobar(){

	comp=true;
	while(m--){
		con=0;
		cin>>c>>r;
		//cout<<"c"<<c;
		while(c--){
			cin>>k1;
			if(lista.find(k1)!=lista.end())
				con++;	
		}
		//cout<<"con"<<con<<endl;
		if(r>con){
			comp=false;;
		}
		
	}
	return comp;
}
int main(){
	while(cin>>k){
		//cout<<"A"<<endl;
		lista.clear();
		if(k==0)break;
		cin>>m;
		con=0;
		//cout<<"B"<<endl;
		while(k--){
			cin>>k1;
			lista.insert(k1);
		}
		if(comprobar())cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}

}