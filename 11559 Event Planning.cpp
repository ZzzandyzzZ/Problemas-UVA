//11559 Event Planning

#include <cstdio>

int main(){
    int n,b,h,w,w1,p,total;
    while(scanf("%d %d %d %d",&n,&b,&h,&w)!=EOF){
        //printf("A\n");
        total=0;
        while(h--){
            scanf("%d",&p);
            for(int i=0;i<w;i++){
                scanf("%d",&w1);
                if(n<=w1){
                    if(n*p<=b){
                        if(total==0||total>n*p)total=n*p;
                    }
                }
                //aprintf("%d\n",total);
            }
        }
        if(total==0){printf("stay home\n");}
        else{printf("%d\n",total);}
    }


}
