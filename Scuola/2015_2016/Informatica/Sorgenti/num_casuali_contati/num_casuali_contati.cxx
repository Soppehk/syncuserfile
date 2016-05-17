#include <iostream>
#include <stdlib.h>
#define DIM 10000
using namespace std;

void Generazione(int v[]){
	srand((unsigned)time(NULL));
	for(int i=0;i<DIM;i++){
		v[i]=rand()%20;
	}
	return;
}

void FreqAssoluta(int v[], int freqass[]){
	for(int i=0;i<=19;i++){
		freqass[i]=0;
		for(int k=0;k<DIM;k++){
			if(v[k]==i){
				freqass[i]=freqass[i]+1;
			}
		}
		cout<<"\nLa frequenza assoluta del numero "<<i<<" è "<<freqass[i];
	}
	return;
}

void FreqRelativa(int freqass[], float freqrel[]){
	for(int i=0;i<=19;i++){
		freqrel[i]=0.0;
		freqrel[i]=freqass[i]/1000.0;
		cout<<"\nLa frequenza relativa del numero "<<i<<" è "<<freqrel[i];
	}
	return;
}

void FreqPer(float freqrel[], float freqper[]){
	for(int i=0;i<=19;i++){
		freqper[i]=0.0;
		freqper[i]=freqrel[i]*100;
		cout<<"\nLa frequenza relativa del numero "<<i<<" è "<<freqper[i]<<"%";
	}
	return;
}

void Bubblesort(int freqass[]){
	int aux,sup,scambio;
	sup=DIM;
	while(sup!=0){
		scambio=-1;
		for(int i=0;i<sup-1;i++){
			if(freqass[i]>freqass[i+1]){
				aux=freqass[i];
				freqass[i]=freqass[i+1];
				freqass[i+1]=aux;
				scambio=i;
			}
		}
		sup=scambio;
	}
	
	for(int i=0;i<=19;i++){
		cout<<"\nLa frequenza assoluta del numero "<<i<<" è "<<freqass[i];
	}
	
	return;
}

int main(){
	int v[DIM], freqass[DIM];
	float freqrel[DIM], freqper[DIM];
	
	cout<<"\nGenerazione numeri casuali...";
	Generazione(v);
	cout<<"\n\nFrequenze assolute";
	FreqAssoluta(v,freqass);
	
	cout<<"\n\nFrequenze relative";
	FreqRelativa(freqass,freqrel);
	cout<<"\n\nFrequenze percentuali";
	FreqPer(freqrel,freqper);
	cout<<"\n\nOrdinamento frequenze assolute...";
	Bubblesort(freqass);
	return 1;
}
