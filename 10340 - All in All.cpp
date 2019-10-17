#include <iostream>
#include <string>

using namespace std;

int main(){
    string s,t;
    int con;
    int pos;
    while(cin>>s>>t){
        con=pos=0;
        for(int i=0;i<t.size();i++){
            if(s[pos]==t[i]){con++;pos++;}
        }
        if(con==s.size()){cout<<"Yes"<<endl;}
        else{
            cout<<"No"<<endl;
        }
    }
}

