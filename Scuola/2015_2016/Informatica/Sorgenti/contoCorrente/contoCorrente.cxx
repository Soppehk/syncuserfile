#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string.h>
using namespace std;

struct datiCliente{
	string nome;
	string cognome;
	int n_conto_corrente;
};

float Saldo(float &saldo){
	fstream fileConto;
	string aux;
	fileConto.open("versamenti.txt",ios::in);
	
	fflush(stdin);
	getline(fileConto,aux);
	saldo=saldo+aux;
	while(!fileConto.eof()){
		fflush(stdin);
		getline(fileConto,aux);
		saldo=saldo+stodaux;
	}
	
	return saldo;
}

void Versamento(float &saldo, int &nVersamenti){
	float aux;
	fstream fileConto;
	
	cout<<"\nSaldo: "<<saldo;
	
	cout<<"\nVersamento N "<<nVersamenti;
	
	fileConto.open("versamenti.txt",ios::app);
	
	cout<<"Inserire versamento: ";
	cin>>aux;
	
	fileConto<<aux<<endl;
	
	fileConto.close();
	
	nVersamenti++;
	saldo=saldo+aux;
	
	return;
}

void Prelievo(float &saldo, int &nPrelievi){
	float aux;
	fstream fileConto;
}

int main(){
	struct datiCliente cliente;
	int scelta, nVersamenti=0, nPrelievi=0;
	bool ctl=false;
	float saldo=0.0;
	
	fstream fileConto;
	
	cout<<"Programma Gestione Conto Corrente\n\n";
	
	fileConto.open("cliente.txt", ios::out);
	
	cout<<"\nBenvenuto nel processo di creazione del suo conto corrente";
	
	cout<<"\nInserisca il suo nome: ";
	fflush(stdin);
	getline(cin,cliente.nome);
	fileConto<<cliente.nome<<endl;
	
	cout<<"\nInserisca il suo cognome: ";
	getline(cin,cliente.cognome);
	fileConto<<cliente.cognome<<endl;
	
	srand((unsigned)time(NULL));
	cliente.n_conto_corrente=rand()%10000;
	cout<<"\nIl suo numero di conto corrente è "<<cliente.n_conto_corrente;
	fileConto<<cliente.n_conto_corrente<<endl;
	
	fileConto.close();
	cout<<"\nCongratulazioni, ha completato il processo di creazione del conto corrente!\n\n";
		
	do{
		cout<<"\nOperazioni disponibili: ";
		cout<<"\n1) Versamento";
		cout<<"\n2) Prelievo";
		cout<<"\n3) Transazioni";
		cout<<"\n4) Chiusura programmma";
		
		do{
			cout<<"\n==> ";
			cin>>scelta;
		}while((scelta<1)||(scelta>3));
		
		switch(scelta){
			case 1: cout<<"\nVersamento";
					Versamento(saldo,nVersamenti);
					ctl=true;
					break;
					
			case 2: cout<<"\nPrelievo";
					if(ctl){
						
					}else{
						cout<<"\nE' necessario effetuare un versamento prima di un prelievo!";
					}
					break;
			
			case 3: cout<<"\nTransazioni";
		}
		
	}while(scelta!=4);	
	
	cout<<"\nUscita dal programma...";
	
	return 0;
}
