#include <iostream>
#define DIM 10
using namespace std;

void Inserimento(float v[]){
	for(int i=0;i<DIM;i++){
		cout<<"\nN"<<i+1<<" ==> ";
		cin>>v[i];
	}
	return;
}

void Stampa(float v[]){
	for(int i=0;i<DIM;i++){
		cout<<"\nN"<<i+1<<" "<<v[i];
	}
	return;
}

void Ordinato(float v[], bool &ctl){
	int i=0;
	ctl=true;
	
	do{
		if(v[i+1]>v[i]){
			ctl=true;
		}
		else{
			ctl=false;
		}
		i++;	
	}while((i<DIM-1)&&(ctl==true));
		
	return;
}
int main(){
	float v[DIM];
	bool ctl;
	
	cout<<"Inserimento dati nel vettore...";
	Inserimento(v);
	
	cout<<"\nStampa del contenuto del vettore...";
	Stampa(v);
	
	cout<<"\nControllo ordine crescente...";
	Ordinato(v,ctl);
	
	if(ctl==true){
		cout<<"\nE' ordinato in ordine crescente.";
	}
	else{
		cout<<"\nNon e' ordinato in ordine crescente.";
	}
	
	
	
	
	return 1;
}
