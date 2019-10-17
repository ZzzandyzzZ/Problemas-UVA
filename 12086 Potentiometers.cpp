#include <bits/stdc++.h>
using namespace std;

#define L(i) 2*i+1
#define R(i) 2*i+2
#define P(i) (i-1)>>1

vector<int>lista;
vector<int>st;
vector<int>leaves;

void create_st(int i,int a,int b){
	if(a==b){
		st[i]=lista[a];
		leaves[a]=i;
		return;
	}
	int m=(a+b)/2;
	create_st(L(i),a,m);
	create_st(R(i),m+1,b);
	st[i]=st[L(i)]+st[R(i)];

}
void update(int p,int v){
	int i=leaves[p];
	lista[p]=v;
	st[i]=v;
	do{
		i=P(i);
		st[i]=st[L(i)]+st[R(i)];
	}
	while(i);
}
int rmq(int i,int a,int b,int qa,int qb){
	if(qb<a||b<qa)return 0;
	if(qa<=a&&b<=qb)return st[i];
	int m=(a+b)/2;
	int ml=rmq(L(i),a,m,qa,qb);
	int mr=rmq(R(i),m+1,b,qa,qb);
	return ml+mr;
}

int main(){
    int n,qa,qb,caso=1;
    string cas;
	while(cin>>n,n!=0){
        if(caso!=1)cout<<endl;
        lista.resize(n);
        leaves.resize(4*n);
        st.resize(4*n);
        for(int i=0;i<n;i++){
            cin>>lista[i];
        }
        create_st(0,0,n-1);
        printf("Case %d:\n",caso++);
        while(cin>>cas,cas!="END"){
            if(cas=="M"){
                cin>>qa>>qb;
                cout<<rmq(0,0,n-1,qa-1,qb-1)<<endl;
            }
            else if(cas=="S"){
                cin>>qa>>qb;
                update(qa-1,qb);
            }

        }
	}

}
