//11995 I Can Guess the Data Structure!

#include <cstdio>
#include <queue>
#include <stack>

using namespace std;
int main(){
    int n;
    int n1,n2;
    bool a,b,c;

    while(scanf("%d",&n)!=EOF){
        a=b=c=true;
        queue <int> A;
        priority_queue <int> B;
        stack <int> C;
        while(n--){
            scanf("%d %d",&n1,&n2);
            if(n1==1){
                if(a){
                    A.push(n2);
                }
                if(b){
                    B.push(n2);
                }
                if(c){
                    C.push(n2);
                }
            }
            else if (n1==2){
                if(a){
                    if(!A.empty()&&A.front()==n2){A.pop();}
                    else{a=false;}
                }
                if(b){
                    if(!B.empty()&&B.top()==n2){B.pop();}
                    else{b=false;}
                }
                if(c){
                    if(!C.empty()&&C.top()==n2){C.pop();}
                    else{c=false;}
                }
            }


        }
        if(a+b+c>1)printf("not sure\n");
        else if(a+b+c==0)printf("impossible\n");
        else if(a)printf("queue\n");
        else if(b)printf("priority queue\n");
        else if(c)printf("stack\n");

    }

}
