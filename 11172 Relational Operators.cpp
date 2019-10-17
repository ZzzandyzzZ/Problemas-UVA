#include <stdio.h>

using namespace std;

int main(){
    int n;
    int i,j;
    scanf("%d",&n);
    while(n--){
        scanf("%d %d",&i,&j);
        if(i<j){
            printf("<\n");
        }
        else if(i>j){
            printf(">\n");

        }
        else{
            printf("=\n");
        }
    }
}
