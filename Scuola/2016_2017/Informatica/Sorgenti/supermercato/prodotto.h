#include <iostream>
#include <cstring>
using namespace std;

class prodotto {
	int cod;
	char descr[25];
	char unmis[5];
	int num;
	float prez;
	bool canc;
public:
	prodotto();
	void setCod(int);
	void setDescr(char *);
	void setUnMis(char *);
	void setNum(int);
	void setPrez(float);
	int getCod();
	char getDescr();
	char getUnMis();
	int getNum();
	void setCanc(bool);
	float getPrez();
	bool getCanc();
	void IncNum(int);
	void DecNum(int);
	void setCancFis();
	friend ostream& operator <<(ostream&, prodotto);
};

prodotto::prodotto() {
	canc = false;
}

void prodotto::setCod(int i) {
	cod = i;
}

void prodotto::setDescr(char *c) {
	strcpy(descr, c);
}

void prodotto::setUnMis(char *c) {
	strcpy(unmis, c);
}

void prodotto::setNum(int i) {
	num = i;
}

void prodotto::setPrez(float f) {
	prez = f;
}

void prodotto::setCanc(bool b) {
	canc = b;
}

void prodotto::setCancFis() {
	int scelta;
	if (!canc) {
		cout << "Il file non e' stato cancellato logicamente!" << endl;
		cout << "Vuoi cancellarlo logicamente e riprovare? 1) SI' 2) NO" << endl;
		do {
			cout << "==> ";
			cin >> scelta;
		} while((scelta < 1) || (scelta > 2));

		switch (scelta) {
			case 1: canc = true;
					setCancFis();
					break;
			case 2: cout << "Nessuna operazione effettuata" << endl;
		}
	} else {
		cod = -1;
		cout << "Cancellato" << endl;
	}
}

int prodotto::getCod() {
	return cod;
}

char prodotto::getDescr() {
	return *descr;
}

char prodotto::getUnMis() {
	return *unmis;
}

int prodotto::getNum() {
	return num;
}

float prodotto::getPrez() {
	return prez;
}

bool prodotto::getCanc() {
	return canc;
}

void prodotto::IncNum(int i) {
	num = num + i;
}

void prodotto::DecNum(int i) {
	if ((num - i) < 0) {
		cout << "Hai inserito un numero maggiore degli elementi presenti, numero elementi portato a 0" << endl;
		num = 0;
	} else {
		num = num - i;
	}

	if (num == 0) {
		cout << "Giacenze del prodotto pari a 0, prodotto eliminato logicamente" << endl;
		canc = true;
	}

	return;
}

ostream& operator <<(ostream &out, prodotto p) {
	out << "Codice prodotto: " << p.cod << endl << "Descrizione: " << p.descr << endl << "Unita' misura: " << p.unmis << endl << "Quantita': " << p.num  << endl << "Prezzo: " << p.prez << endl;
	return out;
}
