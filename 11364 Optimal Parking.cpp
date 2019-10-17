//11364 Optimal Parking

#include <cstdio>
#include <cmath>
using namespace std;
int main(){
    int t,n,x,mi,ma;
    scanf("%d",&t);
    while(t--){
        mi=100;
        ma=-1;
        scanf("%d",&n);
        while(n--){
            scanf("%d",&x);
            if(x>ma)ma=x;
            if(x<mi)mi=x;
        }
        printf("%d\n",2*(ma-mi));

    }

}
