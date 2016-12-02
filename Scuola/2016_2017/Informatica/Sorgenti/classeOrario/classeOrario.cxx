#include <iostream>
using namespace std;

class Orario {
	int ora;
	int minuto;
	int secondo;
	bool ctrlMaggZero(int);
	int orarioToSec();
	void secToOrario(int);
public:
	Orario();
	Orario(int, int, int);
	void setOra(int);
	void setMinuto(int);
	void setSecondo(int);
	int getOra();
	int getMinuto();
	int getSecondo();
	friend ostream& operator <<(ostream&, Orario);
	friend Orario operator +(Orario, Orario);
	friend Orario operator -(Orario, Orario);
	friend Orario operator *(Orario, int);
	friend Orario operator /(Orario, int);
	friend bool operator <(Orario, Orario);
};

bool Orario::ctrlMaggZero(int i) {
	if (i >= 0) {
		return true;
	} else {
		cout << "Numero negativo!!!" << endl;
		return false;
	}
}

int Orario::orarioToSec() {
	int sec = 0;
	sec += secondo;
	sec += minuto * 60;
	sec += ora * 3600;
	return sec;
}

void Orario::secToOrario(int n) {
	int aux=24*3600;
	if (n>=0){
		ora=(n/3600)%24;
		n=n%3600;
		minuto=n/60;
		secondo=n%60;
    }
    else{
    	aux=aux+n;
    	ora=(aux/3600)%24;
		aux=aux%3600;
		minuto=aux/60;
		secondo=aux%60;
	}
	return;
}


Orario::Orario() {
	ora = 0;
	minuto = 0;
	secondo = 0;
}

Orario::Orario(int o, int m, int s) {
	if (ctrlMaggZero(o)) {
		ora = o;
	} else {
		ora = 0;
	}

	if (ctrlMaggZero(m)) {
		minuto = m;
	} else {
		minuto = 0;
	}

	if (ctrlMaggZero(s)) {
		secondo = s;
	} else {
		secondo = 0;
	}
	secToOrario(orarioToSec());
}

void Orario::setOra(int i) {
	if (ctrlMaggZero(i)) {
		ora = i;
	} else {
		ora = 0;
	}
	secToOrario(orarioToSec());
}

void Orario::setMinuto(int i) {
	if (ctrlMaggZero(i)) {
		minuto = i;
	} else {
		minuto = 0;
	}
	secToOrario(orarioToSec());
}

void Orario::setSecondo(int i) {
	if (ctrlMaggZero(i)) {
		secondo = i;
	} else {
		secondo = 0;
	}
	secToOrario(orarioToSec());
}

int Orario::getOra() {
	return ora;
}

int Orario::getMinuto() {
	return minuto;
}

int Orario::getSecondo() {
	return secondo;
}

ostream& operator <<(ostream& out, Orario o) {
	out << o.ora << " : " << o.minuto << " : " << o.secondo << endl;
	return out;
}

Orario operator +(Orario o1, Orario o2) {
	Orario o;
	int temp;
	temp = o1.orarioToSec() + o2.orarioToSec();
	o.secToOrario(temp);

	return o;
}

Orario operator -(Orario o1, Orario o2) {
	Orario o;
	int temp;
	temp = o1.orarioToSec() - o2.orarioToSec();
	o.secToOrario(temp);

	return o;
}

Orario operator *(Orario o, int i) {
	Orario oprod;
	int temp;
	temp = o.orarioToSec() * i;
	oprod.secToOrario(temp);

	return oprod;
}

Orario operator /(Orario o, int i) {
	Orario oquoz;
	int temp;
	temp = o.orarioToSec() / i;
	oquoz.secToOrario(temp);

	return oquoz;
}

bool operator <(Orario o1, Orario o2) {
	bool ctrl;

	if(o1.ora < o2.ora ) {
		ctrl=true;
	} else {
		if (o1.ora > o2.ora ) {
			ctrl=false;
		} else { //stessa ora
			if (o1.minuto < o2.minuto) {
				ctrl=true;
			} else {
				if (o1.minuto > o2.minuto) {
					ctrl = false;
				} else { //stesso minuto
					if (o1.secondo < o2.secondo) {
						ctrl=true;
					} else {
						ctrl=false;
					}
				}
			}
		}
	}

	return ctrl;
}

int main() {
	Orario o1(23,98,28);
	Orario o2(45,46,127);
	Orario o3;

	cout << o1;
	cout << o2;
	o3 = o1 + o2;
	cout << o3;
	o3 = o1 - o2;
	cout << o3;
	o3 = o1 * 3;
	cout << o3;
	o3 = o1 / 3;
	cout << o3;
	cout << (o2 < o1) << endl;

	return 0;
}
