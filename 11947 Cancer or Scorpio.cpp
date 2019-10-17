#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
bool esBisiesto(int year)
{
     return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

string signoS(int dia,int mes){
    mes--;
    if(mes==0){
        if(dia>=21){
            return "aquarius";
        }
        return "capricorn";
    }
    else if(mes==1){
        if(dia>=20){
            return "pisces";
        }
        return "aquarius";
    }
    else if(mes==2){
        if(dia>=21){
            return "aries";
        }
        return "pisces";
    }
    else if(mes==3){
        if(dia>=21){
            return "taurus";
        }
        return "aries";
    }
     else if(mes==4){
        if(dia>=22){
            return "gemini";
        }
        return "taurus";
    }
    else if(mes==5){
        if(dia>=22){
            return "cancer";
        }
        return "gemini";
    }
    else if(mes==6){
        if(dia>=23){
            return "leo";
        }
        return "cancer";
    }
    else if(mes==7){
        if(dia>=22){
            return "virgo";
        }
        return "leo";
    }
    else if(mes==8){
        if(dia>=24){
            return "libra";
        }
        return "virgo";
    }
    else if(mes==9){
        if(dia>=24){
            return "scorpio";
        }
        return "libra";
    }
    else if(mes==10){
        if(dia>=23){
            return "sagittarius";
        }
        return "scorpio";
    }
    else if(mes==11){
        if(dia>=23){
            return "capricorn";
        }
        return "sagittarius";
    }

}
int main(){
    int n;
    int con;
    int pos;
    int dia,mes,ano;
    string date;
    string signo="";
    vector<int> meses(12);
    meses[0]=31;
    meses[1]=28;
    meses[2]=31;
    meses[3]=30;
    meses[4]=31;
    meses[5]=30;
    meses[6]=31;
    meses[7]=31;
    meses[8]=30;
    meses[9]=31;
    meses[10]=30;
    meses[11]=31;
    scanf("%d\n",&n);
    for(int i=1;i<=n;i++){
        con=0;
        meses[1]=28;
        getline(cin,date);
        mes=int(date[0]-'0')*10+int(date[1]-'0');
        dia=int(date[2]-'0')*10+int(date[3]-'0');
        ano=int(date[4]-'0')*1000+int(date[5]-'0')*100+int(date[6]-'0')*10+int(date[7]-'0');
        pos=mes-1;
        if(esBisiesto(ano)){meses[1]++;}
        con+=meses[pos]-dia;
        while(con<280){
            pos++;
            //printf("%d \n",con);
            if(pos==12){
                pos=0;ano++;
                if(!esBisiesto(ano)){meses[1]=28;}
            }
            con+=meses[pos];
        }
        //printf("%d-%d-%d\n",con,con-280,pos);
        if(pos==0){dia=meses[11]-(con-280);}
        else{dia=meses[pos]-(con-280);}
        mes=pos+1;
        signo=signoS(dia,mes);
        printf("%d ",i);
        if(mes<=9){printf("0");}
        printf("%d/",mes);
        if(dia<=9){printf("0");}
        printf("%d/%d %s\n",dia,ano,signo.c_str());

        //printf("%d %d/%d/%d %s\n",i,mes,dia,ano,signo.c_str());
    }

}
