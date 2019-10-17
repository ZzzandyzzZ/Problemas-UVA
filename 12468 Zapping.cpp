//12468 Zapping
#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    int a,b;
    while(scanf("%d %d",&a,&b),a>=0,b>=0){
        if(a>b)swap(a,b);
        b-a<99-b+a+1?printf("%d\n",b-a):printf("%d\n",99-b+a+1);
    }


}
