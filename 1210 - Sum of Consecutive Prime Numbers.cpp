//1210 - Sum of Consecutive Prime Numbers
#include <bits/stdc++.h>
using namespace std;
#define N 1000001

vector<int> primes;
bitset<N> bs;
void sieve(){
    bs.set();
    primes.push_back(2);
    for(long long i=3;i<N;i+=2){
        if(bs[i]){
            primes.push_back(i);
            for(long long j=i*i;j<N;j+=i<<1)
                bs[j]=0;
        }
    }
}
int suma(long long a){
    int sum,total=0;
    for(int i=0;i<primes.size();i++){
        sum=0;
        if(primes[i]>a)break;
        for(int j=i;j<primes.size();j++){
            sum+=primes[j];
            if(sum==a)total++;
            if(sum>a)break;
        }
    }
    return total;
}
int main(){
    sieve();
    long long a;
    while(scanf("%lld",&a)){
        if(a==0)break;
        cout<<suma(a)<<endl;
    }
}