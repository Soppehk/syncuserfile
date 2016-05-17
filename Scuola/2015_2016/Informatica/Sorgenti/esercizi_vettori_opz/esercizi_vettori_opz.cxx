#define dim 10
#include <iostream>
using namespace std;

void Inizializzazione(float v[]){
	for(int i=0;i<10;i++){
		v[i]=0.0;
	}
	return;
}

void Input(float v[]){
	for(int i=0;i<10;i++){
		cout<<"\nN"<<i+1<<" ==> ";
		cin>>v[i];
	}
	return;
}

void Stampa(float v[]){
	for(int i=0;i<10;i++){
		cout<<"\nN"<<i+1<<" "<<v[i];
	}
	return;
}

void Gen3(float v1[], float v2[], float v3[]){
	for(int i=0;i<10;i++){
		v3[i]=v1[i]+v2[i];
	}
	return;
}
int main(){
	float v1[dim], v2[dim], v3[dim];
	
	cout<<"Inizializzazione primo vettore...";
	Inizializzazione(v1);
	cout<<"\nInizializzazione secondo vettore...";
	Inizializzazione(v2);
	cout<<"\nInizializzazione terzo vettore...";
	Inizializzazione(v3);
	
	cout<<"\n\nInserisci 10 numeri nel primo vettore";
	Input(v1);
	cout<<"\nStampa del primo vettore...";
	Stampa(v1);
	
	cout<<"\n\nInserisci 10 numeri nel secondo vettore";
	Input(v2);
	cout<<"\nStampa del secondo vettore...";
	Stampa(v2);
	
	cout<<"\n\nGenerazione terzo vettore...";
	Gen3(v1,v2,v3);
	cout<<"\nStampa del terzo vettore...";
	Stampa(v3);
	
	return 1;
}
