#include <iostream>
#include <math.h>
#define DIMC 4
#define DIMM 8
using namespace std;

void InputMsg1(bool a[]){
	int n;
	cout<<"\nInserire il messaggio premendo invio ad ogni cifra(8 bit)\n";
	for(int i=0;i<DIMM;i++){
		do{
			cout<<"\nN"<<i+1<<" ";
			cin>>n;
		}while((n<0)||(n>1));
		a[i]=n;
	}
	
	return;
}

int Ctl(){
	int a;
	
	do{
		cin>>a;
	}while((a!=0)&&(a!=1));
	
	return a; 
}

void InputMsg2(bool bmessaggio[], bool bcontrollo[]){
	cout<<"\nInserire il messaggio premendo invio ad ogni cifra(12 bit)\n";
	
	cout<<"\nN1 ";
	bcontrollo[0]=Ctl();  //C1
	
	cout<<"\nN2 ";
	bcontrollo[1]=Ctl();  //C2
	
	cout<<"\nN3 ";
	bmessaggio[0]=Ctl();  //M3
	
	cout<<"\nN4 ";
	bcontrollo[2]=Ctl();  //C4
	
	cout<<"\nN5 ";
	bmessaggio[1]=Ctl();  //M5
	
	cout<<"\nN6 ";
	bmessaggio[2]=Ctl();  //M6
	
	cout<<"\nN7 ";
	bmessaggio[3]=Ctl();  //M7
	
	cout<<"\nN8 ";
	bcontrollo[3]=Ctl();  //C8
	
	cout<<"\nN9 ";
	bmessaggio[4]=Ctl();  //M9
	
	cout<<"\nN10 ";
	bmessaggio[5]=Ctl();  //M10
	
	cout<<"\nN11 ";
	bmessaggio[6]=Ctl();  //M11
	
	cout<<"\nN12 ";
	bmessaggio[7]=Ctl();  //M12
	
	return;
}

void CalcBitCtl(bool bmessaggio[], bool bcontrollo[]){
	
	bcontrollo[0]=(bmessaggio[0] xor bmessaggio[1] xor bmessaggio[3] xor bmessaggio[4] xor bmessaggio[6]); //C1
				  //M3               //M5              //M7              //M9              //M11
	bcontrollo[1]=(bmessaggio[0] xor bmessaggio[2] xor bmessaggio[3] xor bmessaggio[5] xor bmessaggio[6]); //C2
				  //M3		         //M6	           //M7	             //M10             //M11
	bcontrollo[2]=(bmessaggio[1] xor bmessaggio[2] xor bmessaggio[3] xor bmessaggio[7]);                   //C4
				  //M5			     //M6	  		   //M7	   	         //M12
	bcontrollo[3]=(bmessaggio[4] xor bmessaggio[5] xor bmessaggio[6] xor bmessaggio[7]);                   //C8
				  //M9	 		     //M10             //M11	         //M12
		
	return;
}

void Stampa(bool vett[]){
	for(int i=0;i<DIMC;i++){
		cout<<vett[i]<<" ";
	}
	
	return;
}

void CmpErroriBitCtl(bool bcontrollo[], bool ctlbitc[], int &pse){
	int k=1;
	pse=0;	
	for(int i=0;i<4;i++){
		if(bcontrollo[i]!=ctlbitc[i]){
			pse=pse+k;
		}
		k=k*2;
	}
	
	return;
}

int main(){
	int scelta, uscita, pse;
	bool c[DIMC], ctlbitc[DIMC], m[DIMM];
	
	cout<<"CODIFICA DI HAMMING";
	
	do{
		do{
		cout<<"\n(1)Calcolo bit di controllo da trasmettere";
		cout<<"\n(2)Calcolo bit di controllo e ricerca errori in una sequenza ricevuta\n==> ";
		cin>>scelta;
		}while((scelta!=1)&&(scelta!=2));
		
		switch(scelta){
			case 1: cout<<"\nCodifica";
					InputMsg1(m);
					CalcBitCtl(m,c);
					cout<<"\nStampa Bit Controllo  ";
					Stampa(c);
					break;
					
			case 2: cout<<"\nDecodifica";
					InputMsg2(m,c);
					CalcBitCtl(m,ctlbitc);
					cout<<"\nStampa bit di controllo corretti  ";
					Stampa(ctlbitc);
					CmpErroriBitCtl(c,ctlbitc,pse);
					if(pse==0){
						cout<<"\nNon sono presenti errori";
					}else{
						cout<<"\nErrore in posizione "<<pse;
					}
					break;
		}
		cout<<"\nVuoi ripetere?(1)SI'";
		cin>>uscita;
		
	}while(uscita==1);
	
	return 0;
}
