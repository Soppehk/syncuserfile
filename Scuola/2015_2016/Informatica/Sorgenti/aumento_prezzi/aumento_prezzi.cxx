#include <iostream>
#define dim 5
using namespace std;

void Inserimento(float prezzi[], string prodotti[]){
	for(int i=0;i<dim;i++){
		cout<<"\nProdotto N"<<i+1<<" : ";
		cin>>prodotti[i];
		do{
			cout<<"Prezzo del prodotto: ";
			cin>>prezzi[i];
		}while(prezzi[i]<0);
	}
	return;
}

void Stampa(float prezzi[], string prodotti[]){
	for(int i=0;i<dim;i++){
		cout<<"\n"<<prodotti[i]<<": "<<prezzi[i]<<" euro";
	}
	return;
}

void AumentoPrezzi(float prezzi[]){
	for(int i=0;i<dim;i++){
		if(prezzi[i]<5){
			prezzi[i]=prezzi[i]+prezzi[i]*10/100;
		}
		else{
			prezzi[i]=prezzi[i]+prezzi[i]*6/100;
		}	
	}
	return;
}

int main(){
	float prezzi[dim];
	string prodotti[dim];
	
	cout<<"Inserimento prezzi prodotti...";
	Inserimento(prezzi,prodotti);
	cout<<"\nStampa dei prodotti...";
	Stampa(prezzi,prodotti);
	cout<<"\n\nAumento dei prezzi dei prodotti...";
	AumentoPrezzi(prezzi);
	cout<<"\nStampa aumenti...";
	Stampa(prezzi,prodotti);
	
	
	return 1;
}
