#include <iostream>
#define DIM 10
using namespace std;

class Vettore {
	int v[DIM];
	int nel;
public:
	Vettore();
	int aggEl(int);
	int insEl(int, int);
	void azzEl();
	int ricEl(int);
	friend ostream& operator <<(ostream &out, Vettore);
	void ordEl(bool);
	friend Vettore operator +(Vettore, Vettore);
};

Vettore::Vettore() {
	nel = 0;
}

int Vettore::aggEl(int i) {
	if (nel == DIM) {
		return -1;
	} else {
		v[nel] = i;
		nel++;
		return nel -1;
	}
}

int Vettore::insEl(int i, int pos) {
	if (pos >= nel) {
		return -1;
	} else {
		v[pos] = i;
		return pos;
	}
}

void Vettore::azzEl() {
	nel = 0;
}

int Vettore::ricEl(int el) {
	for (int i = 0; i < nel; i++) {
		if (v[i] == el) {
			return i;
		}
	}

	return -1;
}

ostream& operator <<(ostream &out, Vettore a) {
	for (int i = 0; i < a.nel; i++) {
		out << a.v[i];
	}

	return out;
}

void Vettore::ordEl(bool cresc) {
	int aux;
	for (int i = 0; i < nel; i++) {
		for (int j = nel-1; j >= i; j--) {
			if (cresc) {
				if (v[i] > v[i+1]) {
					aux = v[i];
					v[i] = v[i+1];
					v[i+1] = aux;
				}
			} else {
				if (v[i] < v[i+1]) {
					aux = v[i];
					v[i] = v[i+1];
					v[i+1] = aux;
				}
			}
		}
	}
}


Vettore operator +(Vettore a, Vettore b) {
	Vettore c;

}

Vettore operator -(Vettore a, Vettore b) {
	Vettore c;
	bool ctrl = false;

	for (int i = 0; i < a.nel; i++) {
		for (int j = 0; j < b.nel; j++) {
			if (a.v[i] == b.v[j]) {
				ctrl = false;
			}
		}
	}
}
