//12157 Tariff Plan

#include <cstdio>

int main(){
    int T,N,cas=1,n,t1,t2,aux;
    scanf("%d",&T);
    while(T--){
        t1=t2=0;
        scanf("%d",&N);
        while(N--){
            scanf("%d",&n);
            aux=n/29;
            if(n%29>=aux){aux++;}
            t1+=(aux*10);
            aux=n/59;
            if(n%59>=aux){aux++;}
            t2+=(aux*15);
            //printf("%d+-+%d\n",t1,t2);
        }
        printf("Case %d: ",cas++);
        if(t1<t2){printf("Mile %d\n",t1);}
        else if(t1>t2){printf("Juice %d\n",t2);}
        else{printf("Mile Juice %d\n",t1);}
    }



}
