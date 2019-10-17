//12554 A Special “Happy Birthday” Song!!!
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
    int n,ns,aux=0;
    string per;
    vector <string> song(16);
    song[0]="Happy";
    song[1]="birthday";
    song[2]="to";
    song[3]="you";
    song[4]="Happy";
    song[5]="birthday";
    song[6]="to";
    song[7]="you";
    song[8]="Happy";
    song[9]="birthday";
    song[10]="to";
    song[11]="Rujia";
    song[12]="Happy";
    song[13]="birthday";
    song[14]="to";
    song[15]="you";

    cin>>n;
    vector <string> lper(n);
    for(int i=0;i<n;i++){
        cin>>lper[i];
    }
    ns=n/16+1;
    while(ns--){
        for(int i=0;i<16;i++){
            if(aux==n)aux=0;
            cout<<lper[aux]<<": "<<song[i]<<endl;
            aux++;
        }
    }
}
