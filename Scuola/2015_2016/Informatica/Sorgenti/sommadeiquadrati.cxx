#include <iostream>
#include <math.h>
using namespace std;

int main(){
	int n=1,i,c=0;
	
	cout<<"Per terminare il ciclo scrivere 0";
	while(n!=0){
		cout<<"\nInserisci un numero: ";
		cin>>n;
		if(n>0){
			i=n;
			i=pow(i,2);
			c=c+i;
			}
		}
	cout<<"\n"<<c;	
	return 1;	
	}
