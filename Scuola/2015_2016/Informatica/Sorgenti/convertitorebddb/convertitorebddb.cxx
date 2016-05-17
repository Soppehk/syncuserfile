#include <iostream>
#include <math.h>
#define max 10
using namespace std;

void Inizializzazione(int numcon[]){
	for(int i=0;i<max;i++){
		numcon[i]=0;
	}
	return;
}

void InputDec(int &num){
	do{
		cout<<"\nInserisci un numero positivo minore di 1024: ";
		cin>>num;
	}while((num<0)||(num>=1024));
	return;
}

void InputBin(int &num){
	do{
		cout<<"\nInserisci un numero positivo minore di 100000000: ";
		cin>>num;
	}while((num<0)||(num>=100000000));
	return;
}

void DecToBin(int num, int numcon[]){
	int i=0;		
	while(i<max)	
	{
		if((num%2)==0)	
		{
			numcon[max-1-i]=0;	
		} else {
			numcon[max-1-i]=1;	
		}
		num=num/2;		
		i++;		
	}	
	return;
}

void BinToDec(int num, int &numcondec){
	int rest;
	
	for(int i=0;num>0;i++)
	{
		rest=num%10;
		num=num/10;
		numcondec=numcondec+rest*pow(2,i);	
	}
	
	return;
}

void Stampa(int numcon[]){
	for(int i=0;i<max;i++){
		cout<<numcon[i];
	}
	return;
}
int main(){
	int scelta, num, numcondec, numconbin[max];
	
	
	do{
		cout<<"\nInserisci 1 per conversione binario=>decimale o 2 per conversione decimale=>binario: ";
		cin>>scelta;
		if((scelta!=1)&&(scelta!=2)){
			cout<<"\nScelta non valida!";
		}
	}while((scelta!=1)&&(scelta!=2));
	
	switch(scelta){
		case 1:	
				InputBin(num);
				BinToDec(num,numcondec);
				cout<<"\n"<<numcondec;
				break;
		case 2: Inizializzazione(numconbin);
				InputDec(num);
				DecToBin(num,numconbin);
				Stampa(numconbin);
				break;
	}
	
	return 1;
}
