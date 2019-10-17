//1061  Consanguine Calculations
#include <bits/stdc++.h>
using namespace std;
string v[6][8]={
"O+","O-","","","","","",""
,"O+","O-","A+","A-","","","",""
,"O+","O-","B+","B-","","","",""
,"B+","B-","A+","A-","","","",""
,"AB+","AB-","B+","B-","A+","A-","",""
,"O+","O-","AB+","AB-","B+","B-","A+","A-"};

pair<int,int> m[8][8]={
 make_pair(0,1),make_pair(0,1),make_pair(3,1),make_pair(3,1),make_pair(2,1),make_pair(2,1),make_pair(1,1),make_pair(1,1)
,make_pair(0,1),make_pair(0,0),make_pair(3,1),make_pair(3,0),make_pair(2,1),make_pair(2,0),make_pair(1,1),make_pair(1,0)

,make_pair(3,1),make_pair(3,1),make_pair(4,1),make_pair(4,1),make_pair(4,1),make_pair(4,1),make_pair(4,1),make_pair(4,1)
,make_pair(3,1),make_pair(3,0),make_pair(4,1),make_pair(4,0),make_pair(4,1),make_pair(4,0),make_pair(4,1),make_pair(4,0)

,make_pair(2,1),make_pair(2,1),make_pair(4,1),make_pair(4,1),make_pair(2,1),make_pair(2,1),make_pair(5,1),make_pair(5,1)
,make_pair(2,1),make_pair(2,0),make_pair(4,1),make_pair(4,0),make_pair(2,1),make_pair(2,0),make_pair(5,1),make_pair(5,0)

,make_pair(1,1),make_pair(1,1),make_pair(4,1),make_pair(4,1),make_pair(5,1),make_pair(5,1),make_pair(1,1),make_pair(1,1)
,make_pair(1,1),make_pair(1,0),make_pair(4,1),make_pair(4,0),make_pair(5,1),make_pair(5,0),make_pair(1,1),make_pair(1,0)
};
map<string,int> mp;

bool search(int a,string c){
    bool cp=true;
    int i,k;
    if(a%2!=0&&mp[c]%2==0){
        i=0;
        k=2;
    }
    else{i=0;k=1;}
    for(;i<8;i+=k){
        pair<int,int>aux=m[a][i];
        for(int j=0;j<8;j++){
            if(v[aux.first][j]==c){
                if(cp){
                    printf("{");
                    cout<<v[5][i];
                    cp=false;
                }
                else {
                    cout<<", "<<v[5][i];
                }
            }
        }
    }
    return cp;
}
int main(){
    int cas=1;

    
    for(int i=0;i<8;i++)mp[v[5][i]]=i;
    string a,b,c;
    int i,j;
    /*
    for(map<string,int>::iterator it =mp.begin();it!=mp.end();it++)
        cout<<it->first<<" "<<it->second<<"*";
    cout<<endl;*/
    while(cin>>a>>b>>c){
        if(a=="E"&&b=="N"&&c=="D")break;
        printf("Case %d: ",cas++);
        if(a=="O-"&&b=="O-"){
            cout<<a<<" "<<b<<" O-"<<endl;
            continue;
        }
        if(a=="?"){
            if(search(mp[b],c)){
                printf("IMPOSSIBLE ");
            }
            else printf("} ");

            cout<<b<<" "<<c<<endl;
        }
        else if(b=="?"){
            cout<<a<<" ";
            if(search(mp[a],c)){
                printf("IMPOSSIBLE ");
            }
            else printf("} ");
            cout<<c<<endl;
        }
        else if(c=="?"){
            pair<int,int> aux=m[mp[a]][mp[b]];
            if(aux.second==0){i=1;j=2;}
            else{i=0;j=1;}
            cout<<a<<" "<<b<<" {";
            cout<<v[aux.first][i];i+=j;
            for(;i<8;i+=j){
                if(v[aux.first][i]=="")break;
                cout<<", "<<v[aux.first][i];
            }
            printf("}\n");
        }
    }


}






    /*
    v[0]={"O+","O-","","","","","",""};
    v[1]={"O+","O-","A+","A-","","","",""};
    v[2]={"O+","O-","B+","B-","","","",""};
    v[3]={"B+","B-","A+","A-","","","",""};
    v[4]={"AB+","AB-","B+","B-","A+","A-","",""};
    v[5]={"O+","O-","AB+","AB-","B+","B-","A+","A-"};
    */

        /*
    m[0]={{0,1},{0,1},{3,1},{3,1},{2,1},{2,1},{1,1},{1,1}};
    m[1]={{0,1},{0,0},{3,1},{3,0},{2,1},{2,0},{1,1},{1,0}};

    m[2]={{3,1},{3,1},{4,1},{4,1},{4,1},{4,1},{4,1},{4,1}};
    m[3]={{3,1},{3,0},{4,1},{4,0},{4,1},{4,0},{4,1},{4,0}};

    m[4]={{2,1},{2,1},{4,1},{4,1},{2,1},{2,1},{5,1},{5,1}};
    m[5]={{2,1},{2,0},{4,1},{4,0},{2,1},{2,0},{5,1},{5,0}};

    m[6]={{1,1},{1,1},{4,1},{4,1},{5,1},{5,1},{1,1},{1,1}};
    m[7]={{1,1},{1,0},{4,1},{4,0},{5,1},{5,0},{1,1},{1,0}};
    */