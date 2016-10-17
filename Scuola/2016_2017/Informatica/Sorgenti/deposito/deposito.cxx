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


void ControlloFile(fstream &file, const char *nomefile) {

	file.open(nomefile, ios::in);
	if(file.fail()) {
		cout << "Il file " << nomefile << " non esiste!" << endl;
		cout << "ERRORE" << endl;
		file.close();
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

	getline(f, riga);
	istringstream iss(riga);
	iss >> saux;
	d[nl].setNomeCitta(saux);
	iss >> iaux;
	d[nl].setNumMax(iaux);
	iss >> iaux;
	d[nl].setNum(iaux);
	if(d[nl].getNum() > d[nl].getNumMax()) {
		cout << "Superata capienza veicoli -> linea: " << nl + 1;
		f.close();
		exit(1);
	}

	return;
}

void LeggoFileIniziale(deposito d[], fstream &f, int &nl) {
	ControlloIncongruenzeFileIniziale(d, f, nl);
	while (!f.eof()) {
		nl++;
		ControlloIncongruenzeFileIniziale(d, f, nl);
		if (ControlloCitta(d, d[nl].getNomeCitta(), nl) != -1) {
			cout << "Citta' gia' presente! -> linea: " << nl + 1;
			f.close();
			exit(1);
		}
	}

	return;
}

void ControlloIncongruenzeFileScambio(deposito d[], fstream &f, int nlp, int &nla) {
	string riga, nomecittaarrivo, nomecittapartenza;
	int numscambio, pospartenza, posarrivo;

	getline(f, riga);
	istringstream iss(riga);
	iss >> nomecittapartenza;
	if (ControlloCitta(d, nomecittapartenza, nlp) != -1) {
		pospartenza = ControlloCitta(d, nomecittapartenza, nlp);
		iss >> nomecittaarrivo;
		if ((ControlloCitta(d, nomecittaarrivo, nla) != -1) || (nomecittaarrivo != d[pospartenza].getNomeCitta())) {
			posarrivo = ControlloCitta(d, nomecittaarrivo, nla);
			iss >> numscambio;
			if ((numscambio + d[posarrivo].getNum() <= d[posarrivo].getNumMax()) && (numscambio <= d[pospartenza].getNum())) {
				d[pospartenza].setNum(d[pospartenza].getNum() - numscambio);
				d[posarrivo].setNum(d[posarrivo].getNum() + numscambio);
			}
		} else {
			cout << "Citta' non esistente o uguale! -> linea: " << nla + 1;
			f.close();
			exit(1);
		}
	} else {
		cout << ControlloCitta(d, nomecittapartenza, nlp);
		cout << "Citta' non esistente! -> linea: " << nlp;
		f.close();
		exit(1);
	}

	return;
}

void LeggoFileScambio(deposito d[], fstream &f, int nlp, int &nla) {
	ControlloIncongruenzeFileScambio(d, f, nlp, nla);
	while (!f.eof()) {
		nla++;
		ControlloIncongruenzeFileScambio(d, f, nlp, nla);
	}

	return;
}

void Stampa(deposito d[], int nl) {
	cout << "Stampa situazione attuale" << endl;
	for (int i = 0; i < nl; i++) {
		cout << i + 1 << ") Citta': " << d[i].getNomeCitta() << " Numero massimo veicoli: " << d[i].getNumMax() << " Numero attuale veicoli: " << d[i].getNum() << endl;
	}

	return;
}

int main() {
	deposito depositi[DIM];
	string nomefileiniziale = "i.txt";
	string nomefilescambio = "s.txt";
	int numlinefileiniziale = 0;
	int numlinefilescambio = 0;
	fstream fileiniziale, filescambio;
	ControlloFile(fileiniziale, nomefileiniziale.c_str());

	LeggoFileIniziale(depositi, fileiniziale, numlinefileiniziale);
	Stampa(depositi, numlinefileiniziale);
	ControlloFile(filescambio, nomefilescambio.c_str());
	LeggoFileScambio(depositi, filescambio, numlinefileiniziale, numlinefilescambio);
	Stampa(depositi, numlinefileiniziale);


	fileiniziale.close();
	filescambio.close();

	return 0;
}
