#include <iostream>
#define DIM 5
#define DIM2 10
using namespace std;

void Input(int vett[]){
	for(int i=0;i<DIM;i++){
		cout<<"\nN"<<i+1<<" ==> ";
		cin>>vett[i];
	}	
	
	return;
}

void Bubblesort(int vett[]){
	int aux,sup,scambio;
	sup=DIM;
	
	while(sup!=0){
		scambio=-1;
		for(int i=0;i<sup-1;i++){
			if(vett[i]>vett[i+1]){
				aux=vett[i];
				vett[i]=vett[i+1];
				vett[i+1]=aux;
				scambio=i;
			}
		}
		sup=scambio+1;
	}
	
	return;
}

void CostruzioneTerzoVettore(int vett1[],int vett2[],int vett3[]){
	int k=0;
	for(int i=0;i<DIM2;i=i+2){
		if(vett1[k]<=vett2[k]){
			vett3[i]=vett1[k];
			vett3[i+1]=vett2[k];
		}
		if(vett1[k]>vett2[k]){
			vett3[i]=vett2[k];
			vett3[i+1]=vett1[k];
		}
		k++;
	}
	
	return;
}

void Stampa(int vett[]){
	for(int i=0;i<DIM2;i++){
		cout<<"\nN"<<i+1<<" ==> "<<vett[i];
	}
	
	return;
}

int main(){
	int vett1[DIM], vett2[DIM], vett3[DIM2];
	
	cout<<"Inserisci elementi primo vettore\n";
	Input(vett1);
	
	cout<<"\n\nInserisci elementi secondo vettore\n";
	Input(vett2);
	
	cout<<"\n\nOrdinamento contenuto vettori...";
	Bubblesort(vett1);
	Bubblesort(vett2);
	
	cout<<"\n\nCostruzione terzo vettore...";
	CostruzioneTerzoVettore(vett1,vett2,vett3);
	
	cout<<"\nStampa terzo vettore..."; 
	Stampa(vett3);
	
	return 0;
}
