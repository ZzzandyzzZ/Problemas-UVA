#include <iostream>
#include<string>
using namespace std;

int error(string p,int ta){
    int c=0,c2=0;
    string letras[3]={"one","two","three"};
    if (ta ==3){
        for(int i=0;i<3;i++){
            if(p[i]==letras[0][i]){
                c++;
            }
            if (p[i]==letras[1][i]){
                c2++;
            }
        }
        if(c>=2){return 1;}
        else if(c2>=2){return 2;}
    }
    else if (ta==5){
        for(int i=0;i<5;i++){
           if(p[i]==letras[2][i]){
                c++;
            }
        }
        if (c>=4){return 3;}
    }

}

int main(){
    int c;
    string p;
    cin>>c;
    for(int i=0;i<c;i++){
        cin>>p;
        cout<<error(p,p.size())<<endl;
    }
}
