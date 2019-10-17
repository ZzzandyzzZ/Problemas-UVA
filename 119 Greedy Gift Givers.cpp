//119 Greedy Gift Givers
#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
int n;
vector <string> l_p(12);
vector <int> t_p;

void update(string per,int can){
    for(int i=0;i<n;i++){
        if(l_p[i]==per){
            t_p[i]+=can;
            return;
        }
    }

}
int main(){
    int can,p,aux;
    bool a=false;
    string per,per2;
    while(scanf("%d",&n)!=EOF){
        if(a)cout<<endl;
        a=true;
        t_p.assign(12,0);
        for(int i=0;i<n;i++){
            cin>>l_p[i];
        }
        for(int i=0;i<n;i++){
            cin>>per;
            scanf("%d %d",&can,&p);
            if(p!=0)aux=can/p;
            update(per,-(aux*p));
            while(p--){
                cin>>per2;
                update(per2,aux);
            }

        }
        for(int i=0;i<n;i++){
            cout<<l_p[i]<<" "<<t_p[i]<<endl;
        }
        l_p.clear();
    }

}
