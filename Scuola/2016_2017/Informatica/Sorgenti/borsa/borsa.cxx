#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <sstream>
using namespace std;

#define DIM 100

struct data {
	string giorno;
	string mese;
	string anno;
};

struct titolo {
	string nome;
	string codice;
	struct data datidata;
	string quot;
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

void LeggoFile(struct titolo titoli[DIM], fstream &file, char nomefile[128], int &numline) {
	file.open(nomefile, ios::in);
	string riga;
	int i = 0;

	while(!file.eof()) {
		getline(file, riga);
		cout << riga << endl;
		istringstream iss(riga);
		getline(iss, titoli[i].nome, ' ');
		getline(iss, titoli[i].codice, ' ');
		getline(iss, titoli[i].datidata.giorno, '/');
		getline(iss, titoli[i].datidata.mese, '/');
		getline(iss, titoli[i].datidata.anno, ' ');
		getline(iss, titoli[i].quot);
		i++;
	}
	numline = i - 1;

	return;
}

bool Presente(struct titolo titolomax[DIM], int numline2, string codice) {
	for (int i = 0; i < numline2; i++) {
		if (titolomax[i].codice == codice) {
			return false;
		}
	}

	return true;
}

void CopioMax(struct titolo titoli[DIM], struct titolo titolimax[DIM], int &numline) {
	string max;
	int numline2 = 0;
	for (int i = 0; i < numline; i++) {
		max = titoli[i].quot;
		for (int j = 0; j < numline; j++) {
			if ((titoli[j].codice == titoli[i].codice) && (titoli[j].quot >= max)/* && Presente(titolimax, numline2, titoli[i].codice)*/) {
				max = titoli[j].quot;
				titolimax[i] = titoli[i];
				numline2++;
			}
		}
	}
	numline = numline2;

	return;
}

void Stampa(struct titolo titolimax[DIM], int numline) {
	cout << "Stampa in corso..." << endl;
	for (int i = 0; i < numline; i++) {
		cout << titolimax[i].nome << " (" << titolimax[i].codice << ") " << titolimax[i].datidata.giorno << " " << titolimax[i].datidata.mese << " " << titolimax[i].datidata.anno << " " << titolimax[i].quot << endl;
	}
}

int main (int argc, char const *argv[]) {
	struct titolo titoli[DIM];
	struct titolo titolimax[DIM];
	fstream file;
	int numline;
	char nomefile[128];

	cout << "Gestore titoli di borsa" << endl;
	ControlloFile(titoli, file, nomefile);
	LeggoFile(titoli, file, nomefile, numline);
	CopioMax(titoli, titolimax, numline);
	Stampa(titolimax, numline);

	return 0;
}
