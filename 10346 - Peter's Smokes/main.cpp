#include <iostream>

using namespace std;

int main()
{
    int n,k,co=0;
    while(cin>>n,cin>>k){
        co=n;
        while(k<=n){
            co+=n/k;
            n=n/k+n%k;
        }
        cout<<co<<endl;
    }
    return 0;
}
