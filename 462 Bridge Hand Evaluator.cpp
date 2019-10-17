//462 Bridge Hand Evaluator

#include <bits/stdc++.h>

using namespace std;

int main(){
	char carta[2];
	int con,A,ma,j;
	vector <int> mazos;
	vector <vector<int> > esp;
	map <char,int> valor;
	char palos[4]={'S','H','D','C'};
	valor['S']=0;
	valor['H']=1;
	valor['D']=2;
	valor['C']=3;
	while(true){
		con=A=0;
		mazos.assign(4,0);
		esp.assign(4,{});
		for(int i=0;i<4;i++)
			esp[i].assign(4,0);
		for(int i=0;i<13;i++){
			if(scanf("%2s",carta)==EOF)return 0;
			switch (carta[0]){
				case 'A':
					con+=4;
					esp[valor[carta[1]]][3]=1;
					
				break;
				case 'K':
					con+=3;
					esp[valor[carta[1]]][0]=1;
				break;
				case 'Q':
					con+=2;
					esp[valor[carta[1]]][1]=1;
				break;
				case 'J':
					con++;
					esp[valor[carta[1]]][2]=1;
				break;
			}
			mazos[valor[carta[1]]]++;
		}
		//cout<<con<<endl;
		for(int i=0;i<4;i++){
			if(esp[i][0]==1&&mazos[i]==1)con--;
			if(esp[i][1]==1&&mazos[i]<=2)con--;
			if(esp[i][2]==1&&mazos[i]<=3)con--;
		}	
		//cout<<con<<endl;
		for(int i=0;i<4;i++){
			if(esp[i][3]==1)A++;
			else if(esp[i][0]&&mazos[i]>=2)A++;
			else if(esp[i][1]&&mazos[i]>=3)A++;
		}
		if(con>=16&&A==4){
			cout<<"BID NO-TRUMP"<<endl;
		}
		else{
		for(int i=0;i<4;i++){
			if(mazos[i]==2)con++;
			else if(mazos[i]<=1)con+=2;
		}
		//cout<<con<<endl;

/*
		for(int i=0;i<4;i++)
			cout<<mazos[i]<<" ";
		cout<<endl;
		cout<<con<<endl;
*/
		if(con<14)cout<<"PASS"<<endl;
		else{
			ma=j=0;
			for(int i=0;i<4;i++){
				if(mazos[i]>ma){
					ma=mazos[i];
					j=i;
				}
				
			}
			cout<<"BID "<<palos[j]<<endl;
		}
	}
		//cout<<con<<endl;
		//cout<<A<<endl;
		
	}
		
}