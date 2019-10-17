//661 Blowing Fuses

#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
int main(){
    int n,m,c,ac,aux,maxi,cas=1;
    bool b;
    vector <int> am;
    vector <bool> es;
    while(scanf("%d %d %d",&n,&m,&c),n,m,c){

        am.assign(n,0);
        es.assign(n,0);
        ac=0;
        b=false;
        maxi=-1;
        for(int i=0;i<n;i++){
           cin>>am[i];
        }
        while(m--){
            scanf("%d",&aux);
            if(es[aux-1]==1){
                es[aux-1]=0;
                ac-=am[aux-1];
            }
            else{
                es[aux-1]=1;
                ac+=am[aux-1];
                if(ac>c)b=true;
                if(ac>maxi&&ac<=c)maxi=ac;
            }
            //cout<<"-"<<ac<<"-"<<endl;
        }
        printf("Sequence %d\n",cas++);
        if(b)printf("Fuse was blown.\n");
        else{
            printf("Fuse was not blown.\n");
            printf("Maximal power consumption was %d amperes.\n",maxi);
        }
        printf("\n");
    }

}
