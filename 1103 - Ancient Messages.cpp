#include <bits/stdc++.h>

using namespace std;

int H,W,con;
map<char,string> sim;
map<int,char> simb;
vector<string> ma;
vector<int> lista;
vector<vector<int> > MA;
stack<pair<int,int> > st;
string linea;
vector<char> rpta;

void mostrar(){
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cout<<MA[i][j];
        }
        cout<<endl;
    }    
    cout<<endl;
}
int DFS2(int x,int y){

    if(x<0||y<0||x==H||y==W)return -1;
    if(MA[x][y]==-2)return 0;
    if(MA[x][y]!=0)return MA[x][y];
    MA[x][y]=-2;
    //mostrar();
    vector<int> v(4);

    v[0]=DFS2(x+1,y);
    if(v[0]==-1){MA[x][y]=-1;return -1;}
    v[1]=DFS2(x,y+1);
    if(v[1]==-1){MA[x][y]=-1;return -1;}
    v[2]=DFS2(x-1,y);
    if(v[2]==-1){MA[x][y]=-1;return -1;}
    v[3]=DFS2(x,y-1);
    if(v[3]==-1){MA[x][y]=-1;return -1;}

    MA[x][y]=-2;
    return v[0];

}
int DFS(int x,int y){
    if(x<0||y<0||x==H||y==W)return 0;
    if(ma[x][y]=='0')return 0;
    MA[x][y]=con;
    ma[x][y]='0';
    DFS(x+1,y);
    DFS(x,y+1);
    DFS(x-1,y);
    DFS(x,y-1);
}
/*
void DFS(){
    st.push({0,0});
    while(!st.empty()){
        int i =st.top().first,j=st.top().second;
        st.pop();
        if(MA[i][j]==0){
            MA[i][j]=-1;
            if(i-1>=0)st.push(i-1,j);
            if(j-1>=0)st.push(i,j-1);
            if(i+1<H)st.push(i+1,j);
            if(j+1<W)st.push(i,j+1);

        }


    }
}
*/
int main(){
    int cas=1;
    sim['0']="0000";sim['8']="1000";
    sim['1']="0001";sim['9']="1001";
    sim['2']="0010";sim['a']="1010";
    sim['3']="0011";sim['b']="1011";
    sim['4']="0100";sim['c']="1100";
    sim['5']="0101";sim['d']="1101";
    sim['6']="0110";sim['e']="1110";
    sim['7']="0111";sim['f']="1111";
    simb[0]='W';simb[3]='J';
    simb[1]='A';simb[4]='S';
    simb[2]='K';simb[5]='D';

    while(scanf("%d %d",&H,&W)){
        if(H==0&&W==0)break;

        con=1;
        ma.assign(H,"");
        MA.assign(H,{});
        rpta.clear();
        for(int i=0;i<H;i++)
            MA[i].assign(W*4,0);

        for(int i=0;i<H;i++){
            cin>>linea;
            for(int j=0;j<W;j++){
                ma[i]+=sim[linea[j]];
            }
        }
        W*=4;
        //for(int i=0;i<H;i++)cout<<ma[i]<<endl;cout<<endl;

        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                if(ma[i][j]=='1'){
                    DFS(i,j);
                    con++;
                }
            }
        }
        lista.assign(con,0);
        //mostrar();
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                if(MA[i][j]==0){
                    int aux=DFS2(i,j);
                    
                    if(aux!=-1)
                        lista[aux]++;
                }
            }
        }
        for(int j=1;j<con;j++){
            rpta.push_back(simb[lista[j]]);
        }
        sort(rpta.begin(),rpta.end());
        printf("Case %d: ",cas++);
        for(int j=0;j<con-1;j++){
            cout<<rpta[j];
        }
        printf("\n");
        //mostrar();
    }

}
