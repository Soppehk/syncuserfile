#include <iostream>
#include <stdio.h>
#define DIM 10
using namespace std;

void Menu(){
	cout<<"\n1. Inserire nel database i dati di una medicina";
	cout<<"\n2. Ricerca nel database di una medicina tramite codice";
	cout<<"\n3. Stampa contenuto database";
	cout<<"\n4. Uscita dal programma";
		
	return;
}

void InserimentoDati(string codice_medicine[], string nome_medicine[], float prezzo_medicine[], int &numero_medicina, int ordine_medicine[]){
	cout<<"\nInserisci codice medicina N "<<numero_medicina+1<<" : ";
	fflush(stdin);
	getline(cin,codice_medicine[numero_medicina]);	
	cout<<"\nInserisci nome medicina : ";
	fflush(stdin);
	getline(cin,nome_medicine[numero_medicina]);
	cout<<"\nInserisci prezzo medica : ";
	cin>>prezzo_medicine[numero_medicina];
	
	numero_medicina++;
	ordine_medicine[numero_medicina]=numero_medicina;
	
	return;
}

void Ricerca(string codice_medicine[], string nome_medicine[], float prezzo_medicine[]){
	int posizione=-1;
	string codice;
	
	cout<<"\nImmetere il codice da ricercare: ";
	fflush(stdin);	
	getline(cin,codice);
	
	while((i<DIM)&&(codice_medicine[i]<=codice)&&(trovato==-1)){
		if(codice_medicine==codice){
			posizione=i;
		}else{
			i++;
		}
	}
	
	if(posizione==-1){
		cout<<"\nMedicina non trovata!";
	}else{
		cout<<"\nCodice medicina: "<<codice_medicine[posizione];
		cout<<"\nNome medicina: "<<nome_medicine[posizione];
		cout<<"\nPrezzo medicina: "<<prezzo_medicine[posizione];
	}
	
	return;
}

void DuplicazioneString(string vettcp[], string v[]){
	for(int i=0;i<DIM;i++){
		vettcp[i]=v[i];
	}
	
	return;
}

void DuplicazioneFloat(float vettcp[], float v[]){
	for(int i=0;i<DIM;i++){
		vettcp[i]=v[i];
	}
	
	return;
}

void Stampa(string codice_medicine[], string nome_medicine[], float prezzo_medicine[], int ordine_medicine[]){
	int scelta_ordinamento;
	cout<<"\nSelezionare tipo di ordinamento";
	do{
		cout<<"\n1. Codice";
		cout<<"\n2. Nome";
		cout<<"\n3. Prezzo";
		cout<<"\n==> ";
		cin>>scelta_ordinamento;
	}while((scelta_ordinamento<1)||(scelta_ordinamento>3));	
	
	switch(scelta_ordinamento){
		case 1: 
	}
	
	return;
}

int main(){
	string codice_medicine[DIM], nome_medicine[DIM];
	float prezzo_medicine[DIM];
	int ordine_medicine[DIM];
	int scelta, numero_medicina=0;
	
	do{
		Menu();
		
		do{
			cout<<"\n==> ";
			cin>>scelta;
		}while((scelta<1)||(scelta>4));
		
		switch(scelta){
			case 1: cout<<"\nInserire nel database i dati di una medicina";
					InserimentoDati(codice_medicine,nome_medicine,prezzo_medicine,numero_medicina,ordine_medicine);
					break;
			case 2: cout<<"\nRicerca nel database di una medicina tramite codice";
					Ricerca(codice_medicine,nome_medicine,prezzo_medicine);
					break;
			case 3: cout<<"\nStampa contenuto database"	;
					Stampa();
					break;
		}
		cout<<"\n\n";		
	}while(scelta!=4);
	
	cout<<"\nUscita dal programma...";
	
	return 0;
}
