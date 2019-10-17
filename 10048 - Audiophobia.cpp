//10048 - Audiophobia


#include <bits/stdc++.h>

using namespace std;

int main(){
    int C,S,Q,u,v,w,cas=1;
    vector<vector<int> > AdjMat;
    while(cin>>C>>S>>Q,C,S,Q){
        if(cas!=1)cout<<endl;
        printf("Case #%d\n",cas++);
        //int AdjMat[C+1][C+1]={INT_MAX};
        AdjMat.assign(C+1,{});
        for(int i=1;i<=C;i++)
            AdjMat[i].assign(C+1,INT_MAX);
        /*
        for(int i=1;i<=C;i++){
            for(int j=1;j<=C;j++)
                cout<<AdjMat[i][j]<<" ";
            cout<<endl;
        }
        */
        while(S--){
            cin>>u>>v>>w;  
            AdjMat[u][v]=w;
            AdjMat[v][u]=w;
        }
        for(int k=1;k<=C;k++)
            for(int i=1;i<=C;i++)
                for(int j=1;j<=C;j++)
                    AdjMat[i][j]=min(AdjMat[i][j],max(AdjMat[i][k],AdjMat[k][j]));
        while(Q--){
            cin>>u>>v;
            if(AdjMat[u][v]==INT_MAX)
                cout<<"no path"<<endl;
            else
                cout<<AdjMat[u][v]<<endl;
        }
    }

}