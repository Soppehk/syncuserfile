#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
	float x, y, z, area, prezzo_pittura, costo_pittura;
	
	cout <<"Inserire il lato lungo: ";
	cin >>x;
	cout <<"\nInserire il l'altezza: ";
	cin >>y;
	cout <<"\nInserire il lato corto: ";
	cin >>z;
	cout <<"\nInserire il prezzo della vernice al metro cubo: ";
	cin >>prezzo_pittura;
	
	area = x*y*2+z*y*2+x*y;
	cout <<"\nLa superifice da pitturare e' pari a: "<<area;
	costo_pittura = area*prezzo_pittura;
	cout <<"\nIl costo totale della pittura è pari a: "<<costo_pittura;
	getchar();
	return 1;
	}
