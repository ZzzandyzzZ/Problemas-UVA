//11340 Newspaper

#include <bits/stdc++.h>

using namespace std;

int main(){
    int N,K,M;
    double val,total;
    map <char, double>::iterator it;
    map <char,double> valores;
    string linea;
    char ch;
    scanf("%d", &N);
    while(N--){
    	
    	total=0;
    	scanf("%d", &K);
    	while(K--){
    		cin>>ch>>val;
    		valores[ch]=val;
    	}
    	scanf("%d", &M);
    	cin.ignore();
    	while(M--){
    		linea="";
    		getline(cin,linea);
    		for(int i=0;i<linea.size();i++){
    			it = valores.find(linea[i]);
				
				if(it != valores.end())
    				total+=it->second;
    		}
    		
    	}

    	printf("%0.2lf$\n",total/100);
    	valores.clear();
    }
    return 0;

}
