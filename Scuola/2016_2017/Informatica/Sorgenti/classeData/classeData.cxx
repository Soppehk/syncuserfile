#include <iostream>
using namespace std;

class Data {
	int giorno;
	int mese;
	int anno;
	bool ctrlMaggZero(int);
	string tradMese(int);
	int numGiorniMese();
	int numGiorniAnno();
public:
	int dataToGiorni();
	void giorniToData(int);

	Data();
	Data(int, int, int);
	int getGiorno();
	int getMese();
	int getAnno();
	void setGiorno(int);
	void setMese(int);
	void setAnno(int);
	friend ostream& operator <<(ostream&, Data);
	friend Data operator +(Data, Data);
	friend Data operator -(Data, Data);
};

bool Data::ctrlMaggZero(int i) {
	if (i >= 0) {
		return true;
	} else {
		cout << "Numero negativo!!!" << endl;
		return false;
	}
}

string Data::tradMese(int i) {
	switch (i) {
		case 1: return "Gennaio";
		case 2: return "Febbraio";
		case 3: return "Marzo";
		case 4: return "Aprile";
		case 5: return "Maggio";
		case 6: return "Giugno";
		case 7: return "Luglio";
		case 8: return "Agosto";
		case 9: return "Settembre";
		case 10: return "Ottobre";
		case 11: return "Novembre";
		case 12: return "Dicembre";
	}
	return "";
}

int Data::numGiorniMese() {
	if ((mese == 1) || (mese == 3) || (mese == 5) || (mese == 7) || (mese == 8) || (mese == 10) || (mese == 12)) {
		return 31;
	}
	if ((mese == 4) || (mese == 6) || (mese == 9) || (mese == 11)) {
		return 30;
	}
	if (mese == 2) {
		if (anno % 4 == 0) {
			return 29;
		} else {
			return 28;
		}
	}
	return 0;
}

int Data::numGiorniAnno() {
	if (anno % 4 == 0) {
		return 366;
	} else {
		return 365;
	}
}

Data::Data() {
	giorno = 1;
	mese = 1;
	anno = 0;
}

Data::Data(int g, int m, int a) {
	setAnno(a);
	setMese(m);
	setGiorno(g);
}

int Data::getGiorno() {
	return giorno;
}

int Data::getMese() {
	return mese;
}

int Data::getAnno() {
	return anno;
}

void Data::setGiorno(int g) {
	if ((ctrlMaggZero(g)) && (g <= numGiorniMese())) {
		giorno = g;
	} else {
		cout << "Giorno inserito non correttamente!!!" << endl;
		giorno = 1;
	}
}

void Data::setMese(int m) {
	if ((ctrlMaggZero(m)) && (m <= 12)) {
		mese = m;
	} else {
		cout << "Mese inserito non correttamente!!!" << endl;
		mese = 1;
	}
}

void Data::setAnno(int a) {
	if (ctrlMaggZero(a)) {
		anno = a;
	} else {
		cout << "Anno inserito non correttamente!!!" << endl;
		anno = 0;
	}
}

int Data::dataToGiorni() {
	Data d;
	int ng;
	ng = giorno;

	for (int i = 1; i < mese; i++) {
		ng += d.numGiorniMese();
		d.mese++;
	}

	for (d.anno = 0; d.anno < anno; d.anno++) {
		ng += d.numGiorniAnno();
	}

	return ng;
}

void Data::giorniToData(int i) {
	anno = 0;
	mese = 1;

	while (i > numGiorniAnno()) {
		i -= numGiorniAnno();
		anno++;
	}

	while (i > numGiorniMese()) {
		i -= numGiorniMese();
		mese++;
	}

	giorno = i;

	if (anno % 4 != 0) {
		giorno--;
	}

}

ostream& operator <<(ostream& out, Data d) {
	out << d.giorno << " / " << d.mese << " / " << d.anno << endl;
	return out;
}

Data operator +(Data d1, Data d2) {
	Data d;
	d.giorniToData(d1.dataToGiorni() + d2.dataToGiorni());
	return d;
}

Data operator -(Data d1, Data d2) {
	Data d;

	if (d1.dataToGiorni() >= d2.dataToGiorni()) {
	 	d.giorniToData(d1.dataToGiorni() - d2.dataToGiorni());
		return d;
	} else {
		d.giorniToData(d2.dataToGiorni() - d1.dataToGiorni());
		return d;
	}
}

int main() {
	Data d1(25, 8, 1966);
	Data d2(1, 1 , 0);
	Data d3;

	cout << d1;
	cout << d2;
	d3 = d1 + d2;
	cout << d3;
	d3 = d2 - d1;
	cout << d3;

	return 0;
}
