//11679 Sub-prime

#include <cstdio>
#include <vector>
using namespace std;
void comprobar(vector <int> a){
    for(int i=0;i<a.size();i++){
        if(a[i]<0){
            printf("N\n");
            return;
        }
        //printf("%d*",a[i]);
    }
    printf("S\n");
}
int main(){
    int N,B,R;
    int D,C,V;
    vector <int> banks;

    while(scanf("%d %d",&B,&N),B,N){
        banks.assign(B,0);
        for(int i=0;i<B;i++){
            scanf("%d",&banks[i]);
        }
        while(N--){
            scanf("%d %d %d",&D,&C,&V);
            banks[D-1]-=V;
            banks[C-1]+=V;
        }
        comprobar(banks);

    }


}
