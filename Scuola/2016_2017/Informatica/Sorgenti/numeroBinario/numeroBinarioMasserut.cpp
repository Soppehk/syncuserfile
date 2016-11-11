#include <iostream>
#include <cstring>
#include <math.h>
#define DIM 10
using namespace std;

class binario {
	int v[DIM];
	int ne;
public:
	binario();
	binario(char*);
	int getV(int); //passo un indice
	void setV(int, int);
	void azzera();
	int binToDec();
	void decToBin(int);
	friend binario somma(binario, binario);
	friend binario operator +(binario, binario);
	friend ostream& operator <<(ostream&, binario);
};

binario::binario() {
	ne = 0;
	for (int i = 0; i < DIM; i++) {
		v[i] = 0;
		ne++;
	}
}

binario::binario(char *c) {
	ne = 0;
	if (strlen(c) > DIM) {
		cout << "STRINGA INSERITA MAGGIORE DI " << DIM << " !!!" <<endl;
	} else {
		for (int i = 0; i < strlen(c);i++) {
			if ((c[i] == '0') || (c[i] == '1')) {
				v[i] = (int)c[i]-'0';
				ne++;
			} else {
				cout << c[i] << ": Presente un carattere diverso da 0 o da 1 !!!" << endl;
			}
		}
	}
}

int binario::getV(int i) {
	if (i < ne) {
		return v[i];
	} else {
		cout << "Indice maggiore degli elementi presenti" << endl;
		return -1;
	}
}

void binario::setV(int valore, int indice) {
	if (indice < DIM) {
		if (indice <= ne) {
			if ((valore == 0) || (valore == 1)) {
				v[indice] = valore;
				if (indice == ne) {
					ne++;
				}
			} else {
				cout << valore << ": Carattere diverso da 0 o da 1 !!!" << endl;
			}
		} else {
			cout << "Cella del vettore non contigua!!!" << endl;
		}
	} else {
		cout << "Indice maggiore della dimensione del vettore!!!" << endl;
	}
}

void binario::azzera() {
	ne = 0;
	for (int i = 0; i < DIM; i++) {
		v[i] = 0;
		ne++;
	}
}

int binario::binToDec() {
	int d = 0;

	for (int i = this->ne - 1; i >= 0; i--) {
		d = d + pow(2, i) * this->getV(this->ne - 1 - i);
	}

	return d;
}

void binario::decToBin(int i) {
	ne = 0;
	int copia = i, nbin = 0;;

	while (copia >= 1) {
		copia = copia / 2;
		nbin++;
	}

	while (i >= 1) {
		v[nbin] = i % 2;
		nbin --;
		i = i / 2;
		ne++;
	}
	ne++;

	return;
}

ostream& operator << (ostream &out, binario b) {
	for (int i = 0; i < b.ne; i++) {
		out << b.v[i];
	}
	out << endl;
	return out;
}

binario somma(binario b1, binario b2) {
	int i1 = b1.binToDec();
	int i2 = b2.binToDec();
	int somma = i1 + i2;
	binario b;
	b.decToBin(somma);

	return b;
}

binario operator +(binario b1, binario b2) {
	int i1 = b1.binToDec();
	int i2 = b2.binToDec();
	int somma = i1 + i2;
	binario b;
	b.decToBin(somma);

	return b;
}

int main() {
	binario b1;
	binario b2("0101101");
	binario b3;
	binario b4;
	binario b5;

	b1.azzera();
	cout << b1;
	cout << b2;

	cout << b2.getV(6) << endl;
	b1.setV(1, 1);
	cout << b1;
	b2.setV(1, 7);
	cout << b2;
	cout << b2.binToDec() << endl;
	b3.decToBin(53);
	cout << b3;

	b4 = somma(b2,b3);
	cout << b4;
	b5 = b2 + b3;
	cout << b5;

	return 0;
}
