//11044 Searching for Nessy


#include <cstdio>

int main(){
    int t,n,m;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        if(n%3>0){(n/=3)+1;}
        else{n/=3;}
        if(m%3>0){(m/=3)+1;}
        else{m/=3;}
        //printf("%d %d\n",m,n);
        printf("%d\n",m*n);


    }

}
