#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include <string>
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
	string data;
	struct data datidata;
	string quot;
};

void ControlloFile(fstream &file, char nomefile[128]) {
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

void SoloMax(struct titolo t[DIM], int &numline) {
	for (int i = 0; i < DIM; i++) {
		for (int j = 0; j < DIM; j++) {
			if (t[j].codice == t[i].codice) {
				if (t[j].quot > t[i].quot) {
					t[i].nome = "";
				}
			}
		}
	}

	return;
}

void LeggoFile(struct titolo t[DIM], fstream &file, char nomefile[128], int &numline) {
	file.open(nomefile, ios::in);
	int i = 0;
	string riga;

	while(!file.eof()) {
		getline(file, riga);
		istringstream iss(riga);
		iss >> t[i].nome;
		iss >> t[i].codice;
		iss >> t[i].data;
		iss >> t[i].quot;
		i++;
		numline++;
	}

	return;
}

void Stampa(struct titolo t[DIM], int numline) {
	string mese;
	int nmese;

	cout << "Stampa in corso..." << endl;
	for (int i = 0; i < numline; i++) {
		if (t[i].nome != "") {
			mese = t[i].data;
			istringstream iss(t[i].data);
			getline(iss, t[i].datidata.giorno, '/');
			getline(iss, t[i].datidata.mese, '/');
			getline(iss, t[i].datidata.anno);
			stringstream(t[i].datidata.mese) >> nmese; //converte string -> int e copia nello struct
			switch (nmese) {
		 		case 1:
		 			mese = "Gennaio";
		 			break;
			 	case 2:
			 		mese = "Febbraio";
			 		break;
			 	case 3:
			 		mese = "Marzo";
			 		break;
			 	case 4:
			 		mese = "Aprile";
			 		break;
		 		case 5:
			 		mese = "Maggio";
		 			break;
			 	case 6:
			 		mese = "Giugno";
			 		break;
			 	case 7:
			 		mese = "Luglio";
			 		break;
			 	case 8:
			 		mese = "Agosto";
			 		break;
			 	case 9:
			 		mese = "Settembre";
		 			break;
		 		case 10:
		 			mese = "Ottobre";
		 			break;
		 		case 11:
		 			mese = "Novembre";
		 			break;
		 		case 12:
		 			mese = "Dicembre";
		 			break;
		 		default:
		 			mese = "???";
		 	}
		 	cout << t[i].nome << " (" << t[i].codice << ") " << t[i].datidata.giorno << " " << mese << " " << t[i].datidata.anno << " " << t[i].quot << endl;
		}
	}

	return;
}

int main (int argc, char const *argv[]) {
	struct titolo t[DIM];
	fstream file;
	int numline = 0;
	char nomefile[128];

	cout << "Gestore titoli di borsa" << endl;
	ControlloFile(file, nomefile);
	LeggoFile(t, file, nomefile, numline);
	SoloMax(t, numline);
	Stampa(t, numline);

	return 0;
}
