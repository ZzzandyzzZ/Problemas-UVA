//10349 - Antenna Placement


#include <bits/stdc++.h>

using namespace std;
vector<int>match;
vector<bool>vis;
int cas,h,w,con,aux,MCBM;
vector<string> mapa;
vector<vector<int> >AdjList,mapaN;

int Aug(int l){
    if(vis[l])return 0;
    vis[l]=1;
    for(int j=0;j<AdjList[l].size();j++){
        int r=AdjList[l][j];
        if(match[r]==-1||Aug(match[r])){
            match[r]=l;
            return 1;
        }
    }
    return 0;
}




int main(){

    cin>>cas;
    while(cas--){
        cin>>h>>w;
        mapa.assign(h,"");
        mapaN.assign(h,{});
        MCBM=0;
        con=1;
        for(int i=0;i<h;i++){
            cin>>mapa[i];
            mapaN[i].assign(w,0);
            for(int j=0;j<w;j++){
                if(mapa[i][j]=='*'){
                    mapaN[i][j]=con++;
                }
            }
        }
        AdjList.assign(con,{});
        match.assign(con,-1);
        
        
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if((!(i&1)&&!(j&1))||((i&1)&&(j&1))){
                   // cout<<i<<" "<<j<<endl;
                    aux=mapaN[i][j];
                    if(aux!=0){
                        if(i>=1&&mapaN[i-1][j]!=0)AdjList[aux].push_back(mapaN[i-1][j]);
                        if(j>=1&&mapaN[i][j-1]!=0)AdjList[aux].push_back(mapaN[i][j-1]);
                        if((i<h-1)&&mapaN[i+1][j]!=0)AdjList[aux].push_back(mapaN[i+1][j]);
                        if((j<w-1)&&mapaN[i][j+1]!=0)AdjList[aux].push_back(mapaN[i][j+1]);
                    }
                }
            }
        }

        for(int i=0;i<con;i++){
            vis.assign(con,0);
            MCBM+=Aug(i);
        }
        cout<<con-MCBM-1<<endl;
        /*
        for(int i=0;i<con;i++){
            cout<<i<<"=";
            for(int j=0;j<AdjList[i].size();j++)
                cout<<AdjList[i][j]<<" ";
            cout<<endl;
        }
        */

    }

}
