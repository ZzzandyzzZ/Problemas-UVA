#include <iostream>
#include <string>
#include <map>
#include <cstdio>
#include <iomanip>
using namespace std;

void mostrar(map<string,double> a,int total){
for(map<string,double>::const_iterator it = a.begin();it != a.end(); ++it){
    printf("%s %.4lf\n", (*it).first.data(),(double) (*it).second / (double) total * 100.0);
    }

}

int main(){
    int N,total;
    string aux;
    scanf("%d\n\n", &N);
    for(int i=0;i<N;i++){
        map<string,double> m;
        total=0;
        while(getline(cin,aux)){
        //cout<<"Case"<<endl;
           if(aux.size()==0){break;}
           total++;
            map<string,double>::iterator p = m.find(aux);
            if(p != m.end()){
                m[aux]++;
            }
            else{
                m[aux]=1;
            }

        //cout<<total<<endl;
        }

        mostrar(m,total);
        if(i!=N-1)cout<<endl;
    }



}
