//11138 Nuts and Bolts

#include <cstdio>
#include <vector>
using namespace std;
vector <int> match;
vector <bool> vis;
vector <vector<int> > grafo;

int Aug(int n){
    if(vis[n])return 0;
    vis[n]=1;
    for(int i=0;i<grafo[n].size();i++){
        int m=grafo[n][i];
        if(match[m]==-1||Aug(match[m])){
            match[m]=n;
            return 1;
        }
    }
    return 0;

}

int main(){
    int cas,bolts,nuts,num,MCBM;
    scanf("%d",&cas);
    for(int i=1;i<=cas;i++){
        MCBM=0;
        scanf("%d%d",&bolts,&nuts);
        grafo.assign(bolts,{});
        match.assign(nuts,-1);
        for(int b=0;b<bolts;b++){
            for(int n=0;n<nuts;n++){
                scanf("%d",&num);
                if(num){grafo[b].push_back(n);}
            }
        }
/*
        for(int h=0;h<bolts;h++){
            printf("%d::",h);
            for(int j=0;j<grafo[h].size();j++){
                printf("%d*",grafo[h][j]);
            }
            printf("\n");
        }
*/
        for(int j=0;j<bolts;j++){
            vis.assign(bolts,0);
            MCBM+=Aug(j);
        }
        printf("Case %d: ",i);
        printf("a maximum of %d nuts and bolts ",MCBM);
        printf("can be fitted together\n");

    }

}
