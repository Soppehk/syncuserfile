#include <iostream>
using namespace std;

int Input(int n1, int n2, int& n){
	do{
		cout<<"\n==>";
		cin>>n;
		}while((n<n1)||(n>n2));
	return n;
	}
	
int Somma(int n1, int n2, int& somma){
	int i, n;
	for(i=1;i<=n2;i++){
		cout<<"\nN "<<i;
		Input(n1,n2,n);
		somma=somma+n;
		}
	return somma;
	}
	
void Menu(int& somma){
	int n1, n2, scelta;
	n1=1;
	n2=3;
	cout<<"\nIl programma esegue la somma di 10 numeri i cui valori appartengono\nad un determinato range";
	cout<<"\n1. 1-10";
	cout<<"\n2. 11-20";
	cout<<"\n3. 21-30";								
	Input(n1,n2,scelta);
	switch(scelta){
		case 1: cout<<"\nRange 1-10";
				n1=1;
				n2=10;
				Somma(n1,n2,somma);
				break;
		case 2: cout<<"\nRange 11-20";
				n1=11;
				n2=20;
				Somma(n1,n2,somma);
				break;
		case 3: cout<<"\nRange 21-30";
				n1=21;
				n2=30;
				Somma(n1,n2,somma);
				break;
		}
	return;	
	}
	
	
int main(){
	int somma;
	Menu(somma);
	cout<<"\nLa somma e' "<<somma;
	return 1;
	}	
