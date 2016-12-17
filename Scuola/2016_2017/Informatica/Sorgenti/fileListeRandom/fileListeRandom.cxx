#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
using namespace std;

struct nodo {
	int dato;
	nodo *next;
};

class lista {
	nodo *head;
	int nel;
public:
	lista();
	~lista();
	int pop();
	bool eliminaPres(int);
	int top();
	bool empty();
	void stampa();
	void iO(nodo*, nodo*&);
	void insOrd(int);
	void elVicini();
};

lista::lista() {
	head = NULL;
	nel = 0;
}

lista::~lista() {
	while (!empty()) {
		pop();
	}
}

int lista::pop() {
	int info = 0;
	nodo *aux;

	if (nel != 0) {
		info = head->dato;
		aux = head;
		head = head->next;
		delete(aux);
	} else {
		cout << "Lista vuota!" << endl;
	}

	nel--;

	return info;
}

// void lista::insOrd(int d){
// 	nodo *aux, *prec, *succ;
//
// 	aux = new nodo;
// 	// se voglio controllare if(aux!=NULL)
//
// 	aux->dato = d;
// 	aux->next = NULL;
// 	if(head == NULL || head->dato > d){
// 		aux->next = head;
// 		head = aux;
// 	}
// 	else{
// 		prec = head;
// 		succ = head->next;
// 		while (succ != NULL && succ->dato < aux->dato){
// 			prec = prec->next;
// 			succ = succ->next;
// 		}
// 		prec->next = aux;
// 		aux->next = succ;
// 	}
// 	return;
// }

void lista::iO(nodo *aux, nodo *&h) {

	if (h == NULL) {
		h = aux;
	} else {
		if (h->dato > aux->dato) {
			aux->next = h;
			h = aux;
		} else {
			iO(aux, h->next);
		}
	}
	return;
}

void lista::insOrd(int d) {
	nodo *aux;
	aux = new nodo;
	aux->dato = d;
	aux->next = NULL;
	iO(aux, head);
}

bool lista::eliminaPres(int i) {
	nodo *aux, *auxhead, *prec;
	bool b = false;

	while ((head != NULL) && (head->dato == i)) {
		auxhead = head;
		head = head->next;
		aux = head;
		delete(auxhead);
		b = true;
	}
	if (head != NULL) {
		prec = head;
		aux = head->next;
	}

	return b;
}

int lista::top() {
	if (nel != 0) {
		return head->dato;
	} else {
		cout << "Lista vuota!" << endl;
	}

	return 0;
}

bool lista::empty() {
	return (head == NULL);
}

void lista::stampa() {
	nodo *aux;
	aux = head;
	if (this->empty()) {
		cout << "Lista vuota!" << endl;
	}
	while (aux != NULL) {
		cout << aux->dato << endl;
		aux = aux->next;
	}
}

void lista::elVicini() {
	nodo *aux;
	if (head == NULL) {
		return;
	}

}

void menu() {
	cout << "1)Crea nuovo file numeri.txt" << endl;
	cout << "2)Leggi e stampa il file numeri.txt" << endl;
	cout << "3)Leggi il file numeri.txt, crea pari.txt e dispari.txt" << endl;
	cout << "4)Stampa pari" << endl;
	cout << "5)Stampa dispari" << endl;
	cout << "6)Esci" << endl;
}

void genNumRandom(fstream &f) {
	int i;
	int aux;
	srand(time(NULL));
	do {
		i = 0;
		while (i < 10) {
			aux = rand() % 100 + 1;
			f << aux << endl;
			i++;
		}
		cout << "Hai inserito 10 numeri, ne vuoi inserire altretanti { 1)Si' 0)No }? ";
		cin >> i;
 	} while (i != 0);
}

void stampaNumeri(fstream &f) {
	int aux;
	if (f.is_open()) {
		f >> aux;
		cout << aux << endl;
		while (!f.eof()) {
			f >> aux;
			cout << aux << endl;
		}
	} else {
		cout << "Il file non esiste!" << endl;
	}
}

void creaPariDispari() {
	fstream n, p, d;
	lista l;
	int aux;

	n.open("numeri.txt", ios::in);
	if (n.is_open()) {
		n >> aux;
		l.insOrd(aux);
		while (!n.eof()) {
			n >> aux;
			l.insOrd(aux);
		}
		p.open("pari.txt", ios::out);
		d.open("dispari.txt", ios::out);
		l.pop();
		while (!l.empty()) {
			aux = l.pop();
			if (aux % 2 == 0) {
				p << aux << endl;
			} else {
				d << aux << endl;
			}
		}
		p.close();
		d.close();
	} else {
		cout << "file non esiste" << endl;
	}
	n.close();

	return;
}

int main() {
	fstream f;
	int scelta = 0;

	do {
		menu();
		do {
			cout << "==> ";
			cin >> scelta;
		} while ((scelta < 1) || (scelta > 6));

		switch(scelta) {
			case 1:
				cout << "Creo nuovo file numeri.txt" << endl;
				f.open("numeri.txt", ios::out);
				genNumRandom(f);
				f.close();
				break;
			case 2:
				cout << "Leggo e stampo il file numeri.txt" << endl;
				f.open("numeri.txt", ios::in);
				stampaNumeri(f);
				f.close();
				break;
			case 3:
				cout << "Leggo il file numeri.txt e creo pari.txt e dispari.txt" << endl;
				creaPariDispari();
				break;
			case 4:
				cout << "Leggo e stampo il file pari.txt" << endl;
				f.open("pari.txt", ios::in);
				stampaNumeri(f);
				f.close();
				break;
			case 5:
				cout << "Leggo e stampo il file dispari.txt" << endl;
				f.open("dispari.txt", ios::in);
				stampaNumeri(f);
				f.close();
				break;
		}

	} while (scelta != 6);


	return 0;
}
