#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

struct Nodo {
	int prezzo;
	char codice[5];
	Nodo *next;
};

class Lista {
	Nodo *head;
	int nel;
	int totprezzi;
public:
	Lista();
	~Lista();
	void push(int, char[5]);
	void pop();
	bool empty();
	Nodo *getHead();
	int getNel();
	int getTotPrezzi();
	void insOrd(int, char[5]);
	void insOrdRic(Nodo*, Nodo*&);
	void stampa();
	friend void operator *(Lista, const int);
};

Lista::Lista() {
	head = NULL;
	nel = 0;
	totprezzi = 0;
}

Lista::~Lista() {
	while (!empty()) {
		pop();
	}
}

void Lista::push(int i, char c[5]) {
	Nodo *aux;
	aux = new Nodo;
	aux->prezzo = i;
	strcpy(aux->codice, c);
	aux->next = head;
	head = aux;
}

void Lista::pop() {
	Nodo *aux;
	aux = head;
	head = head->next;
	delete(aux);
}

bool Lista::empty() {
	return (head == NULL);
}

Nodo *Lista::getHead() {
	return head;
}

int Lista::getNel() {
	return nel;
}

int Lista::getTotPrezzi() {
	return totprezzi;
}

void Lista::insOrd(int i, char c[5]) {
	Nodo *aux;
	aux = new Nodo;
	aux->prezzo = i;
	totprezzi = totprezzi + i;
	nel++;
	strcpy(aux->codice, c);
	insOrdRic(aux, head);
}

void Lista::insOrdRic(Nodo *aux, Nodo *&h) {
	if (h == NULL) {
		h = aux;
	} else {
		if (strcmp(aux->codice, h->codice) > 0) {
			aux->next = h;
			h = aux;
		} else {
			insOrdRic(aux, h->next);
		}
	}
}

void Lista::stampa() {
	Nodo *aux;
	aux = head;
	while (aux != NULL) {
		cout << aux->codice << endl << aux->prezzo << endl;
		aux = aux->next;
	}
}

void operator *(Lista l, const int i) {
	Nodo *aux;
	aux = l.head;
	while(aux != NULL) {
		aux->prezzo = aux->prezzo * i;
		aux = aux->next;
	}
}

int main() {
	Lista l;
	fstream p, s;
	float media;
	int scelta, iaux;
	char caux[5];

	p.open("primo.dat", ios::out);
	do {
		cout << "Inserisci codice: ";
		cin.getline(caux, 4);
		p << caux << endl;
		cout << "Inserisci prezzo: ";
		cin >> iaux;
		p << iaux << endl;
		cout << "Vuoi inserire altri elementi? 0)Si 1)No: ";
		cin >> scelta;
		cin.ignore();
	} while (scelta != 1);
	p.close();

	p.open("primo.dat", ios::in);
	s.open("secondo.dat", ios::out);
	p >> caux;
	p >> iaux;
	l.insOrd(iaux, caux);
	while (!p.eof()) {
		p >> caux;
		p >> iaux;
		l.insOrd(iaux, caux);
	}
	media = l.getTotPrezzi() / l.getNel();

	Nodo *aux;
	aux = l.getHead();
	while(aux != NULL) {
		if (aux->prezzo >= media) {
			s << aux->codice << endl;
			s << aux->prezzo << endl;
		}
		aux = aux->next;
	}

	cout << "Stampa di l:" << endl;
	l.stampa();
	const int i = 5;
	l*i;
	l.stampa();

	return 0;
}
