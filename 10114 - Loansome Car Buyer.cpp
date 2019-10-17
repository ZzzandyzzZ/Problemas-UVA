#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

double convertir(string a){
    double aux=0;
    for(int i=1;i<a.size();i++){
        aux+=(a[i]-'0')/(pow(10,i));
    }
    return aux;
}

int main(){
    //duracion del prestamo
    //pago inicial
    //monto prestamo
    //numero de registros
    long long du,nr,me,con=0;
    double pi,mp,total;
    double d;
    string re;
    while(cin>>du>>pi>>mp>>nr,du>0){
        vector <double> v(du+10,0);
        total=pi+mp;
        pi=mp/du;
        //cout<<total<<endl;
        for(int i=0;i<nr;i++){
            cin>>me>>re;
            d=1-convertir(re);

            v[me]=d;
        }
        con=0;

            d=v[con];
            total*=d;
            while(total<mp){
                con++;
                if(v[con]!=0){d=v[con];}
                total*=(d);
                mp-=pi;

                du--;
                //cout<<setprecision(30)<<total<<" "<<mp<<endl;
            }

        if(con==1){cout<<"1 month"<<endl;}
        else{cout<<con<<" months"<<endl;}



    }

}
