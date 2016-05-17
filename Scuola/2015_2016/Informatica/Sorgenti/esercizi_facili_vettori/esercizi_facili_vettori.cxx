#include <iostream>
using namespace std;

int main(){
	int vett[10];
	int i, somma=0, prodotto=1;
	
	for(i=0;i<10;i++){
		cout<<"\nN"<<i+1<<" ==>";
		cin>>vett[i];
		somma=somma+vett[i];
		prodotto=prodotto*vett[i];
	}
	cout<<"\nHai finito il caricamento\n";
	for(i=0;i<=9;i++){
		cout<<"\n"<<vett[i];
	}
	cout<<"\n\nLa somma e': "<<somma;
	cout<<"\nIl prodotto e': "<<prodotto<<"\n";
	for(i=9;i>=0;i--){
		cout<<"\n"<<vett[i];
	}
	return 1;
}

/*
#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
	int vett[50];
	int i;
	cout<<"Calcolo numeri casuali...";
	srand((unsigned)time(NULL));
	for(i=0;i<50;i++){
		vett[i]=rand()%100+1;
	}
	cout<<"\nFine calcolo numeri casuali\nStampa: ";
	for(i=0;i<50;i++){
		cout<<"\nN"<<i+1<<"==> "<<vett[i];
	}
	return 1;
}
*/
