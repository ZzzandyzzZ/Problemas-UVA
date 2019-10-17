#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int main(){
    int f,c;
    int r,aux,con;
    vector <int> p;
    while(cin>>f>>c){
        vector<vector<int> > M(c);
        for (int i=0;i<c;i++)
            M[i].resize(f);
        for(int h=0;h<f;h++){
            p.clear();
            cin>>r;
            for(int i=0;i<r;i++){
                cin>>aux;
                p.push_back(aux-1);
            }
            for(int i=0;i<r;i++){
                cin>>aux;

                M[p[i]][h]=aux;

            }

        }
        cout<<c<<" "<<f<<endl;
        for(int i=0;i<c;i++){
            p.clear();
            con=0;
            for(int j=0;j<f;j++){
                if(M[i][j]!=0){p.push_back(j+1);con++;}
            }
            cout<<con;
            if(con!=0){
                cout<<" ";
            }

            for(int j=0;j<con;j++){
                cout<<p[j];
                p[j]=M[i][p[j]-1];
                if(j!=con-1){cout<<" ";}
            }
            cout<<endl;
            for(int j=0;j<con;j++){
                cout<<p[j];
                if(j!=con-1){cout<<" ";}
            }
            cout<<endl;
        }

    }

}
