#include <iostream>
#include <stdlib.h>
#include <string>
#include <stdio.h>
#define DIM 3
using namespace std;

struct medicine{
	string codice;
	float prezzo;
	string nome;
};

void Menu(){
	cout<<"\n1. Inserire nel database i dati di una medicina";
	cout<<"\n2. Ricerca nel database di una medicina tramite codice";
	cout<<"\n3. Stampa contenuto database";
	cout<<"\n4. Uscita dal programma";
		
	return;
}

void InserimentoDati(struct medicine farmacia[], int &nMedicina){
	cout<<"\nInserisci codice medicina N"<<nMedicina+1<<" : ";
	fflush(stdin);
	getline(cin,farmacia[nMedicina].codice);	
	cout<<"\nInserisci nome medicina : ";
	fflush(stdin);
	getline(cin,farmacia[nMedicina].nome);
	cout<<"\nInserisci prezzo medicina : ";
	cin>>farmacia[nMedicina].prezzo;
	
	nMedicina++;
	
	return;
}

void Ricerca(struct medicine farmacia[]){
	int posizione=-1, i=0;
	string codice;
	
	cout<<"\nImmetere il codice da ricercare: ";
	fflush(stdin);	
	getline(cin,codice);
	
	while((i<DIM)&&(farmacia[i].codice<=codice)&&(posizione==-1)){
		if(farmacia[i].codice==codice){
			posizione=i;
		}else{
			i++;
		}
	}
	
	if(posizione==-1){
		cout<<"\nMedicina non trovata!";
	}else{
		cout<<"\nCodice medicina: "<<farmacia[posizione].codice;
		cout<<"\nNome medicina: "<<farmacia[posizione].nome;
		cout<<"\nPrezzo medicina: "<<farmacia[posizione].prezzo;
	}
	
	return;
}

void Stampa(struct medicine farmacia[],int dim){
	int scelta_ordinamento;
	struct medicine aux;
	cout<<"\nSelezionare tipo di ordinamento";
	do{
		cout<<"\n1. Codice";
		cout<<"\n2. Nome";
		cout<<"\n3. Prezzo";
		cout<<"\n==> ";
		cin>>scelta_ordinamento;
	}while((scelta_ordinamento<1)||(scelta_ordinamento>3));	
	
	switch(scelta_ordinamento){
		case 1: cout<<"\nOrdinamento per codice";
			 	for(int i=0;i<dim;i++){
			 		if((i+1)!=dim){
			 			if(farmacia[i].codice>farmacia[i+1].codice){
			 			aux=farmacia[i];
			 			farmacia[i]=farmacia[i+1];
			 			farmacia[i+1]=aux;
			 			}
			 		}
			 		
			 	}
			 	break;
			 	
		case 2: cout<<"\nOrdinamento per nome";
			 	for(int i=0;i<dim;i++){
			 		if((i+1)!=dim){
				 		if(farmacia[i].nome>farmacia[i+1].nome){
				 			aux=farmacia[i];
				 			farmacia[i]=farmacia[i+1];
				 			farmacia[i+1]=aux;
				 		}	
			 		}
			 		
			 	}
				break;
		
		case 3: cout<<"\nOrdinamento per prezzo";
			 	for(int i=0;i<=dim;i++){
			 		if((i+1)!=dim){
			 			if(farmacia[i].prezzo>farmacia[i+1].prezzo){
			 			aux=farmacia[i];
			 			farmacia[i]=farmacia[i+1];
			 			farmacia[i+1]=aux;
			 			}
			 		}
			 		
			 		
	            }
	            break;
	}
	
	for(int i=0;i<dim;i++){
		cout<<"\nN"<<i+1;
		cout<<"\nCodice medicina: "<<farmacia[i].codice;
		cout<<"\nNome medicina: "<<farmacia[i].nome;
		cout<<"\nPrezzo medicina: "<<farmacia[i].prezzo;
	}
	
	return;
}

int main(){
	struct medicine farmacia[DIM];
	int nMedicina=0;
	int scelta=0;
	bool ctl=false;
	
	do{
		Menu();
		
		do{
			cout<<"\n==> ";
			cin>>scelta;
		}while((scelta<1)||(scelta>4));
		
		switch(scelta){
			case 1: cout<<"\nInserire nel database i dati di una medicina";
				 	if(nMedicina<DIM){
				 		InserimentoDati(farmacia,nMedicina);
				 		ctl=true;
				 	}else{
				 		cout<<"\nDatabase pieno!";
				 	}
					break;
					
			case 2: cout<<"\nRicerca nel database di una medicina tramite codice";
					if(ctl){
						Ricerca(farmacia);
					}else{
						cout<<"\nDatabase vuoto!";
					}
					break;
					
			case 3: cout<<"\nStampa contenuto database"	;
					if(ctl){
						Stampa(farmacia,DIM);
					}else{
						cout<<"\nDatabase vuoto!";
					}
					break;
		}
		cout<<"\n\n";		
	}while(scelta!=4);
	
	cout<<"\nUscita dal programma...";
	
	return 0;
}
