#include <iostream>
#include <stdlib.h>
#include <time.h>
#define DIM 50
using namespace std;

void Input(float &prtr0, float &prer0, float &prer1){
	cout<<"Inserire la probabilita' di trasmettere 0";
	do{
		cout<<"\n==> ";
		cin>>prtr0;
	}while((prtr0<0)||(prtr0>1));
	
	cout<<"\nInserire la probabilita' dell'errore sullo 0";
	do{
		cout<<"\n==> ";
		cin>>prer0;
	}while((prer0<0)||(prer0>1));
	
	cout<<"\nInserire la probabilita' dell'errore sull'1";
	do{
		cout<<"\n==> ";
		cin>>prer1;
	}while((prer1<0)||(prer1>1));
	
	return;
}

void ElaborazioneDati(float prtr0, float &prtr1, float &pr0, float &pr1, float prer0, float prer1, float &pro0, float &pro1){
	prtr1=1-prtr0;
	pr0=1-prer0;
	pr1=1-prer1;
	
	pro0=pr0*prtr0+prer1*prtr1;
	pro1=pr1*prtr1+prer0*prtr0;
	
	return;
}

void CreazioneVettoreBitTrasmessi(int vett[], float prtr0, int &nume0, int &nume1){
	int i;
	nume0=0;
	nume1=0;
	double n;
	
	srand((unsigned)time(NULL)); //Inizializzazione del seme
	
	do{
		n=(double)(rand())/((double)RAND_MAX+1.0); //Assegnazione alla variabile di un valore espresso in virgola mobile, compreso tra 0 e 1
		if(n<prtr0){
			vett[i]=0;
			nume0++;
		}else{
			vett[i]=1;
			nume1++;
		}
		i++;
	}while(i<DIM);	
	
	return;
}

void CreazioneVettoreBitRicevuti(int vett[], int vetr[],float prtr0, float prtr1, int &nume0, int &nume1){
	double n;
	int i=0;
	srand((unsigned)time(NULL)); //Inizializzazione del seme
	nume0=0;
	nume1=0;
	
	do{
		n=(double)(rand())/((double)RAND_MAX+1.0); //Assegnazione alla variabile di un valore espresso in virgola mobile, compreso tra 0 e 1
		
		if(vett[i]==0){
			if(n<prtr0){
				vetr[i]=1;
				nume0++;
			}else{
				vetr[i]=0;
			}
		}else{
			if(n<prtr1){
				vetr[i]=0;
				nume1++;
			}else{
				vetr[i]=1;
			}
		}
		i++;
	}while(i<DIM);	

	return;
}

void StampaVettore(int vett[]){
	for(int i=0;i<DIM;i++){
		cout<<vett[i]<<" ";
	}
	
	return;
}

int main(){
	int vt[DIM], vr[DIM], num0t, num1t, nume0r, nume1r;
	float pt0,pt1,p1,p0,pe0,pe1,pr0,pr1;
	char scelta;
	
	do{
		//Raccolata dati in input
		Input(pt0,pe0,pe1);
		//Elaborazione dati
		cout<<"\nElaborazione dati...";
		ElaborazioneDati(pt0,pt1,p1,p0,pe0,pe1,pr0,pr1);
		//Generazione vettore bit trasmessi
		cout<<"\nGerazione vettore bit trasmessi...";
		CreazioneVettoreBitTrasmessi(vt,pt0,num0t,num1t);
		//Stampa vettore bit trasmessi
		cout<<"\nStampa vettore bit trasmessi... ";
		StampaVettore(vt);
		//Generazione vettore bit ricevuti
		cout<<"\nGenerazione vettore bit ricevuti...";
		CreazioneVettoreBitRicevuti(vt,vr,pr0,pr1,nume0r,nume1r);
		//Stampa vettore bit ricevuti
		cout<<"\nStampa vettore bit ricevuti... ";
		StampaVettore(vr);
		
		
		//Statistiche
		cout<<"\n\nProbabilita' di trasmettere 0: "<<pt0;
		cout<<"\nProbabilita' di trasmettere 1: "<<pt1;
		cout<<"\nProbabilita' di trasmettere 0 e ricevere 0: "<<p0;
		cout<<"\nProbabilita' dell'errore sullo 0: "<<pe0;
		cout<<"\nProbabilita' di trasmettere 1 e ricevere 1: "<<p1;
		cout<<"\nProbabilita' dell'errore sull'1: "<<p1;
		cout<<"\nProbabilita' di ricevere 0: "<<pr0;
		cout<<"\nProbabilita' di ricevere 1: "<<pr1;
		
		cout<<"\n\nNumero bit 0 trasmessi: "<<num0t;
		cout<<"\nNumero bit 1 trasmessi: "<<num1t;
		cout<<"\nNumero bit 0 ricevuti: "<<num0t-nume0r;
		cout<<"\nNumero bit 1 ricevuti: "<<num1t-nume1r;
		cout<<"\nNumero errori bit 0 ricevuti: "<<nume0r;
		cout<<"\nNumero errori bit 1 ricevuti: "<<nume1r;
		
		cout<<"\n\nVuoi ripetere? s=SI'\n==> ";
		cin>>scelta;
		
	}while((scelta=='s')||(scelta=='S'));
	
	return 0;
}
