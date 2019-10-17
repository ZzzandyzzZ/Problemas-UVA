//backtracking

#include <bits/stdc++.h>

using namespace std;
int n,to,sum=0,ma=0,cd_max=0;
vector <int> res,value,l_max;
void mostrar(){
    for(int i=0;i<n;i++)
        if(l_max[i]!=0)
            printf("%d ",l_max[i]);

}
void Backtracking (int c,int v,int cd){
    if(c==n){
        if(v==to&&cd>=cd_max){
            //cout<<"RPTA";mostrar();
            ma=v;
            copy(res.begin(),res.end(),l_max.begin());
            cd_max=cd;
            //cout<<"= "<<v<<endl;
            return;
        }
        else if(v>ma&&v<to&&cd>cd_max){
            ma=v;
            copy(res.begin(),res.end(),l_max.begin());
            cd_max=cd;
            //cout<<"posible";mostrar();
            //cout<<"= "<<v<<endl;
            return;
        }
        //mostrar();
        //cout<<"= "<<v<<endl;
        return;
    }
    res[c]=value[c];
    Backtracking(c+1,value[c]+v,cd+1);
    res[c]=0;
    Backtracking(c+1,v,cd);
}


int main(){
    while(scanf("%d %d",&to,&n)!=EOF){
        sum=0,ma=0,cd_max=0;
        res.resize(n);
        value.resize(n);
        l_max.resize(n);
        for(int i=0;i<n;i++){
            scanf("%d",&value[i]);
        }
        Backtracking(0,0,0);
        mostrar();
        printf("sum:%d\n",ma);
    }
;



}
