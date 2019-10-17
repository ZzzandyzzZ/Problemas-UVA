//10954 Add All

#include <bits/stdc++.h>

using namespace std;

int main(){
    int N,an,total,cas;
    priority_queue<int,vector<int>,greater<int> > pq;
    while(cin>>N,N){
        total=0;
        if(N==1){
            cin>>cas;
            cout<<total<<endl;
            continue;
        }
        while(N--){
            cin>>cas;
            pq.push(cas);
        }
        while(!pq.empty()){
            an=pq.top();
            pq.pop();
          //  cout<<an<<" ";
            if(pq.empty()){
                total+=an;
            }
            else{
                an+=pq.top();
                pq.pop();
                //cout<<an<<" "<<endl;
                total+=an;
                if(!pq.empty())pq.push(an);
            }
            //cout<<"To"<<total<<endl;
        }
        cout<<total<<endl;
    }


}