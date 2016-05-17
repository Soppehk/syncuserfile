#include <iostream>
#include <stdio.h>
#define DIM 3
using namespace std;

int contatore=0;

struct data{
	int giorno;
	int mese;
	int anno;
};

struct pratiche{
	int npratica;
	string cognome;
	string nome;
	//string data;
	string descrizione;
	struct data data_inizio;
	struct data data_fine;	
};

void Menu(){
	cout<<"\n1.Inserisci dati clienti\n2.Stampa database clienti\n3.Elimina dati meno recenti\n4.Esci dal programma";
	
	return;
}

void StampaPratica(struct pratiche cliente[], int i){
	cout<<"\nPratica N "<<cliente[i].npratica;
	cout<<"\ncliente "<<cliente[i].cognome<<" "<<cliente[i].nome;
	cout<<"\nData inizio pratica: "<<cliente[i].data_inizio.giorno<<"/"<<cliente[i].data_inizio.mese<<"/"<<cliente[i].data_inizio.anno;
	if((cliente[i].data_fine.giorno==0)&&(cliente[i].data_fine.mese==0)&&(cliente[i].data_fine.anno==0)){
		cout<<"\nData ultimazione pratica: Il cliente non ha ancora terminato la pratica!";
	}else{
		cout<<"\nData ultimazione pratica: "<<cliente[i].data_fine.giorno<<"/"<<cliente[i].data_fine.mese<<"/"<<cliente[i].data_fine.anno;
	}
	cout<<"\nDescrizione "<<cliente[i].descrizione;
	
	return;
}

void Push(struct pratiche cliente[], int dim, int &ne, int &tail){
	bool scelta=false;
	if(ne==dim){
		cout<<"\nCoda piena!";
	}else{
		contatore++;
		cliente[tail].npratica=contatore;
		cout<<"\nCliente N"<<cliente[tail].npratica;
		
		cout<<"\nInserire il cognome del cliente: ";
		fflush(stdin);
		getline(cin,cliente[tail].cognome);
		
		cout<<"\nInserire il nome del cliente: ";
		getline(cin,cliente[tail].nome);
		
		cout<<"\nInserire giorno inizio pratica: ";
		cin>>cliente[tail].data_inizio.giorno;
		
		cout<<"\nInserire mese inizio pratica: ";
		cin>>cliente[tail].data_inizio.mese;
		
		cout<<"\nInserire anno inizio pratica: ";
		cin>>cliente[tail].data_inizio.anno;
		
		cout<<"\nLa pratica e' stata terminata? 0.SI' 1.NO";
		do{
			cout<<"\n==> ";
			cin>>scelta;
		}while((scelta!=true)&&(scelta!=false));
		
		if(scelta){
			cliente[tail].data_fine.giorno=0;
			cliente[tail].data_fine.mese=0;
			cliente[tail].data_fine.anno=0;
		}else{
			cout<<"\nInserire giorno fine pratica: ";
			cin>>cliente[tail].data_fine.giorno;
			
			cout<<"\nInserire mese fine pratica: ";
			cin>>cliente[tail].data_fine.mese;
			
			cout<<"\nInserire anno fine pratica: ";
			cin>>cliente[tail].data_fine.anno;
		}
				
		cout<<"\nInserire la descrizione della pratica: ";
		fflush(stdin);
		getline(cin,cliente[tail].descrizione);
		tail=(tail+1)%dim;
		ne++;
	}
	
	return;
}

void Pop(struct pratiche cliente[], int dim, int &ne, int &head){
	if(ne==0){
		cout<<"\nCoda vuota!";
	}else{
		cout<<"\nEliminazione pratica...";
		StampaPratica(cliente,head);
		cout<<"\nPratica eliminata";
		cliente[head].npratica=0;
		head=(head+1)%dim;
		ne--;
	}
	
	return;
}

void StampaDB(struct pratiche cliente[], int dim, int ne, int head, int tail){
	int k=head;
	if(ne==0){
		cout<<"\nCoda vuota!";
	}else{
		do{
		   StampaPratica(cliente,k);
		   k=(k+1)%dim;
		   cout<<"\n";
		}while(k!=tail);
		}
	
	return;
}

int main(){
	struct pratiche cliente[DIM];
	int scelta, ne=0, tail=0, head=0;
	string qualcosa;
		
	do{
		Menu();
		do{
			cout<<"\n==> ";
			cin>>scelta;
			getline(cin,qualcosa);
		}while((scelta<1)||(scelta>4));
		
		switch(scelta){
			case 1: cout<<"\nInserimento dati cliente";
				 	Push(cliente,DIM,ne,tail);
				 	break;
			case 2: cout<<"\nStampa database";
				 	StampaDB(cliente,DIM,ne,head,tail);
				 	break;
			case 3:	cout<<"\nEliminazione dati meno recenti";
				 	Pop(cliente,DIM,ne,head);
				 	break;
		}
		
		cout<<"\n\n";
		
	}while(scelta!=4);
	
	cout<<"\nUscita dal programma...";
	
	return 0;
}
