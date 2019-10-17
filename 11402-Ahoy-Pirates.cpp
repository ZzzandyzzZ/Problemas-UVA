#include <bits/stdc++.h>
using namespace std;

#define L(i) 2*i+1
#define R(i) 2*i+2
#define P(i) (i-1)*2


//vector<int>lista;
vector<int>st;
vector<vector<int> >lazy;
string A;
void mostrar(){
    int con=2,an=0;
    cout<<st[0]<<endl;
    for(int i=1;i<30;i++){
        cout<<st[i]<<"(";
        for(int j=0;j<lazy[i].size();j++)
            cout<<lazy[i][j]<<" ";
        cout<<")"<<" ";
        if(con+an==i){
            an=i;
            con*=2;
            cout<<endl;
        }


    }
    cout<<endl;
}
void create_st(int i,int a,int b){
	if(a==b){
		st[i]=A[a]-'0';
		return;
	}
	int m=(a+b)/2;
	create_st(L(i),a,m);
	create_st(R(i),m+1,b);
	st[i]=st[L(i)]+st[R(i)];

}

void Lazy(int i,int a,int b,vector<int> l){
    for(int j=0;j<l.size();j++){
        if(l[j]==1)st[i]=b-a+1;
        else if(l[j]==0)st[i]=0;
        else if(l[j]==2)st[i]=b-a+1-st[i];
        //cout<<"**"<<i<<" "<<st[i]<<" ";
    }
    //cout<<endl;
}

int update(int i,int a,int b,int qa,int qb,int l){
	//cout<<"**"<<st[i]<<"="<<i<<"**"<<endl;mostrar(45);cout<<endl;
	if(qb<a||b<qa){
        return st[i];
	}
	if(qa<=a&&b<=qb){
        lazy[i].push_back(l);
        Lazy(i,a,b,lazy[i]);
        //cout<<"**"<<st[i]<<"="<<i<<"**"<<endl;mostrar();cout<<endl;
        if(a==b)lazy[i]={};
        return st[i];
    }
    int m=(a+b)/2;
    if(lazy[i].size()>0){
        lazy[L(i)]=lazy[i];
        Lazy(L(i),a,m,lazy[i]);
        lazy[R(i)]=lazy[i];
        Lazy(R(i),m+1,b,lazy[i]);
        lazy[i]={};
    }

    //cout<<"**"<<st[i]<<"="<<i<<"**"<<endl;mostrar();cout<<endl;
	update(L(i),a,m,qa,qb,l);
	update(R(i),m+1,b,qa,qb,l);
	st[i]=st[L(i)]+st[R(i)];

}
int rmq(int i,int a,int b,int qa,int qb){
	if(qb<a||b<qa){
        return 0;
	}
	if(qa<=a&&b<=qb){
        lazy[i]=lazy[P(i)];
        Lazy(i,a,b,lazy[i]);
        //cout<<"**"<<st[i]<<"="<<i<<"**"<<endl;mostrar();cout<<endl;
        if(a==b)lazy[i]={};
        return st[i];
    }
    int m=(a+b)/2;
    if(lazy[i].size()>0){
        lazy[L(i)]=lazy[i];
        Lazy(L(i),a,m,lazy[i]);
        lazy[R(i)]=lazy[i];
        Lazy(R(i),m+1,b,lazy[i]);
        lazy[i]={};
    }
	int ml=rmq(L(i),a,m,qa,qb);
	int mr=rmq(R(i),m+1,b,qa,qb);
    st[i]=st[L(i)]+st[R(i)];
	return ml+mr;

}



/*
int rmq(int i,int a,int b,int qa,int qb){
	if(qb<a||b<qa)return 0;
	if(qa<=a&&b<=qb)return st[i];
	int m=(a+b)/2;
	int ml=rmq(L(i),a,m,qa,qb);
	int mr=rmq(R(i),m+1,b,qa,qb);
	return ml+mr;
}
*/
int main(){
	int N,M,T,m,qa,qb,tam,caso=1,Q;
	char cas;
	string au;
	cin>>N;
	while(N--){
	    Q=1;
        A="";
		cin>>M;
		while(M--){
			cin>>m;
			cin>>au;
			while(m--)A+=au;
		}
		tam=A.size();
		st.resize(4*tam);
		lazy.assign(4*tam,{});
		create_st(0,0,tam-1);
        //mostrar(45);cout<<endl;
		/*
		cout<<rmq(0,0,A.size()-1,0,4)<<endl;
		for(int i=0;i<A.size()*4;i++)
            cout<<st[i]<<" ";
        cout<<endl;
        */
        //cout<<A<<endl;

		cin>>T;
		cout<<"Case "<<caso++<<":"<<endl;
		while(T--){
			cin>>cas>>qa>>qb;
			switch (cas){
				case 'F':
					update(0,0,tam-1,qa,qb,1);
					//mostrar(45);cout<<endl;
					break;
				case 'E':

					update(0,0,tam-1,qa,qb,0);
					//mostrar(45);cout<<endl;
					break;
				case 'I':
                    update(0,0,tam-1,qa,qb,2);
                    //mostrar(45);cout<<endl;
					break;
				case 'S':
					cout<<"Q"<<Q++
					<<": "<<rmq(0,0,tam-1,qa,qb)<<endl;
					break;

			}

		}
	}
}
