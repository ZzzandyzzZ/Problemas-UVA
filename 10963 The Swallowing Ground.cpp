//10963 The Swallowing Ground

#include <cstdio>

int main(){
    int n,w,y1,y2,con;
    bool com;
    scanf("%d",&n);
    while(n--){
        scanf("\n\n%d",&w);
        com=true;
        scanf("%d %d",&y1,&y2);
        con=y1-y2;
        w--;
        while(w--){
            scanf("%d %d",&y1,&y2);
            if(con!=y1-y2)com=false;
        }
        if(com)printf("yes\n");
        else{
            printf("no\n");
        }
        if(n!=0){
            printf("\n");
        }
    }


}
