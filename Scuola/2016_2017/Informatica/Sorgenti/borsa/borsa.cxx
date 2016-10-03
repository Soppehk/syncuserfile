#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

#define DIM 100

struct data {
	int giorno;
	int mese;
	int anno;
};

struct titolo {
	string nome;
	string codice;
	struct data;
	int quot;
};

void ControlloFile(struct titolo titoli[DIM], fstream &file, char nomefile[128]) {

	cout << "Inserisci il nome del file da cui prendere i dati: ";
	cin >> nomefile;
	file.open(nomefile, ios::in);
	if(file.fail()) {
		cout << "Il file " << nomefile << " non esiste!" << endl;
		cout << "ERRORE" << endl;
		file.close();
		exit(1);
	} else {
		cout << "Il file " << nomefile << " e' valido" << endl;
		file.close();
	}

	return;
}

void CaricoVettore(struct titolo titolimax[DIM], string riga) {


}

void LeggoFile(struct titolo titoli[DIM], struct titolo titolimax[DIM], fstream &file, char nomefile[128]) {
	file.open(nomefile, ios::in);
	string riga;
	int i = 0;

	while(!file.eof()) {
		getline(file, riga);
		cout << riga << endl;

		i++;
	}

	return;
}

int main (int argc, char const *argv[]) {
	struct titolo titoli[DIM];
	struct titolo titolimax[DIM];
	fstream file;
	char nomefile[128];

	cout << "Gestore titoli di borsa" << endl;
	ControlloFile(titoli, file, nomefile);
	LeggoFile(titoli, titolimax, file, nomefile);

	return 0;
}
