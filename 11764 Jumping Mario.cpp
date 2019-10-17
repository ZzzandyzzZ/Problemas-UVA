//11764 Jumping Mario

#include <cstdio>

int main(){
    int T,N,H,L,an,cas=1,n;
    scanf("%d",&T);
    while(T--){
        H=L=0;
        scanf("%d",&N);
        scanf("%d",&an);N--;
        while(N--){
            scanf("%d",&n);
            if(an<n)H++;
            else if(an>n)L++;
            an=n;
        }
        printf("Case %d: %d %d\n",cas++,H,L);


    }


}
