//12403 Save Shetu

#include <cstdio>
#include <string.h>
int main(){
    int t,k,can=0;
    char o[10];
    scanf("%d",&t);
    while(t--){
        scanf("%s",o);
        if(strcmp(o,"donate")==0){
            scanf("%d",&k);
            can+=k;
        }
        else if(strcmp(o,"report")==0){
            printf("%d\n",can);
        }
    }

}
