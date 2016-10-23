#include <iostream>
#include <fstream>
#include <cstring>
#define DIM 10
using namespace std;

class persona {
	char nome[20];
	char cognome[20];
	int eta;
	bool cancellato;
public:
	persona();
	void elimina();
	void recupera();
	void setNome(char *);
	void setCognome(char *);
	void setEta(int);
	char getNome();
	char getCognome();
	int getEta();
};

persona::persona() {
	cancellato = false;
}

void persona::setNome(char c[20]) {
	strcpy(c, nome);
}

void persona::setCognome(char c[20]) {
	strcpy(c, cognome);
}

void persona::setEta(int i) {
	eta = i;
}

char persona::getNome() {
	return *nome;
}

char persona::getCognome() {
	return *cognome;
}

int persona::getEta() {
	return eta;
}

void persona::elimina() {
	cancellato = true;
}

void persona::recupera() {
	cancellato = false;
}

void leggo(persona persone[], fstream &f, int &nel) {
	cout << "leggo" << endl;
	f.open("file.bin", ios::binary | ios::in);
	nel = 0;

	f.read((char*)&persone[nel], sizeof(persona));
	while (!f.eof()) {
		cout << nel;
		nel++;
		f.read((char*)&persone[nel], sizeof(persona));
	}

	f.close();

	return;
}

void cancello(persona persone[], fstream &f, fstream &ftmp, int nel) {
	int el;

	cout << "Quale vuoi cancellare? " << endl;
	do {
		cout << "==> ";
		cin >> el;
	} while ((el > nel) || (el < 0));

	persone[el].elimina();
	ftmp.open("filetmp.bin", ios::binary | ios::out);
	ftmp.write((char*)&persone, sizeof(persona)*(nel+1));
	ftmp.close();
	remove("file.bin");
	rename("filetmp.bin", "file.bin");

	return;
}

void cancellopersempre(persona persone[], fstream &f, fstream &ftmp, int &nel) {
	int el;

	cout << "Quale vuoi cancellare per sempre? " << endl;
	do {
		cout << "==> ";
		cin >> el;
	} while ((el > nel) || (el < 0));

	ftmp.open("filetmp.bin", ios::binary | ios::out);

	persone[el].setNome('');
	nel--;
	for(int i = 0; i <= nel; i++) {
		if (persone[i].getNome() != '') {
			ftmp.write((char*)&persone[i], sizeof(persona));
		}
	}

	ftmp.close();
	remove("file.bin");
	rename("filetmp.bin", "file.bin");
	leggo(persone, f, nel);

}

void stampa(persona persone[], int nel) {
	cout << "Stampa" << endl;
	for (int i = 0; i <= nel; i++) {
		cout << "Indice: " << i << endl;
		cout << "Nome: " << persone[i].getNome() << endl;
		cout << "Cognome: " << persone[i].getCognome() << endl;
		cout << "Eta: " << persone[i].getEta() << endl;
		cout << endl;
	}
	return;
}

void creafile(persona persone[], fstream &f) {
	char caux[20];
	int iaux;
	cout << "Creazione nuovo file" << endl;
	f.open("file.bin", ios::binary | ios::out);

	cout << "Inserisci nome: ";
	cin >> caux;
	persone[0].setNome(caux);
	cout << "Inserisci cognome: ";
	cin >> caux;
	persone[0].setCognome(caux);
	cout << "Inserisci eta: ";
	cin >> iaux;
	persone[0].setEta(iaux);

	f.write((char*)&persone, sizeof(persona));

	f.close();

	return;
}

int main(int argc, char const *argv[]) {
	fstream f, ftmp;
	persona persone[DIM];
	int nel = 0;

	f.open("file.bin", ios::binary | ios::in);

	if (!f.is_open()) {
		f.close();
		creafile(persone, f);
		exit(1);
	}
	f.close();

	leggo(persone, f, nel);
	stampa(persone, nel);


	return 0;
}
