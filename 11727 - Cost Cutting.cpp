#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	int T;
	vector<int> a(3);
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>a[0]>>a[1]>>a[2];
		sort(a.begin(),a.begin()+3);
		cout<<"Case "<<i<<": "<<a[1]<<endl;
	}



}
