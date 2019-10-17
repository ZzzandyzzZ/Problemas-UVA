//161 - Traffic Lights

//608 - Counterfeit Dollar
#include <bits/stdc++.h>

using namespace std;


bool comprobar(){
    for(i=0;i<t;i++){
        vm[i].first+=(2*v[i]);
        for(int j=0;j<i;j++){
            if(!(vm[j].first<=vm[i].first&&vm[j].second>vm[i].first)){
                return false;
            }
        }
    }
    return true;
}


int main(){
    int i;
    while(cin>>a>>b>>c){
        if(a==0&&b==0&&c==0)break;
        vector<int> v;
        vector<pair<int,int> > vm;
        t=2;
        v.push_back(a);v.push_back(b);
        while(c!=0){
            v.push_back(c);
            t++;
            cin>>c;
        }
        vm.assign(t,{0,0});
        while(1){
            for(i=0;i<t;i++)cout<<v[i]<<" ";cout<<endl;
            for(i=0;i<t;i++)cout<<vm[i].first<<" "<<vm[i].second<<"*";cout<<endl;    
            if(comprobar()){
                
            }

        }

    }
}