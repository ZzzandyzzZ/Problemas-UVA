//10286	Trouble with a Pentagon
#include <bits/stdc++.h>

using namespace std;
int main(){
    double N,PI = acos(-1.0);
    while(cin>>N)
        cout<<fixed<<setprecision(10)<<N*sin(108*PI/180)/sin(63*PI/180)<<endl;
    return 0;
}