#include <iostream>
#define giorni 5
using namespace std;

void Input(float prezzi[],int ordinegiorni[]){
	cout<<"\nInserire prezzo del prodotto per ogni giorno del mese\n";
	
	for(int i=0;i<giorni;i++){
		
		do{
			cout<<"Giorno "<<i+1<<" prezzo: ";
			cin>>prezzi[i];
			ordinegiorni[i]=i;
		}while(prezzi[i]<0);
	}
	
	return;
}

void Stampa(float prezzi[]){
	for(int i=0;i<giorni;i++){
		cout<<"\nGiorno "<<i+1<<" prezzo: "<<prezzi[i];
	}
	return;
}

float Max(float prezzi[]){
	float max=0;
	for(int i=0;i<giorni;i++){
		if(prezzi[i]>max){
			max=prezzi[i];
		}
	}
	
	return max;
}

float Min(float prezzi[]){
	float min=999999999;
	for(int i=0;i<giorni;i++){
		if(prezzi[i]<min){
			min=prezzi[i];
		}
	}
	
	return min;
}

void Bubblesort(float prezzi[], float ordinato[],int ordinegiorni[]){
	int auxgiorni,sup,scambio;
	float aux;
	
	for(int i=0;i<giorni;i++){
		ordinato[i]=prezzi[i];
	}
	
	sup=giorni;
	while(sup!=0){
		scambio=-1;
		for(int i=0;i<(sup-1);i++){
			if(ordinato[i]>ordinato[i+1]){
				aux=ordinato[i];
				ordinato[i]=ordinato[i+1];
				ordinato[i+1]=aux;
				scambio=i;
				
				auxgiorni=ordinegiorni[i];
				ordinegiorni[i]=ordinegiorni[i+1];
				ordinegiorni[i+1]=auxgiorni;
			}
		}
		sup=scambio+1;
	}
	
	return;
}

int main(){
	int ordinegiorni[giorni];
	float prezzi[giorni], ordinato[giorni];
	
	Input(prezzi,ordinegiorni);
	Stampa(prezzi);
	cout<<"\n\nPrezzo massimo "<<Max(prezzi);
	cout<<"\n\nPrezzo minimo "<<Min(prezzi);
	cout<<"\n\nPrezzi ordinati...";
	Bubblesort(prezzi,ordinato,ordinegiorni);
	for(int i=0;i<giorni;i++){
		cout<<"\nGiorno "<<ordinegiorni[i]+1<<" prezzo: "<<ordinato[i];
	}
	
	
	return 1;
}
