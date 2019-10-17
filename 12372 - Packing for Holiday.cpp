//12372 - Packing for Holiday

#include <cstdio>

int main(){
    int cas=1,N,L,W,H;
    scanf("%d",&N);
    while(N--){
        scanf("%d %d %d",&L,&W,&H);
        if(L>20||W>20||H>20)printf("Case %d: bad\n",cas++);
        else{printf("Case %d: good\n",cas++);}
    }

}
