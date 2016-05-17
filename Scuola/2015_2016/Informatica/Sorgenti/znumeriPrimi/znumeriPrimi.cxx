#include <iostream>
using namespace std;
int somma=0;

int Input(int& n){
	do{
		cout<<"\nInserisci numero maggiore di 1: ";
		cin>>n;
		}while(n<=1);
	return n;
	}

int Somma(int x){
	somma=somma+x;
	return somma;
	}


int Primo(int x){
	if(x<=2){
		return 1;
		}
	if(x%2==0){
		return 0;
		}
	for(int i=3;i<x/2;i=i+2){
		if(x%i==0){	
		return 0;
		}
		}
	return 1;			
	}


void SommaNumeriPrimi(int n){
	int i,x=0;
	for(i=1;i<=n; i++){
		if(Primo(i))
		cout<<i<<"+";
		Somma(Primo(x));
		}
	cout<<"\b="<<somma;
	return;	
	}


int main(){
	int n;
	Input(n);
	SommaNumeriPrimi(n);
	return 1;
	}
