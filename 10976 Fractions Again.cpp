//10976 Fractions Again?!
#include <cstdio>
#include <iostream>
using namespace std;


int n;
void sum(int i,int c){
    int xi;
    double xd;
    if(i==n){
        printf("%d\n",c);
        return ;
    }
    xd=double(i*n)/(i-n);
    xi=xd;

    if(xd-xi==0){
        sum(i-1,c+1);
        printf("1/%d = 1/%d + 1/%d\n",n,xi,i);
    }
    else
        sum(i-1,c);

}

int main(){
    while(scanf("%d",&n)!=EOF){
        sum(2*n,0);
    }

}


/*
int main(){
    double xd;
    int n,xi,con;
    while(scanf("%d",&n)!=EOF){
        con=0;
        for(int i=n+1;i<=n*2;i++){
            xd=double(i*n)/(i-n);
            xi=xd;
            if(xd-xi==0){
                con++;
                printf("1/%d = 1/%d + 1/%d\n",n,xi,i);
            }
        }


    }
    return 0;

}
*/
