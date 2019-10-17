//11332 Summing Digits

#include <cstdio>
long long int digit( long long int a){
    if(a<10)return a;
    long long int aux=0;
    while(a>9){
        aux+=a%10;
        a/=10;
    }
    digit(a+aux);

}
int main(){
    long long int n;
    while(scanf("%lld",&n)){
        if(n==0)break;
        printf("%lld\n",digit(n));
    }
    return 0;

}
