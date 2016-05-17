#include <iostream>
using namespace std;

int dim=5; 

void Inserimento(int v[]){
	for(int i=0;i<dim;i++){
		cout<<"\nN"<<i+1<<" ==> ";
		cin>>v[i];
	}
	return;
}

void Stampa(int v[]){
	for(int i=0;i<dim;i++){
		cout<<"\nN"<<i+1<<" "<<v[i];
	}
	return;
}

void Merge(int v1[], int v2[], int v3[]){
	int j=0;
	int k=0;
	for(int i=0;i<10;i++){
		if(i%2==0){
			v3[i]=v1[j];
			j++;
		}
		else{
			v3[i]=v2[k];
			k++;
		}
	}
	return;
}
int main(){
	int v1[5], v2[5], v3[10];
	
	cout<<"Inserimento dati primo vettore...";
	Inserimento(v1);
	cout<<"\nInserimento dati secondo vettore...";
	Inserimento(v2);
	cout<<"\nStampa primo vettore...";
	Stampa(v1);
	cout<<"\nStampa secondo vettore...";
	Stampa(v2);
	cout<<"\nCostruzione terzo vettore...";
	Merge(v1,v2,v3);
	dim=10;
	cout<<"\nStampa terzo vettore...";
	Stampa(v3);
	
	return 1;
}
