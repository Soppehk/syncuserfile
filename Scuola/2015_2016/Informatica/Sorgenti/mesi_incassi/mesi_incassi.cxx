#include <iostream>
#include <string.h>
#include <cstdio>
#define DIM 5
using namespace std;

int Menu(){
	int scelta;
	cout<<"\n1)Inserimento dati";
	cout<<"\n2)Stampa dei dati inseriti";
	cout<<"\n3)Incasso annuale";
	cout<<"\n4)Mese con incasso maggiore";
	cout<<"\n5)Mese con incasso minore";
	cout<<"\n6)Stampa incassi in ordine crescente";
	cout<<"\n7)Stampa incassi in ordine decrescente";
	cout<<"\n8)Uscita dal programma";
	
	cout<<"\n\nInserire scelta: ";
	do{
		cout<<"\n==> ";
		cin>>scelta;
	}while((scelta<1)||(scelta>8));
	
	return scelta;
}


void InputDati(string mese[], float incasso[], int &nmese, bool &ctl){
	cout<<"\n"<<nmese<<" Inserisci il mese: ";
	fflush(stdin);
	cin>>mese[nmese-1];
	cout<<"\nInserire l'incasso mensile in euro: ";
	cin>>incasso[nmese-1];
	nmese++;
	ctl=true;
	return;
}

void StampaDati(string mese[], float incasso[]){
	for(int i=0;i<DIM;i++){
		cout<<"\n"<<i+1<<" "<<mese[i]<<" "<<incasso[i]<<" euro";
	}
	
	return;
}

float IncassoTotale(float incasso[]){
	float incassototale;
	for(int i=0;i<DIM;i++){
		incassototale=incassototale+incasso[i];
	}	
	
	return incassototale;
}

void IncassoMax(string mese[], float incasso[]){
	int imax=0;
	float max=0;
	for(int i=0;i<DIM;i++){
		if(incasso[i]>max){
			max=incasso[i];
			imax=i;
		}
	}
	cout<<"\nMese incasso massimo "<<mese[imax]<<" "<<incasso[imax]<<" euro";
	
	return;
}

void IncassoMin(string mese[], float incasso[]){
	int imin=0;
	float min=1000000000;
	for(int i=0;i<DIM;i++){
		if(incasso[i]<min){
			min=incasso[i];
			imin=i;
		}
	}
	cout<<"\nMese incasso minimo "<<mese[imin]<<" "<<incasso[imin]<<" euro";
	
	return;
}

void CopiaVettoreString(string mese[], string copiamese[]){
	for(int i=0;i<DIM;i++){
		copiamese[i]=mese[i];
	}
	
	return;
}

void CopiaVettoreFloat(float incasso[], float copiaincasso[]){
	for(int i=0;i<DIM;i++){
		copiaincasso[i]=incasso[i];
	}
	
	return;
}

void Bubblesort(string mese[], float incasso[]){
	int i,sup,scambio;
	float auxf, copiaincasso[DIM];
	string auxs, copiamese[DIM];
	
	CopiaVettoreString(mese,copiamese);
	CopiaVettoreFloat(incasso,copiaincasso);
	
	sup=DIM;
	while(sup!=0){
		scambio=-1;
		for(i=0;i<sup-1;i++){
			if(copiaincasso[i]>copiaincasso[i+1]){
				auxf=copiaincasso[i];
				copiaincasso[i]=copiaincasso[i+1];
				copiaincasso[i+1]=auxf;
				
				auxs=copiamese[i];
				copiamese[i]=copiamese[i+1];
				copiamese[i+1]=auxs;
				
				scambio=i;
			}
		}
		sup=scambio+1;
	}
	
	StampaDati(copiamese,copiaincasso);
	
	return;
}

void BubblesortDecrescente(string mese[], float incasso[]){
	int i,sup,scambio;
	float auxf, copiaincasso[DIM];
	string auxs, copiamese[DIM];
	
	CopiaVettoreString(mese,copiamese);
	CopiaVettoreFloat(incasso,copiaincasso);
	
	sup=DIM;
	while(sup!=0){
		scambio=-1;
		for(i=0;i<sup-1;i++){
			if(copiaincasso[i]<copiaincasso[i+1]){
				auxf=copiaincasso[i];
				copiaincasso[i]=copiaincasso[i+1];
				copiaincasso[i+1]=auxf;
				
				auxs=copiamese[i];
				copiamese[i]=copiamese[i+1];
				copiamese[i+1]=auxs;
				
				scambio=i;
			}
		}
		sup=scambio+1;
	}
	
	StampaDati(copiamese,copiaincasso);
	
	return;
}

int main(){
	string mese[DIM];
	float incasso[DIM];
	int nmese=1, scelta;
	bool ctl=false;
	cout<<"---INCASSI MENSILI---\n\n";
	do{
		scelta=Menu();
		
		switch(scelta){
			case 1: cout<<"\nInserimento dati";
					while(nmese<=DIM){
						InputDati(mese,incasso,nmese,ctl);
					}
					if(nmese>DIM){
						cout<<"\nHai già inserito i dati di un anno!";
					}
					break;
					
			case 2: cout<<"\nStampa dei dati inseriti...";
					if((ctl)||(nmese==DIM)){
						StampaDati(mese,incasso);
					}else{
						cout<<"\nNon hai inserito tutti i dati!\n";
					}
					break;
					
			case 3: cout<<"\nIncasso annuale";
					if((ctl)||(nmese==DIM)){
						cout<<"\nNel corso dell'anno sono stati incassati "<<IncassoTotale(incasso)<<" euro";
					}else{
						cout<<"\nNon hai inserito tutti i dati!\n";
					}
					break;
					
			case 4: cout<<"\nMese con incasso maggiore";
					if((ctl)||(nmese==DIM)){
						IncassoMax(mese,incasso);
					}else{
						cout<<"\nNon hai inserito tutti i dati!\n";
					}
					break;
			
			case 5:	cout<<"\nMese con incasso minimo";
					if((ctl)||(nmese==DIM)){
						IncassoMin(mese,incasso);
					}else{
						cout<<"\nNon hai inserito tutti i dati!\n";
					}
					break;
					
			case 6: cout<<"\nStampa incassi in ordine crescente";
					if((ctl)||(nmese==DIM)){
						Bubblesort(mese,incasso);
					}else{
						cout<<"\nNon hai inserito tutti i dati!\n";
					}
					break;
					
			case 7: cout<<"\nStampa incassi in ordine decrescente";
					if((ctl)||(nmese==DIM)){
						BubblesortDecrescente(mese,incasso);
					}else{
						cout<<"\nNon hai inserito tutti i dati!\n";
					}
					break;
					
			case 8: cout<<"\nUscita dal programma...";
					break;
		}
		cout<<"\n\n";
		
	}while(scelta!=8);	
	
	return 0;
}

