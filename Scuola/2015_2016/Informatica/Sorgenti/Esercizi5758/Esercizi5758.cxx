/*//Esercizio 57
#include <iostream>
using namespace std;

void DatiIniziali(int&, int&);
void RaccoltaDati(int,int,int&,int&);
void Resoconto(int,int);

int main(){
	int anno, ndipendenti, under18, over60;
	DatiIniziali(anno, ndipendenti);
	RaccoltaDati(anno, ndipendenti, under18, over60);
	Resoconto(under18, over60);
	return 1;
	}
	
void DatiIniziali(int& anno,int& ndipendenti){
	cout<<"\nInserisci anno corrente: ";
	cin>>anno;
	do{
		cout<<"\nInserisci numero dipendenti: ";
		cin>>ndipendenti;
		}while(ndipendenti<1);
	return;
	}	
	
void RaccoltaDati(int anno,int ndipendenti,int& under18,int& over60){
	char* nome;
	int nascita=0, i;
	under18=0;
	over60=0;
	
	for(i=1;i<= ndipendenti;i++){
		cout<<"\nDipendente "<<i;
		cout<<"\nInserire nome: ";
		cin>>nome;
		do{
			cout<<"Inserire anno di nascita: ";
			cin>>nascita;
			}while(nascita>anno);
		
		if((anno-nascita)>=60)
			over60++;
		if((anno-nascita)<=18)
			under18++;
		}
	return;
	}
	
void Resoconto(int under18, int over60){
	cout<<"\nI dipendenti in eta' pensionabile sono: "<<over60;
	cout<<"\nI dipendenti minorenni sono: "<<under18;
	return; 
	}
*/		
//Esercizio 58
#include <iostream>
#include <math.h>
using namespace std;

int main(){
	int i, stipendio=0, d=10;
	for(i=0;i<22;i++){
		d=d*2;
		stipendio=stipendio + d;
		}
	cout<<"Stipendio "<<stipendio;
	
	return 1;
	}
