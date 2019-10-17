//10300 Ecological Premium

#include <cstdio>

int main(){
    int n,f,n1,n2,n3,t;
    scanf("%d",&n);
    while(n--){
        t=0;
        scanf("%d",&f);
        while(f--){
            scanf("%d %d %d",&n1,&n2,&n3);
            t+=n1*n3;
        }
        printf("%d\n",t);
    }

}
