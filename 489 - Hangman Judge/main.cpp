#include <iostream>

using namespace std;

int main()
{

    int caso,con=0,con2=0,con3=0;
    string palabra,intentos,resultado;
    while(cin>>caso){
        if (caso<0){break;}
        cin>>palabra;
        cin>>intentos;
        if(palabra.size()==1){cout<<"Round "<<caso<<endl;
            for(int i =0;i<7;i++){
                con3=0;
            for(int j =0;j<7;j++){
                if(intentos[i]==palabra[j]){palabra[j]=' ';con3++;}
            }
            if(con3>=1 && intentos[i]!=' '){con++;}
            }
        if (con>=1){cout<<"You win."<<endl;}
        else{cout<<"You lose."<<endl;}
        con=0;con2=0;
        }
        else{
        for(int i =0;i<intentos.size();i++){
            for(int j =0;j<intentos.size();j++){
                if (i!=j && intentos[i]==intentos[j]){intentos[i]=' ';}
            }
        }
        for(int i =0;i<intentos.size();i++){
                con3=0;
            for(int j =0;j<palabra.size();j++){
                if(intentos[i]==palabra[j]){palabra[j]=' ';con3++;}
            }
            if(con3==0 && intentos[i]!=' '){con++;}
        }
        for(int j =0;j<palabra.size();j++){
            if (palabra[j]!=' '){con2++;}
        }
        cout<<"Round "<<caso<<endl;
        if (con>=7){cout<<"You lose."<<endl;}
        else if (con<=7 && con2>=1){cout<<"You chickened out."<<endl;}
        else {cout<<"You win."<<endl;}}
        con=0;con2=0;
    }
    return 0;
}
