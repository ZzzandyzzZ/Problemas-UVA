#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void mostrar(vector<int> a){
    for(int i=0;i<a.size();i++)
        cout<<a[i]<<" ";
    cout<<endl;

}
int main(){
    int T,N;
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>N;
        vector <int> team(N);
        for(int j=0;j<N;j++){
            cin>>team[j];
        }
        
        sort(team.begin(), team.begin()+N);
        
        cout<<"Case "<<i+1<<": "<<team[N/2]<<endl;
    }

}
