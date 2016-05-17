#include <iostream>
using namespace std;

void AzzerVett(int v[]){
	for(int i=0;i<10;i++){
		v[i]=0;
	}
	return;
}

void StampaVettore(int v[]){
	for(int i=0;i<10;i++){
		cout<<"\nN"<<i+1<<" "<<v[i];
	}
	return;
}
	
void InserimentoDati(int v[]){
	for(int i=0;i<10;i++){
		cout<<"\n\nInserisci un numero N"<<i+1<<"==> ";
		cin>>v[i];
	}
	return;
}

void StampaVettoreInverso(int v[]){
	for(int i=9;i>=0;i--){
		cout<<"\nN"<<i+1<<" "<<v[i];
	}
	return;
}

void PariDispari(int v[],int &npari,int &ndispari){
	npari=0;
	ndispari=0;
	for(int i=0;i<10;i++){
		if(v[i]%2==0){
			npari++;
		}
		else{
			ndispari++;
		}
	}
	return;
}

int main(){
	int v[10], npari, ndispari;
	cout<<"Inizializzaione del vettore...";
	AzzerVett(v);
	cout<<"\nStampa contenuto vettore\n";
	StampaVettore(v);	
	InserimentoDati(v);
	cout<<"\nStampa contenuto vettore\n";
	StampaVettore(v);
	cout<<"\n\nStampa contenuto vettore al contrario\n";
	StampaVettoreInverso(v);
	PariDispari(v,npari,ndispari);
	cout<<"\nNel vettore sono presenti "<<npari<<" numeri pari e "<<ndispari<<" numeri dispari";

	return 1;
}
