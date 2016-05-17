#include <iostream>
using namespace std;

float Input(float& n){
	do{
		cin>>n;
		}while(n<0);
	return n;	
	}

float Spazio(float a, float b){
	return (a*b);
	}

float Tempo(float a, float b){
	return (a/b);
	}

float Velocita(float a, float b){
	return (a/b);
	}

int main(){
	float s,t,v;
	int scelta;
	
	cout<<"\nSpazio==> 1";
	cout<<"\nTempo==> 2";
	cout<<"\nVelocita'==> 3";
	
	do{	
		cout<<"\nInserire scelta: ";
		cin>>scelta;
		}while(scelta<=0||scelta>3);
		
	switch(scelta){
		case 1: cout<<"\nInserisci velocita': ";
				Input(v);
				cout<<"\nInserisci tempo: ";
				Input(t);
				cout<<"\nSpazio= "<<Spazio(v,t);
				break;
		
		case 2: cout<<"\nInserisci spazio: ";
				Input(s);
				cout<<"\nInserisci velocita': ";
				Input(v);
				cout<<"\nTempo= "<<Tempo(s,v);
				break;
				
		case 3: cout<<"\nInserisci spazio: ";
				Input(s);
				cout<<"\nInserisci tempo: ";
				Input(t);
				cout<<"\nVelocita'= "<<Velocita(s,t);
				break;		
		}
		
	return 1;	
	}			

/*
#include <iostream>
using namespace std;

float Input(float& n){
	do{
		cin>>n;
		}while(n<0);
	return n;	
	}

void InserimentoDati(float& d, float& d1, float& d2, float& v1, float& v2){
	cout<<"Inserire distanza tra le due citta': ";
	Input(d);
	do{
		cout<<"\nInserire distanza percossa dalla prima auto: ";
		Input(d1);
		}while(d1>d);
	do{
		cout<<"\nInserire distanza percossa dalla seconda auto: ";
		Input(d2);
		}while(d2>d);	
	cout<<"\nInserire velocita' della prima auto: ";
	Input(v1);
	cout<<"\nInserire velocita' della seconda auto: ";
	Input(v2);
	return;
	}	

float Tempo(float a, float b){
	return (a/b);
	}	
	
void Calcoli(float d, float d1, float d2, float v1, float v2){
	cout<<"\nLa prima auto impieghera' "<<Tempo((d-d1),v1)<<" ore ad arrivare a destinazione";
	cout<<"\nLa seconda auto impieghera' "<<Tempo((d-d2),v2)<<" ore ad arrivare a destinazione";
	if(Tempo((d-d2),v2)>Tempo((d-d1),v1)){
		cout<<"\nLa prima auto arrivera' prima a destinazione";
		cout<<"\nLa seconda auto arrivera' dopo "<<Tempo((d-d2),v2)-Tempo((d-d1),v1)<<" ore";
		}else{
			cout<<"\nLa seconda auto arrivera' prima a destinazione";
			cout<<"\nLa prima auto arrivera' dopo "<<Tempo((d-d1),v1)-Tempo((d-d2),v2)<<" ore";
			}
	return;		
	}
	
int main(){
	float d,d1,d2,v1,v2;
	InserimentoDati(d,d1,d2,v1,v2);
	Calcoli(d,d1,d2,v1,v2);	
	return 1;
	}
*/
