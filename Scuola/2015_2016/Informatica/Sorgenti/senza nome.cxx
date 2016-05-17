#include <iostream>
using namespace std;

float Perquad(){
	float lato, per;
	do{	
		cout<<"\nInserisci lato: ";
		cin>>lato;
	}while(lato<0);
	per=lato*4;
	return per;
	}
	
float Areaquad(){
	float lato, area;
	do{
		cout<<"\nInserisci lato: ";
		cin>>lato;
		}while(lato<0);
	area=lato*lato;
	return area;
	}

float Perret(){
	float base, altezza, per;
	do{
		cout<<"\nInserisci base: ";
		cin>>base;
		cout<<"\nInserisci altezza: ";
		cin>>altezza;
		}while((base<0)&&(altezza<0));
	per=base*2+altezza*2;
	return per;
	}

float Arearet(){
	float base, altezza, area;
	do{
		cout<<"\nInserisci base: ";
		cin>>base;
		cout<<"\nInserisci altezza: ";
		cin>>altezza;
		}while((base<0)&&(altezza<0));
	
	area=base*altezza;
	return area;
	}	

void Perareatri(){
	float base, altezza, lato;
	do{
		cout<<"\nInserisci base: ";
		cin>>base;
		cout<<"\nInserisci altezza: ";
		cin>>altezza;
		cout<<"\nInserisci lato: ";
		cin>>lato;
		}while((base<0)&&(altezza<0)&&(lato<0));
	cout<<"\nPerimetro="<<base+altezza+lato;
	cout<<"\nArea="<<base*altezza/2;
	return;
	}	
	
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
		}while((diagmax<diagmin)&&(diagmax<0)&&(diagmin<0)&&(l1<0)&&(l2<0)&&(l3<0)&&(l4<0));
	cout<<"\nPerimetro="<<l1+l2+l3+l4;
	cout<<"\nArea="<<diagmax*diagmin/2;
	return;
	}
	
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
		}while((basemax<basemin)&&(basemax<0)&&(basemin<0)&&(altezza<0)&&(l1<0)&&(l2<0));
	cout<<"\nPerimetro="<<basemax+basemin+l1+l2;
	cout<<"\nArea="<<(basemax+basemin)*altezza/2;
	
	return;
	}			
	
void Menu(){
	int scelta;
	
	do{
		cout<<"Inserisci:\n1 per perimetro quadrato\n2 per area quadrato\n3 per perimetro rettangolo\n4 per area rettangolo\n5 per perimetro e area triangolo\n6 per perimetro e area rombo\n7 per perimetro e area trapezio\n==> ";
		cin>>scelta;
		}while((scelta<=0)&&(scelta>=8)); 
	
	switch(scelta){
		case 1: cout<<"\nperimetro quadrato";
					   cout<<"\nPerimetro="<<Perquad();
					   break;
		case 2: cout<<"\narea quadrato";
					   cout<<"\nArea="<<Areaquad();
					   break;
		case 3: cout<<"\nperimetro rettangolo";
					   cout<<"\nPerimetro="<<Perret();
					   break;
		case 4: cout<<"\narea rettangolo";
					  cout<<"\nArea="<<Arearet();
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
