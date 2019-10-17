#include <iostream>
#include <string>
using namespace std;

int main(){
    int L,pos;
    string ey[4]={"+x","+y","-x","-y"};
    string ez[4]={"+x","+z","-x","-z"};
    string mov,dir;
    while(cin>>L,L!=0){
        pos=0;
        dir=ez[pos];
        for(int i=0;i<L-1;i++){
            cin>>mov;
            if(mov=="No"){continue;}
            else if(mov[1]=='z'){
                //cout<<"A: ";
                if(dir==ey[1] || dir==ey[3]){
                    continue;
                }
                else{
                    if(mov[0]=='+'){
                        pos++;
                        if(pos>3){pos-=4;}
                    }
                    else{
                        pos--;
                        if(pos<0){pos+=4;}

                    }
                    dir=ez[pos];
                }
            }
            else if(mov[1]=='y'){
                //cout<<"B: ";
                if(dir==ez[1] || dir==ez[3]){
                    continue;
                }
                else{
                    if(mov[0]=='+'){
                        pos++;
                        if(pos>3){pos-=4;}
                    }
                    else{
                        pos--;
                        if(pos<0){pos+=4;}
                    }
                    dir=ey[pos];
                }

            }
            //cout<<dir<<endl;
        }
        cout<<dir<<endl;
    }


}
