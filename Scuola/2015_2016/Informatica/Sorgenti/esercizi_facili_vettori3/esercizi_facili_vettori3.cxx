#include <iostream>
using namespace std;

void Inizializzazione(int v[]){
	for(int i=0;i<10;i++){
		v[i]=0;
	}
	return;
}

void Inserimento(int v[]){
	int a=0;
	cout<<"\nInserisci 10 numeri in ordine crescente";
	for(int i=0;i<10;i++){
		do{
			cout<<"\nN"<<i+1<<" ==> ";
			cin>>v[i];
			if(a==0){
				a=v[i];
			}
			if(a>v[i]){
				cout<<"\nDevi inserire i numeri in ordine crescente!";
			}
			
		}while(a>v[i]);
		a=v[i];
	}
	return;
}

void Stampa(int v[],int a){
	for(int i=0;i<10;i++){
		if(a==1){
			cout<<"\nN"<<i+1<<" ==> "<<v[i];
		}
		else{
			if((a==3)&&(v[i]%2==0)){
				cout<<"\nN"<<i+1<<" ==> "<<v[i];
			}
			if((a==2)&&(v[i]%2!=0)){
				cout<<"\nN"<<i+1<<" ==> "<<v[i];
			}
		}
	}
	return;
}

bool Ricerca(int v[],int n){
	for(int i=0;i<10;i++){
		if(v[i]==n){
			return true;
		}
		if(v[i]>n){
			return false;
		}
	}
	return false;
}

int main(){
	int v[10], n;
	
	cout<<"Inizializzazione dati...";
	Inizializzazione(v);
	
	cout<<"\nInserimento dati...";
	Inserimento(v);
	
	cout<<"\nStampa dei dati...\n";
	Stampa(v,1);
	
	cout<<"\n\nStampa dei numeri dispari...\n";
	Stampa(v,2);
	
	cout<<"\n\nStampa dei numeri pari...\n";
	Stampa(v,3);
	
	cout<<"\n\nInserisci numero da ricercare: ";
	cin>>n;
	if(Ricerca(v,n)==true){
		cout<<"\nNumero trovato";
	}
	else{
		cout<<"\nNumero non trovato";
	}
	
	return 1;
}
