#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

#define DIM 10

class deposito {
	string nomecitta;
	int nummax;
	int num;

	public:
		string getNomeCitta();
		void setNomeCitta(string);
		int getNum();
		void setNum(int);
		int getNumMax();
		void setNumMax(int);
};

string deposito::getNomeCitta() {
	return nomecitta;
}

void deposito::setNomeCitta(string s) {
	nomecitta = s;
}

int deposito::getNum() {
	return num;
}

void deposito::setNum(int i) {
	num = i;
}

int deposito::getNumMax() {
	return nummax;
}

void  deposito::setNumMax(int i) {
	nummax = i;
}


void ControlloFile(fstream &f, const char *nomefile) {

	f.open(nomefile, ios::in);
	if(f.fail()) {
		cout << "Il file " << nomefile << " non esiste!" << endl;
		cout << "ERRORE" << endl;
		f.close();
		exit(1);
	} else {
		cout << "Il file " << nomefile << " e' valido" << endl;
	}

	return;
}

int ControlloCitta(deposito d[], string s, int nl) {
	int pos = -1;
	for (int i = 0; i < nl; i++) {
		if (d[i].getNomeCitta() == s) {
			pos = i;
		}
	}

	return pos;
}

void ControlloIncongruenzeFileIniziale(deposito d[], fstream &f, int nl) {
	string riga, saux;
	int iaux;

	f >> saux;
	d[nl].setNomeCitta(saux);
	f >> iaux;
	d[nl].setNumMax(iaux);
	f >> iaux;
	d[nl].setNum(iaux);
	if(d[nl].getNum() > d[nl].getNumMax()) {
		cout << "Superata capienza veicoli -> linea: " << nl + 1;
		f.close();
		exit(1);
	}
	if(d[nl].getNum() < 0) {
		cout << "Numero veicoli negativo! -> linea: " << nl + 1;
		f.close();
		exit(1);
	}

	return;
}

void LeggoFileIniziale(deposito d[], fstream &f, int &nlp) {
	ControlloIncongruenzeFileIniziale(d, f, nlp);
	while (!f.eof()) {
		nlp++;
		ControlloIncongruenzeFileIniziale(d, f, nlp);
		if (ControlloCitta(d, d[nlp].getNomeCitta(), nlp) != -1) {
			cout << "Citta' gia' presente! -> linea: " << nlp + 1;
			f.close();
			exit(1);
		}
	}
	f.close();

	return;
}

void ControlloIncongruenzeFileScambio(deposito d[], fstream &f, int nlp, int nla) {
	string riga, nomecittaarrivo, nomecittapartenza;
	int numscambio, pospartenza, posarrivo;

	f >> nomecittapartenza;
	f >> nomecittaarrivo;
	f >> numscambio;

	if (ControlloCitta(d, nomecittapartenza, nlp + 1) == -1) {
		cout<< "Citta' non esistente! -> linea: " <<nla + 1;
		f.close();
		exit(1);
	}

	pospartenza = ControlloCitta(d, nomecittapartenza, nlp + 1);


	if ((ControlloCitta(d, nomecittaarrivo, nlp + 1) == -1) || (nomecittaarrivo == nomecittapartenza)) {
		cout << "Citta' non esistente o uguale! -> linea: " << nla + 1;
		f.close();
		exit(1);
	}

	posarrivo = ControlloCitta(d, nomecittaarrivo, nlp + 1);

	if ((numscambio + d[posarrivo].getNum() > d[posarrivo].getNumMax()) || (numscambio > d[pospartenza].getNum())) {
		cout << "Errore numero veicoli! -> linea: " << nla + 1;
		f.close();
		exit(1);
	}

	d[posarrivo].setNum(d[posarrivo].getNum() + numscambio);
	d[pospartenza].setNum(d[pospartenza].getNum() - numscambio);

	return;
}

void LeggoFileScambio(deposito d[], fstream &f, int nlp, int &nla) {
	ControlloIncongruenzeFileScambio(d, f, nlp, nla);
	while (!f.eof()) {
		nla++;
		ControlloIncongruenzeFileScambio(d, f, nlp, nla);
	}
	f.close();

	return;
}

void Stampa(deposito d[], int nl) {
	cout << "Stampa situazione attuale" << endl;
	for (int i = 0; i <= nl; i++) {
		cout << i + 1 << ") Citta': " << d[i].getNomeCitta() << ", Numero massimo veicoli: " << d[i].getNumMax() << ", Numero attuale veicoli: " << d[i].getNum() << endl;
	}

	return;
}

void Riscrivi(deposito d[], fstream &f, const char * nomefile, int nl) {
	f.open(nomefile, ios::out);

	for (int i = 0; i <= nl; i++) {
		f << d[i].getNomeCitta() << " " << d[i].getNumMax() << " " << d[i].getNum() << endl;
	}

	f.close();

	return;
}

void Menu() {
	cout << "MENU" << endl;
	cout << "1) Stampare" << endl;
	cout << "2) Effettuare spostamenti" << endl;
	cout << "3) Riscrivere file iniziale" << endl;
	cout << "4) Esci" << endl;

	return;
}

int main() {
	deposito depositi[DIM];
	string nomefileiniziale;
	string nomefilescambio;
	int numlinefileiniziale = 0;
	int numlinefilescambio = 0;
	fstream fileiniziale, filescambio;
	int scelta;

	cout << "***GESTORE DEPOSITI***" << endl;
	cout << "Immettere nome file iniziale: ";
	cin >> nomefileiniziale;
	ControlloFile(fileiniziale, nomefileiniziale.c_str());
	LeggoFileIniziale(depositi, fileiniziale, numlinefileiniziale);

	do {
		Menu();
		cout << "Scegli:";
		do {
			cout << "==> ";
			cin >> scelta;
		} while (scelta <= 0 || scelta > 4);

		switch (scelta) {
			case 1: cout << "Stampa" << endl;
				Stampa(depositi, numlinefileiniziale);
				break;
			case 2: cout << "Spostamenti" << endl;
				cout << "Immettere nome file scambi: ";
				cin >> nomefilescambio;
				ControlloFile(filescambio, nomefilescambio.c_str());
				LeggoFileScambio(depositi, filescambio, numlinefileiniziale, numlinefilescambio);
				break;
			case 3: cout << "Riscrivo file iniziale" << endl;
				Riscrivi(depositi, fileiniziale, nomefileiniziale.c_str(), numlinefileiniziale );
				break;
			case 4: cout << "Uscita dal programma" <<endl;

		}
	} while(scelta != 4);

	return 0;
}
