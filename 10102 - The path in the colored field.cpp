//10102 - The path in the colored field

#include <bits/stdc++.h>

using namespace std;

int main(){
    int m,mi,temp,ma;
    string linea;
    vector<pair<int,int>> unos;
    vector<pair<int,int>> tres;
    while(scanf("%d",&m)!=EOF){
        ma=-9999999;
        unos.clear();
        tres.clear();
        for(int i=0;i<m;i++){
            cin>>linea;
            for(int j=0;j<m;j++){
                if(linea[j]=='1'){
                    unos.push_back({i,j});
                }
                else if(linea[j]=='3'){
                    tres.push_back({i,j});
                }
            }
        }
        for(int i=0;i<unos.size();i++){
            mi=9999999;
            for(int j=0;j<tres.size();j++){
                temp=abs(unos[i].first-tres[j].first)+abs(unos[i].second-tres[j].second);
               // cout<<temp<<"**"<<mi<<endl;
                if(temp<mi)mi=temp;
            }
            //cout<<"___"<<endl;
            if(mi>ma)ma=mi;
        }

        /*
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++)
            cout<<M[i][j]<<" ";
            cout<<endl;}
        */
        cout<<ma<<endl;
    }


}
