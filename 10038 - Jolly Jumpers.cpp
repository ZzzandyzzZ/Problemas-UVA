
#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int main()
{
    int b[3001]={},a,comprobar=0;
    while(cin>>a){
        if(a==0){break;}
        cin>>b[0];
        for(int i=1;i<a;i++){
            cin>>b[i];
            b[i-1]=abs(b[i]-b[i-1]);
        }
        b[a-1]={0};
        sort(b,b+3001,greater< int >());
        for(int i=0;i<a-1;i++){
            if (b[i]-b[i+1]!=1){comprobar++;}
        }
        if(comprobar>0){cout<<"Not jolly"<<endl;}
        else{cout<<"Jolly"<<endl;}
        comprobar=0;
    }
    return 0;
}

/*
#include <iostream>
#include <algorithm>

using namespace std;

const int SIZE = 7;

int main()
{
    int intArray[SIZE] = {5, 3, 32, -1, 1, 104, 53};

    //Now we call the sort function
    sort(intArray, intArray + SIZE);

    cout << "Sorted Array looks like this." << endl;
    for (size_t i = 0; i != SIZE; ++i)
        cout << intArray[i] << " ";

    return 0;
}
*/
