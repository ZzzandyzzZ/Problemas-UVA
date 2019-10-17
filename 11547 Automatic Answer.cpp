//11547 Automatic Answer

#include <cstdio>
#include <cmath>
using namespace std;
int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        n=abs((n*567/9+7492)*235/47-498);
        printf("%d\n",(n/10)%10);
    }

}
