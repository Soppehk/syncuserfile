#include <iostream>
using namespace std;

//funzione che prende in input il lato di un quadrato e ne restituisce il perimetro
void Perquad(){
	float lato;
	do{	
		cout<<"\nInserisci lato: ";
		cin>>lato;
	}while(lato<0);
	cout<<"\nPerimetro="<<lato*4;
	return;
	}

//funzione che prende in input il lato di un quadrato e ne restituisce l’area	
void Areaquad(){
	float lato;
	do{
		cout<<"\nInserisci lato: ";
		cin>>lato;
		}while(lato<0);
	cout<<"\nArea="<<lato*lato;
	return;
	}

//funzione che prende in input la base e l’altezza di un rettangolo e ne restituisce il perimetro
void Perret(){
	float base, altezza;
	do{
		cout<<"\nInserisci base: ";
		cin>>base;
		cout<<"\nInserisci altezza: ";
		cin>>altezza;
		}while((base<0)||(altezza<0));
	cout<<"\nPerimetro="<<base*2+altezza*2;
	return;
	}

//funzione che prende in input la base e l’altezza di un rettangolo e ne restituisce l'area
void Arearet(){
	float base, altezza;
	do{
		cout<<"\nInserisci base: ";
		cin>>base;
		cout<<"\nInserisci altezza: ";
		cin>>altezza;
		}while((base<0)||(altezza<0));
	
	cout<<"\nArea="<<base*altezza;
	return;
	}	

//funzione che prende in input base, altezza e lato di un triangolo e ne restituisce il perimetro e l'area
void Perareatri(){
	float base, altezza, lato;
	do{
		cout<<"\nInserisci base: ";
		cin>>base;
		cout<<"\nInserisci altezza: ";
		cin>>altezza;
		cout<<"\nInserisci lato: ";
		cin>>lato;
		}while((base<0)||(altezza<0)||(lato<0));
	cout<<"\nPerimetro="<<base+altezza+lato;
	cout<<"\nArea="<<base*altezza/2;
	return;
	}	
	
//funzione che prende in input  diagonale maggiore, diagonale minore e 4 lati di un rombo e ne restituisce il perimetro e l'area
void Perarearomb(){
	float diagmax, diagmin, l1,l2,l3,l4;
	do{
		cout<<"\nInserisci diagonale maggiore: ";
		cin>>diagmax;
		cout<<"\nInserisci diagonale minore: ";
		cin>>diagmin;
		cout<<"\nInserisci primo lato: ";
		cin>>l1;
		cout<<"\nInserisci secondo lato: ";
		cin>>l2;
		cout<<"\nInserisci terzo lato: ";
		cin>>l3;
		cout<<"\nInserisci quarto lato: ";
		cin>>l4;
		}while((diagmax<diagmin)||(diagmax<0)||(diagmin<0)||(l1<0)||(l2<0)||(l3<0)||(l4<0));
	cout<<"\nPerimetro="<<l1+l2+l3+l4;
	cout<<"\nArea="<<diagmax*diagmin/2;
	return;
	}

//funzione che prende in input base maggiore, base minore, altezza e 2 lati di un trapezio e ne restituisce il perimetro e l'area	
void Perareatrap(){
	float basemax,basemin,altezza, l1,l2;
	do{
		cout<<"\nInserisci base maggiore: ";
		cin>>basemax;
		cout<<"\nInserisci base minore: ";
		cin>>basemin;
		cout<<"\nInserisci altezza: ";
		cin>>altezza;
		cout<<"\nInserisci il primo lato obliquo: ";
		cin>>l1;
		cout<<"\nInserisci il secondo lato obliquo: ";
		cin>>l2;
		}while((basemax<basemin)||(basemax<0)||(basemin<0)||(altezza<0)||(l1<0)||(l2<0));
	cout<<"\nPerimetro="<<basemax+basemin+l1+l2;
	cout<<"\nArea="<<(basemax+basemin)*altezza/2;
	
	return;
	}			
	
//funzione che permette di scegliere una opzione	
void Menu(){
	int scelta;
	
	do{
		cout<<"Inserisci:\n1 per perimetro quadrato\n2 per area quadrato\n3 per perimetro rettangolo\n4 per area rettangolo\n5 per perimetro e area triangolo\n6 per perimetro e area rombo\n7 per perimetro e area trapezio\n==> ";
		cin>>scelta;
		}while((scelta<=0)&&(scelta>=8)); 
	
	switch(scelta){
		case 1: cout<<"\nperimetro quadrato";
					   Perquad();
					   break;
		case 2: cout<<"\narea quadrato";
					   Areaquad();
					   break;
		case 3: cout<<"\nperimetro rettangolo";
					   Perret();
					   break;
		case 4: cout<<"\narea rettangolo";
					  Arearet();
					  break;
		case 5: cout<<"\nperimetro e area triangolo";
					  Perareatri();
					  break;
		case 6: cout<<"\nperimetro e area rombo";
					  Perarearomb();
					  break;
		case 7: cout<<"\nperimetro e area trapezio";
					  Perareatrap();
					  break;
		}
		return;
	}


int main(){
	
	Menu();
	
	return 1;
	}
