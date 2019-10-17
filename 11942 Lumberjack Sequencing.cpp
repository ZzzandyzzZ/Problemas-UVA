//11942 Lumberjack Sequencing

#include <cstdio>

int main(){
    int N,l1,l2;
    bool as,des;
    scanf("%d",&N);
    printf("Lumberjacks:\n");
    while(N--){
        as=des=true;
        scanf("%d",&l1);
        for(int i=1;i<10;i++){
            scanf("%d",&l2);
            if(l1>l2)as=false;
            if(l1<l2)des=false;
            l1=l2;
        }
        if(as||des)printf("Ordered\n");

        else printf("Unordered\n");
    }

}
