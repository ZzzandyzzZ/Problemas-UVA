//12577 Hajj-e-Akbar
#include <cstdio>
#include <string.h>
int main(){
    char ca[10];
    int cas=1;
    while(scanf("%s",ca)){
        if(strcmp(ca,"*")==0)break;
        if(strcmp(ca,"Hajj")==0){
            printf("Case %d: Hajj-e-Akbar\n",cas++);
        }
        else{
            printf("Case %d: Hajj-e-Asghar\n",cas++);
        }
    }



}
