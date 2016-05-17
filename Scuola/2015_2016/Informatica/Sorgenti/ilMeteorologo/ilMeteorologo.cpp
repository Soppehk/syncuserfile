#include <iostream>
using namespace std;

int InputInt(int& n){
	do{
		cout<<"\n==> ";
		cin>>n;
	}while(n<0);
	return n;
}
float InputFloat(float& n){
	do{
		cout<<"\n==> ";
		cin>>n;
	}while(n<0);
	return n;
}
int GiornoSettimana(int giorno,int primoGiorno){
	int g;
	bool c=false;
	g=giorno;
	do{
		if((g>=1)&&(g<=7)){
			c=true;
		}
		else{
			g=g-7;
			c=false;
		}
	}while(c==false);

	g=g+primoGiorno-1;
	if(g>7){
		g=g-7;
	}
	return g;
}
string GiorniDellaSettimana(int giorno){
	switch(giorno){
		case 1: return "Lunedi'";
	 			break;
		case 2: return "Martedi'";
				break;
		case 3: return "Mercoledi'";
	            break;
		case 4: return "Giovedi'";
			 	break;
		case 5: return "Venerdi'";
			 	break;
		case 6: return "Sabato";
			 	break;
		case 7: return "Domenica";
			 	break;
	}
	return "";
}

void DatiIniziali(float& tempMax, float& tempMin, float& preMax, float& preMin, int& nGiorni,int& primoGiorno){
	do{
		cout<<"\nInserire temperatura massima accettata in gradi Celsius: ";
		cout<<"\n==>";
		cin>>tempMax;
		cout<<"\nInserire temperatura minima accettata in gradi Celsius: ";
		cout<<"\n==>";
		cin>>tempMin;
	}while(tempMin>tempMax);

	do{
		cout<<"\nInserire pressione massima accettata in mbar : ";
		InputFloat(preMax);
		cout<<"\nInserire pressione minima accettata in mbar: ";
		InputFloat(preMin);
	}while(preMin>preMax);

	do{
		cout<<"\nInserire il numero di giorni del mese: ";
		InputInt(nGiorni);
	}while((nGiorni>31)||(nGiorni<1));

	cout<<"\nInserire il giorno della settimana del primo giorno del mese.";
	cout<<"\n1. Lunedi'";
	cout<<"\n2. Martedi'";
	cout<<"\n3. Mercoledi'";
	cout<<"\n4. Giovedi'";
	cout<<"\n5. Venerdi'";
	cout<<"\n6. Sabato";
	cout<<"\n7. Domenica";
	do{
		InputInt(primoGiorno);
	}while((primoGiorno>7)||(primoGiorno<1));
	cout<<" ";
	GiorniDellaSettimana(primoGiorno);

	return;
}

void DatiPerOgniGiorno(float tempMax, float tempMin, float preMax, float preMin, int nGiorni, int primoGiorno, int& giorno, float& tempGiornoMax, float& tempGiornoMin, float& preGiornoMax, float& preGiornoMin, float& mediaTemp, float& mediaPre, int& giornoTempMax, int& giornoTempMin, int& giornoPreMax, int& giornoPreMin){
	float tempGiorno, preGiorno, sommaTemp, sommaPre;
	for(giorno=1;giorno<=nGiorni;giorno++){
		cout<<"\n\nGiorno "<<giorno<<" ";
 		cout<<GiorniDellaSettimana(GiornoSettimana(giorno, primoGiorno));
		do{
			cout<<"\nInserisci la temperatura media della giornata in gradi Celsius";
			cout<<"\n==> ";
			cin>>tempGiorno;
		}while((tempGiorno<tempMin)||(tempGiorno>tempMax));
		do{
			cout<<"\nInserisci la pressione media della giornata in mbar";
			cout<<"\n==> ";
			cin>>preGiorno;
		}while((preGiorno<preMin)||(preGiorno>preMax));
		
		if(tempGiorno>tempGiornoMax){
			tempGiornoMax=tempGiorno;
			giornoTempMax=giorno;
		}
		if(tempGiorno<tempGiornoMin){
			tempGiornoMin=tempGiorno;
			giornoTempMin=giorno;
		}
		if(preGiorno>preGiornoMax){
			preGiornoMax=preGiorno;
			giornoPreMax=giorno;
		}
		if(preGiorno<preGiornoMin){
			preGiornoMin=preGiorno;
			giornoPreMin=giorno;
		}
		sommaTemp=sommaTemp+tempGiorno;
		sommaPre=sommaPre+preGiorno;
		mediaTemp=sommaTemp/nGiorni;
		mediaPre=sommaPre/nGiorni;
	}
	return;
}

void ResocontoDati(float tempGiornoMax, float tempGiornoMin, float preGiornoMax, float preGiornoMin, float mediaTemp, float mediaPre, int giornoTempMax, int giornoTempMin, int giornoPreMax, int giornoPreMin, int primoGiorno){
	char c=167;
	cout<<"\nIl giorno "<<GiorniDellaSettimana(GiornoSettimana(giornoTempMax, primoGiorno))<<" "<<giornoTempMax<<" si e' registrata la temperatura massima del mese, pari a "<<tempGiornoMax<<c<<"C";
	cout<<"\nIl giorno "<<GiorniDellaSettimana(GiornoSettimana(giornoTempMin, primoGiorno))<<" "<<giornoTempMin<<" si e' registrata la temperatura minima del mese, pari a "<<tempGiornoMin<<c<<"C";
	cout<<"\nIl giorno "<<GiorniDellaSettimana(GiornoSettimana(giornoPreMax, primoGiorno))<<" "<<giornoPreMax<<" si e' registrata la pressione massima del mese, pari a "<<preGiornoMax<<" mbar";
	cout<<"\nIl giorno "<<GiorniDellaSettimana(GiornoSettimana(giornoPreMax, primoGiorno))<<" "<<giornoPreMin<<" si e' registrata la pressione minima del mese, pari a "<<preGiornoMin<<" mabar";
	cout<<"\nIn questo mese la temperatura media e' pari a "<<mediaTemp;
	cout<<"\nIn questo mese la pressione media e' pari a "<<mediaPre;
	return;
}

int main(){
	int nGiorni, primoGiorno, giorno, giornoTempMax, giornoTempMin, giornoPreMax, giornoPreMin;
	
	float tempMax, tempMin, preMax, preMin, tempGiornoMax, tempGiornoMin, preGiornoMax, preGiornoMin, mediaTemp, mediaPre;
	DatiIniziali(tempMax, tempMin, preMax, preMin, nGiorni, primoGiorno);
	tempGiornoMax=tempMin; tempGiornoMin=tempMax; preGiornoMax=preMin; preGiornoMin=preMax;
	DatiPerOgniGiorno(tempMax, tempMin, preMax, preMin, nGiorni, primoGiorno, giorno, tempGiornoMax, tempGiornoMin, preGiornoMax, preGiornoMin, mediaTemp, mediaPre, giornoTempMax, giornoTempMin, giornoPreMax, giornoPreMin);
	ResocontoDati(tempGiornoMax, tempGiornoMin, preGiornoMax, preGiornoMin, mediaTemp, mediaPre, giornoTempMax, giornoTempMin, giornoPreMax, giornoPreMin, primoGiorno);
	
	return 1;
}
