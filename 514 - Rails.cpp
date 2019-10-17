#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
void mostrar(stack<int> v){
    stack<int> aux;
    aux=v;
    while(!aux.empty()){
        cout<<aux.top()<<" ";
        aux.pop();
    }
    cout<<endl;
}
void mostrar(queue<int> v){
    queue<int> aux;
    aux=v;
    while(!aux.empty()){
        cout<<aux.front()<<" ";
        aux.pop();
    }
    cout<<endl;
}
bool ordenar(vector<int> sa,int N){
    stack<int> st;
    queue<int> en;
    for(int i=0;i<N;i++){
        en.push(i+1);
    }
    for(int j=0;j<N;j++){
        //cout<<sa[j]<<" :"<<endl;
        if(!st.empty()&&sa[j]==st.top()){
            st.pop();
        }
        else{
            if(en.empty()||sa[j]<en.front()){return false;}

            while(!en.empty()){
                //cout<<"stack"<<endl;
                if(sa[j]!=en.front()){
                    st.push(en.front());
                    en.pop();
                }
                else{
                    en.pop();
                    break;
                }
            }
        }

        //mostrar(st);
        //mostrar(en);
    }
    return true;


}
int main(){
    int N,v;

    while(cin>>N,N!=0){
        //cout<<"A"<<endl;
        while(cin>>v,v!=0){
            vector <int> sa;
            //cout<<"B"<<endl;
            sa.push_back(v);
            for(int i=0;i<N-1;i++){
                cin>>v;
                sa.push_back(v);
            }
            if(ordenar(sa,N)==true){cout<<"Yes"<<endl;}
            else{cout<<"No"<<endl;}
        }
        cout<<endl;
    }


}
