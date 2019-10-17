//12279 Emoogle Balance

#include <cstdio>

int main(){
    int N,cas=1,x,ceros,others;
    while(scanf("%d",&N),N){
        ceros=0;
        others=0;
        while(N--){
            scanf("%d",&x);
            if(x==0){ceros++;}
            else{others++;}
        }
        printf("Case %d: %d\n",cas++,others-ceros);
    }


}
