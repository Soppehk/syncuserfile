#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

#define DIM 50

void AzzerMatr(int m[][DIM], int nr, int nc) {
	for(int i = 0; i < nr; i++) {
		for(int j = 0; j < nc; j++ ) {
			m[i][j] = 0;
		}
	}
	
	return;
}

void StampaMatr(int m[][DIM], int nr, int nc) {
	cout << "Stampa contenuto matrice..." << endl << endl;
	for(int i = 0; i < nr; i++) {
		for(int j = 0; j < nc; j++ ) {
			printf("%4d", m[i][j]);
		}
		cout << endl;
	}
	
	return;
}

void Input (int &n) {
	do {
		cout << "Inserisci numero compreso tra 3 e " << DIM << " : ";
		cin >> n;
	} while ((n < 3) || (n > DIM));
	
	return;
}

void SpiraMatr(int m[][DIM], int nr, int nc) {
	int valore = 1, r = 0, c = 0, finito = 0, lsc = 0, ldc = nc - 1, lar = 0, lbr = nr -1;
	
	cout << "Genero matrice..." << endl;
	//scrivo la spirale
	while ((lar <= lbr) && (lsc <= ldc)) {
		//vado a dx sulla riga
		while (c <= ldc) {
			m[r][c] = valore;
			valore++;
			c++;
		}
		c--;
		r++;
		//vado in giù sulla colonna
		while (r <= lbr) {
			m[r][c] = valore;
			valore++;
			r++;
		}
		c--;
		r--;
		//vado a sx sulla riga
		while ( c >= lsc) {
			m[r][c] = valore;
			valore++;
			c--;
		}
		c++;
		r--;
		//vado in su sulla riga
		while ( r > lar) {
			m[r][c] = valore;
			valore++,
			r--;
		}
		c++;
		r++;
		lsc++;
		ldc--;
		lar++;
		lbr--;
	}
	
	return;
}

int main() {
	int matr[DIM][DIM];
	int n;
	
	Input(n);	
	AzzerMatr(matr,n,n);
	SpiraMatr(matr,n,n);
	StampaMatr(matr,n,n);
	
	return 0;
}


