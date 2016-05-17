#include <iostream>
#define DIM 5
using namespace std;

void Push(int vett[], int &posizione, int dim){
	
	if(posizione<=dim){
		cout<<"\nN"<<posizione<<" ";
		cin>>vett[posizione];
		posizione++;
	}else{
		if(posizione>dim){
		if(vett[0]==0){
			posizione=0;
			cout<<"\nN"<<posizione<<" ";
			cin>>vett[posizione];
			posizione++;
		}else{
			cout<<"\nIl vettore è pieno, eseguire un pop!";
		}
	}
	
	return;
}

void Pop(int vett[], int &posizione, int dim){
	int i=0;
	bool exit=false;
	
	while((i<=posizione)&&(exit==false)){
		if(vett[i]==0){
			i++;
		}else{
			vett[i]=0;
			exit=true;
		}
	}
	
	return;	
}

void Stampa(int vett[], int &posizione, int dim){
	int i=0;
	
	while(i<=dim){
		if(i<=dim){
			if(vett[i]==0){
			i++;
		}else{
			cout<<"\nN"<<i<<" "<<vett[i];
			i++;
		}		
		}
	}
	
	
	return;
}

int main(){
	int vett[DIM], scelta=0;
	int posizione=0;
	
	for(int i=0;i<DIM;i++){
		vett[i]=0;
	}
	
	do{
		do{
			cout<<"\n1.Push\n2.Pop\n3.Stampa\n4.Uscita dal programma\n==> ";
			cin>>scelta;
		}while((scelta<1)||(scelta>4));
		
		switch(scelta){
			case 1: cout<<"\nPush";
					Push(vett,posizione,DIM);
					break;
			case 2: cout<<"\nPop";
					Pop(vett,posizione,DIM);
					break;
			case 3: cout<<"\nStampa";
					Stampa(vett,posizione,DIM);
					break;						
		}
		
	}while(scelta!=4);
	
	cout<<"\nUscita dal programma...";
	
	return 0;
}
