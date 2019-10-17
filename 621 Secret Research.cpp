//621 Secret Research

#include <cstdio>
#include <string.h>
int main(){
    int n,tam;
    char cas[1000000];
    scanf("%d",&n);
    while(n--){
        scanf("%s",cas);
        tam=strlen(cas);
        if(strcmp(cas,"1")==0||strcmp(cas,"4")==0||strcmp(cas,"78")==0){
            printf("+\n");
        }
        else if(cas[tam-1]=='5'&&cas[tam-2]=='3'){
            printf("-\n");
        }
        else if(cas[0]=='9'&&cas[tam-1]=='4'){
            printf("*\n");
        }
        else if(strncmp(cas,"190",3)==0){
            printf("?\n");
        }
        else{
            printf("+\n");
        }
    }


}
