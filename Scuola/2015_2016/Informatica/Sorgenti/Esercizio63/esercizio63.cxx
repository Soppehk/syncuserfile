#include <iostream>
using namespace std;

void ListinoPrezzi();
void InsDati(int&,int&,int&,int&);
float Conto(int,int,int,int);

int main(){
	int giorni,persone,abitacolo,veicolo;
	ListinoPrezzi();
	InsDati(giorni,persone,abitacolo,veicolo);
	cout<<endl<<Conto(giorni,persone,abitacolo,veicolo)<<" euro";
	return 1;
	}

void ListinoPrezzi(){
	cout<<"Tariffe campeggio";
	cout<<"\nPersona al giorno: 5,00 euro";
	cout<<"\nTenda al giorno: 4,00 euro";
	cout<<"\nRoulotte al giorno: 4,50 euro";
	cout<<"\nAuto al giorno: 5,50 euro";
	cout<<"\nMoto al giorno: 3,50 euro";
	return;
	}

void InsDati(int& giorni, int& persone, int& abitacolo, int& veicolo){
	do{
		cout<<"\nInserisci numero giorni: ";
		cin>>giorni;
		}while(giorni<0);
	do{
		cout<<"\nInserire numero persone: ";
		cin>>persone;
		}while(persone<1);
	do{
		cout<<"\nInserire 1 per tenda, 2 per roulotte: ";
		cin>>abitacolo;
		}while((abitacolo<1)||(abitacolo>2));	
	do{
		cout<<"\nInserire 1 per auto, 2 per moto: ";
		cin>>veicolo;
		}while((veicolo<1)||(veicolo>2));
		
	return;
	}
	
float Conto(int giorni, int persone, int abitacolo, int veicolo){
	float conto=0;
	if(abitacolo==1){
		conto=conto+4.00;
		}else{
			conto=conto+4.50;			
			}
	if(veicolo==1){
		conto=conto+5.50;
		}else{
			conto=conto+3.50;
			}
	conto=conto+persone*5.00;
	conto=conto*giorni;
	
	return conto;		
	}	
