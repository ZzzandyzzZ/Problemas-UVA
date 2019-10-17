//10424	Love Calculator
#include <bits/stdc++.h>

using namespace std;

int main(){
	string P1,P2;
	int con1,con2,temp;

	while(getline(cin,P1)){
		con1=con2=0;
		getline(cin,P2);
		for(int i=0;i<P1.size();i++){
			temp=tolower(P1[i]);
			if(temp<=122&&temp>=97)
				con1+=(temp-96);
			//cout<<"A"<<con1<<endl;
			if(con1>9){
				con1=con1/10+con1%10;
			}
			if(con1==10)con1=1;
			//cout<<"B"<<con1<<endl;
		}
		for(int i=0;i<P2.size();i++){
			temp=tolower(P2[i]);
			if(temp<=122&&temp>=97)
				con2+=(temp-96);
			if(con2>9){
				con2=con2/10+con2%10;
			}	
			if(con2==10)con2=1;	
		}
		//cout<<con1<<endl;
		//cout<<con2<<endl;
		printf("%.2f \%\n",min(con1,con2)/float(max(con1,con2))*100);
	}
}