//1103 - Ancient Messages


#include <bits/stdc++.h>

using namespace std;

int con,cas=1,H,W;;
vector<vector<bool> >visit;
vector<vector<int> >MA;
vector<string>ma;

void mostrar(){
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cout<<MA[i][j];
        }
        cout<<endl;
    }
}
void DFS(int i,int j){
    if(i<0||j<0||i==H||j==W)return;
    if(visit[i][j]||ma[i][j]=='0')return;
    visit[i][j]=true;
    MA[i][j]=con;
    DFS(i+1,j);
    DFS(i,j+1);
    DFS(i-1,j);
    DFS(i,j-1);
}
int DFS2(int i,int j){
    cout<<i<<" "<<j<<endl;
    if(i<0||j<0||i==H||j==W)return -1;
    if(visit[i][j]&&ma[i][j]=='0')return 0;
    if(MA[i][j]>0)return MA[i][j];
    visit[i][j]=true;
    MA[i][j]=9;
    int a=DFS2(i+1,j);
    int b=DFS2(i,j+1);
    int c=DFS2(i-1,j);
    int d=DFS2(i,j-1);
    if(a==-1||b==-1||c==-1||d==-1)return -1;
    else return a;
}


int main(){
    map<char,string> mp;
    mp['0']="0000";mp['4']="0100";mp['8']="1000";mp['c']="1100";
    mp['1']="0001";mp['5']="0101";mp['9']="1001";mp['d']="1101";
    mp['2']="0010";mp['6']="0110";mp['a']="1010";mp['e']="1110";
    mp['3']="0011";mp['7']="0111";mp['b']="1011";mp['f']="1111";

    
    string linea;
    while(scanf("%d %d",&H,&W)){
        if(H==0&&W==0)break;
        W*=4;
        con=1;
        visit.assign(H,{});
        for(int i=0;i<H;i++)visit[i].assign(W,false);
        MA.assign(H,{});
        for(int i=0;i<H;i++)MA[i].assign(W,0);
        ma.assign(H,"");

        for(int i=0;i<H;i++){
            cin>>linea;
            for(char j:linea){
                ma[i]+=mp[j];
            }
        }

        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                if(ma[i][j]=='1'&&!visit[i][j]){
                    DFS(i,j);
                    con++;
                }
            }
        }

        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                if(ma[i][j]=='0'&&!visit[i][j])
                    cout<<DFS2(i,j)<<endl;
            }
        }
        mostrar();

    }


}