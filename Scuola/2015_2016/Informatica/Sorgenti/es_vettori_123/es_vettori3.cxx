#include <iostream>
#define DIM 10
using namespace std;

void Inserimento(int v[]){
	for(int i=0;i<DIM;i++){
		cout<<"\nN"<<i+1<<" ==> ";
		cin>>v[i];
	}
	return;
}

void Stampa(int v[]){
	for(int i=0;i<DIM;i++){
		cout<<"\nN"<<i+1<<" "<<v[i];
	}
	return;
}

void Differenza(int arr1[], int arr2[], int arr3[]){
	bool ctl;
	for(int i=0;i<DIM;i++){
		ctl=false;
		for(int j=0;j<DIM;j++){
			if(arr1[i]==arr2[j]){
				arr3[i]=arr1[i];
				ctl=true;
			}
		}
		if(ctl==false){
			arr3[i]=0;
		}
	}
	return;
}

int main(){
	int arr1[DIM], arr2[DIM], arr3[DIM];
	cout<<"Inserimento dati primo vettore...";
	Inserimento(arr1);
	cout<<"\nInserimento dati secondo vettore...";
	Inserimento(arr2);
	cout<<"\nCostruzione terzo vettore...";
	Differenza(arr1,arr2,arr3);
	cout<<"\nStampa terzo vettore...";
	Stampa(arr3);
	
	return 1;
}
