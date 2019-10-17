//1203 Argus


#include <cstdio>
#include <string>
#include <queue>
using namespace std;
int MCD(int a,int b){
	return b==0 ?a:MCD(b,a%b);
}
int main(){
    string re;
    vector<pair<int,int> v;
    int Q,P,in=1,con=0,K;
    while(re!="#"){
        scanf("%d %d",&Q,&P);
        v.push_back(make_pair(Q,P));
        if(in)in=MCD(P,P);
        else in=MCD(in,P);
    }
    sort(v.begin(),v.end());
    cin>>K;
    for(int i=in;con<K;i+=in){
    	for(int j=0;j<v.size();j++){
    		if(v[j].second%i==0){
    			cout<<v[j].first<<endl;
    			con++;
    		}
    	}
    }
}
