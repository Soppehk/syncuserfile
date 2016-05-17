#include <iostream>
#include <math.h>
using namespace std;

int scelta, ctl;

void Menu(int);
int Ctlinput();
float Areaquad();
float Arearett();
float Areatri();
float Arearomb();
float Areatrap();
float Perquad();
float Perrett();
float Pertri();
float Perromb();
float Pertrap();


int main(){
	
	do{
		cout<<"1: quadrato, 2: rettangolo, 3: triangolo, 4: rombo, 5: trapezio\n==> ";
		cin>>scelta;
		}while((ctl=0));
		Menu(scelta);
		
		return 1;
	}
	
void Menu(){
	switch(scelta){
		case 1: cout<<"\nquadrato";
					  cout<<"\nArea: "<<Areaquad();
					  cout<<"\nPerimetro: "<<Perquad();
					  break;
		case 2: cout<<"\nrettangolo";
					  cout<<"\nArea: "<<Arearett();
					  cout<<"\nPerimetro: "<<Perrett();
					  break;			  			
		case 3: cout<<"\ntriangolo";
					  cout<<"\nArea: "<<Areatri();
					  cout<<"\nPerimetro: "<<Pertri();
					  break;
		case 4: cout<<"\nrombo";
					  cout<<"\nArea: "<<Arearomb();
					  cout<<"\nPerimetro: "<<Perromb();	
					  break;
		case 5: cout<<"\ntrapezio";
					  cout<<"\nArea: "<<Areatrap();
					  cout<<"\nPerimetro: "<<Pertrap();
					  break;
		}
	return;	
	}	
	
int Ctlinput(){
	if((scelta<=0) || (scelta>5)){
		ctl=1;
		}
		else{
			ctl=2;
			}
	return ctl;		
	}	
	
float Areaquad(float area){
	area=
	}	
	
