//259 - Software Allocation

#include <bits/stdc++.h>

using namespace std;

int cas=1,con,MCBM,con2;
vector<char> letras;
vector<bool> vis;
vector<int> match;
vector<vector<int> >AdjList;
char linea[100];

void mostrar(){
    for(int i=0;i<con;i++){
        cout<<i<<"=";
        for(int j=0;j<AdjList[i].size();j++){
            cout<<AdjList[i][j]<<" ";
        }
        cout<<endl;
    }
}

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
    
    while(1){
        //cout<<"A"<<endl;
        
        con=MCBM=0;
        AdjList.clear();
        letras.clear();
        if(gets(linea)==0)break;
        do{
            if(strcmp(linea,"")==0)break;

            for(int i=0;i<(linea[1]-'0');i++){
                AdjList.push_back({});
                letras.push_back(linea[0]);
                for(int j=3;;j++){
                    if(linea[j]==';')break;
                    AdjList[con].push_back(linea[j]-'0');
                }
                con++;
            }
        }while(gets(linea));
       // mostrar();
        match.assign(10,-1);
        //cout<<con<<endl;
        for(int i=0;i<con;i++){
            vis.assign(con,0);
            MCBM+=Aug(i);
        }
        if(MCBM<con){
            cout<<"!"<<endl;
            
        }
        else{
        for(int i=0;i<10;i++){
            if(match[i]==-1)cout<<"_";
            else cout<<letras[match[i]];
        }
        cout<<endl;
        }
        /*
        for(int i=0;i<con;i++){
            cout<<match[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<con;i++){
            cout<<letras[i]<<" ";
        }
        cout<<endl;*/

        //cout<<MCBM<<endl;
        
    }

}