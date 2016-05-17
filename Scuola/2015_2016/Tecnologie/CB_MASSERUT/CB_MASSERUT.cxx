#include <iostream>
#include <stdlib.h>
using namespace std;

void Input(float &pt0, float &pe0, float &pe1){
	cout<<"Inserire la probabilita' di trasmettere 0";
	do{
		cout<<"\n==> ";
		cin>>pt0;
	}while((pt0<0)||(pt0>1));
	
	cout<<"\nInserire la probabilita' dell'errore sullo 0";
	do{
		cout<<"\n==> ";
		cin>>pe0;
	}while((pe0<0)||(pe0>1));
	
	cout<<"\nInserire la probabilita' dell'errore sull'1";
	do{
		cout<<"\n==> ";
		cin>>pe1;
	}while((pe1<0)||(pe1>1));
	
	return;
}

void ElaborazioneDati(float pt0, float &pt1, float &p0, float &p1, float pe0, float pe1, float &pr0, float &pr1){
	pt1=1-pt0;
	p0=1-pe0;
	p1=1-pe1;
	
	pr0=p0*pt0+pe1*pt1;
	pr1=p1*pt1+pe0*pt0;
	
	return;
}

void CreazioneTabella(float pt0){
	double n;
	int bit, num0, num1, s;
	bool scelta=true;
	
	do{
		srand((unsigned)time(NULL)); //Inizializzazione del seme
		num0=0;
		num1=0;
		cout<<"\n\n";
		for(int i=0;i<7;i++){
			for(int k=0;k<7;k++){
				n=(double)(rand())/((double)RAND_MAX+1.0); //Assegnazione alla variabile di un valore espresso in virgola mobile, compreso tra 0 e 1
				if(n<pt0){
					bit=0;
					num0++;
				}else{
					bit=1;
					num1++;
				}
				cout<<bit<<"  ";
			}
			cout<<"\n";
		}
		cout<<"\n\nNum0 = "<<num0;
		cout<<"\n\nNum1 = "<<num1;
		cout<<"\n\nRipetere? 1.SI' 2.NO\n==>";
		cin>>s;
		if(s==2){
			scelta=false;
		}
		
	}while(scelta==true);
	
	return;
}

int main(){
	float pt0,pt1,p1,p0,pe0,pe1,pr0,pr1;
	
	//Raccolata dati in input
	Input(pt0,pe0,pe1);
	//Elaborazione dati
	ElaborazioneDati(pt0,pt1,p1,p0,pe0,pe1,pr0,pr1);
	//Stampa dati
	cout<<"\nProbabilita' di trasmettere 0: "<<pt0;
	cout<<"\nProbabilita' di trasmettere 1: "<<pt1;
	cout<<"\nProbabilita' di trasmettere 0 e ricevere 0: "<<p0;
	cout<<"\nProbabilita' dell'errore sullo 0: "<<pe0;
	cout<<"\nProbabilita' di trasmettere 1 e ricevere 1: "<<p1;
	cout<<"\nProbabilita' dell'errore sull'1: "<<p1;
	cout<<"\nProbabilita' di ricevere 0: "<<pr0;
	cout<<"\nProbabilita' di ricevere 1: "<<pr1;
	
	//CreazioneTabella
	cout<<"\n\nCreazione tabella...";
	CreazioneTabella(pt0);
	
	return 0;
}
