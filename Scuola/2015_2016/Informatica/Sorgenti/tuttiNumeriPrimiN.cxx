#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
    int n,i=1,c,r;
    bool primo=true;
    
    do{
       cout<<"\nInserisci un numero maggiore di zero: ";
       cin>>n;
	}while(n<=0);
	
	do{ c=2;
		while(c<=i){
			r=i%c;
			if(r==0){
				primo=false;
				}
				c++;
				}
		if(primo){
			cout<<"\n"<<i<<" e' primo";
			}
		else{
			cout<<"\n"<<i<<" non e' primo";
			}		
		i++;		
	}while(i<=n);
	
    getchar();
    return 1;
    }
