#include <iostream>
#include <stdio.h>
using namespace std;

float totaleCassa, cifrainiziale, imin=1000000, imax, pmax;
int qmax, qmin=1000000, numeroClienti;

//funzione che stabilisce l'importo massimo
float Imax(float a){
	if(a>=imax){
	      imax=a;
	}
	return imax;
}
//funzione che stabilisce l'importo minimo
float Imin(float a){
	if(numeroClienti==1){
		imin=imax;						 	
	}else{
		if(a<=imin){
		imin=a;
		}	
	 }
		
	return imin;
}
//funzione che stabilisce la quantità massima venduta a un cliente di un oggetto
int Qmax(int a){
	if(a>=qmax){
		qmax=a;
	}
	return qmax;
}
//funzione che stabilisce la quantità minima venduta a un cliente di un oggetto
int Qmin(int a){
	if(numeroClienti==1){
		qmin=qmax;						 	
	}else{
		if(a<=qmin){
		qmin=a;
	return qmin;
	}
	}
}
//funzione che stabilisce il prezzo unitario massimo
float Pmax(float a){
	if(a>=pmax){
		pmax=a;
	}
	return pmax;
}

//funzione che si occupa della gestione dei singoli clienti
void Cliente(){
	float prezzo=0, conto=0, denaroCliente=0, resto=0;
	int quantita=0, scelta, totalearticoli=0;
	
	do{
	   	do{
		cout<<"\nInserire prezzo unitario dell'articolo: ";
		cin>>prezzo;
		cout<<"\nInserire la quantita' degli oggetti: ";
		cin>>quantita;
		if(prezzo>=pmax){
			pmax=prezzo;
		}
		}while(quantita<=0);
		
		do{
			cout<<"\nSe il cliente vuole acquistare altri prodotti inserire 1 altrimenti 0: ";
			cin>>scelta;
		}while((scelta!=1) && (scelta!=0));
		
		conto=conto+prezzo*quantita;
		
		totalearticoli=totalearticoli+quantita;
	
	}while(scelta==1);
	
	cout<<"\nIl conto totale e': "<<conto;
	cout<<"\nIl numero totale di articoli e': "<<totalearticoli;
	
	do{ 
		cout<<"\nIn cassa ci sono: "<<totaleCassa<<" euro";
		do{
		cout<<"\nIl resto non deve essere maggiore del denaro presente in cassa,\nin caso il problema dovesse verificarsi chiedere al cliente di dare meno denaro";	
		cout<<"\nImmettere la somma versata dal cliente: ";
		cin>>denaroCliente;
		
		}while((denaroCliente<0)||(denaroCliente<conto));
	
		resto=denaroCliente-conto;
		cout<<"\nIl resto e' "<<resto<<" euro";
	}while(resto>totaleCassa);
	
	totaleCassa=totaleCassa+conto;
	numeroClienti=numeroClienti+1;
	Imax(conto);
	Imin(conto);
	Pmax(prezzo);
	Qmax(quantita);
	Qmin(quantita);
	
	return;
}

int main(){
    int altriClienti;
    
	cout<<"Buongiorno";
	do{
		cout<<"\nInserisci cifra presente in cassa: ";
		cin>>cifrainiziale;
	}while(cifrainiziale<0);
	
	totaleCassa=totaleCassa+cifrainiziale;
	
	do{
		do{
			Cliente();
			cout<<"\nCi sono altri clienti? 1:SI' 0:NO\n==> ";
  		    cin>>altriClienti;
		}while((altriClienti!=1)&&(altriClienti!=0));
		
	}while(altriClienti==1);
	
	cout<<"\nIn cassa ci sono "<<totaleCassa<<" euro";
	cout<<"\nOggi l'incasso e' "<<totaleCassa-cifrainiziale<<" euro";
	cout<<"\nL'importo massimo e' stato di "<<imax;
	cout<<"\nL'importo minimo e' stato di "<<imin;
	cout<<"\nLa quantita' massima venduta a un cliente di un oggetto: "<<qmax;
	cout<<"\nLa quantita' minima venduta a un cliente di un oggetto: "<<qmin;
	cout<<"\nOggi sono venuti "<<numeroClienti<<" clienti";
	cout<<"\nIl prezzo unitario massimo e' "<<pmax<<" euro";
	
	getchar();
	return 1;
}
