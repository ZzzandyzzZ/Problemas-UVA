//12668	Attacking rooks

#include <bits/stdc++.h>
using namespace std;

vector<int> match;
vector<bool>vis;
vector<vector<int> >AdjList;

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
    int N,con1,con2,MCBM;
    vector<string>tablero;
    vector<vector<int> > fil,col;
    
    while(cin>>N){
        tablero.assign(N,"");
        fil.assign(N,{});
        col.assign(N,{});
        
        MCBM=0;

        for(int i=0;i<N;i++){
            cin>>tablero[i];
            fil[i].assign(N,-1);
            col[i].assign(N,-1);
        }
        con1=0;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(tablero[i][j]!='X'){
                    fil[i][j]=con1;
                }
                else if(tablero[i][j]=='X'&&j<N-1&&j!=0)
                    con1++;
            }
            con1++;
        }
        con2=0;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(tablero[j][i]!='X'){
                    col[j][i]=con2;
                }
                else if(tablero[j][i]=='X'&&j<N-1&&j!=0)
                    con2++;
            }
            con2++;
        }
        /*
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){cout<<setw(3)<<fil[i][j];}
            cout<<endl;
        }
        cout<<endl;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){cout<<setw(3)<<col[i][j];}
            cout<<endl;
        }
        */
        AdjList.assign(con1,{});
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(fil[i][j]!=-1)
                    AdjList[fil[i][j]].push_back(col[i][j]);
            }
        }


        match.assign(con2,-1);
        for(int i=0;i<con1;i++){
          
            vis.assign(con1,0);
            MCBM+=Aug(i);
        }
        cout<<MCBM<<endl;
    }








    
}