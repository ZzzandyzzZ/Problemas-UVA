//10235 - Simply Emirp

#include <bits/stdc++.h>

using namespace std;
#define N 1000001

vector<int> primes;
bitset<N> bs;
void sieve(){
    bs.set();
    bs[0]=bs[1]=0;
    for(long long i=2;i<N;i++){
        if(bs[i]){
            primes.push_back(i);
            for(long long j=i*i;j<N;j+=i)
                bs[j]=0;
        }
    }
}
long long inv(long long a){
    long long rpta=0;
    while(a>9){
        rpta+=(a%10);
        a/=10;
        rpta*=10;
    }
    rpta+=a;
    return rpta;
}
bool isprime(long long a){
    if(a<=N)return bs[a];
    for(int i=0;i<primes.size();i++){
        if(a%primes[i]==0)return false;
    }
    return true;
}
bool isemirp(long long a){
    long long b=inv(a);
    if(a==b)return false;
    return isprime(b);
}

int main(){
    long long a;
    sieve();
    while(scanf("%lld",&a)!=EOF){
        if(!isprime(a))printf("%lld is not prime.\n",a);
        else if(isemirp(a))printf("%lld is emirp.\n",a);
        else printf("%lld is prime.\n",a);
    }
}