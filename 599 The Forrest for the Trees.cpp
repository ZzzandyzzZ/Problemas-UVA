#include <iostream>
#include <utility>
#include <vector>
#define M 100000
using namespace std;
typedef pair<char,char> edge;
vector<edge> G;

struct union_find{
    int comp[26];
    void init(){
        for(int i=0;i<=25;i++){
            comp[i]=char(65+i);
        }
    };
    char find_s(char x){
        if(comp[(x-'0')-65]==x){cout<<"fin: "<<x<<endl;return x;}
        return comp[(x-'0')-65]=find_s(comp[(x-'0')-65]);
    };
    bool join(char x,char y){
        x=find_s(x);
        y=find_s(y);
        cout<<"join"<<x<<" "<<y<<endl;
        if(x==y)return false;
        int aux=y-'0'-65;
        comp[aux]=x;
        return true;

    };

};



int main(){
    int n;
    edge aux;
    union_find cp;
    string ar;
    cin>>n;
    while(n--){
        cp.init();
        while(cin>>ar,ar[0]!='*'){
            cp.join(ar[1],ar[3]);
            aux=make_pair(ar[1],ar[3]);
            G.push_back(aux);
        }

        for(int i=0;i<G.size();i++){
            cout<<G[i].first<<" "<<G[i].second<<endl;
        }
        for(int i=0;i<27;i++){
            cout<<cp.comp[i]<<" ";
        }
        cout<<endl;

    }
}
