#include <iostream>
using namespace std;

class nodo {
	int dato;
	nodo *next;
public:
	nodo();
	int getDato();
	void setDato(int);
	nodo *getNext();
	void setNext(nodo*);
};

nodo::nodo() {
	next = NULL;
}

int nodo::getDato() {
	return dato;
}

void nodo::setDato(int i) {
	dato = i;
}

nodo *nodo::getNext() {
	return next;
}

void nodo::setNext(nodo *n) {
	next = n;
}

class lista {
	nodo *head;
	nodo *tail;
	char paramentro;
public:
	lista();
	lista(char);
	~lista();
	void push(int);
	int pop();
	int top();
	void insOrd(int);
	friend void insOrdRic(nodo*, nodo*&);
	int tot();
	void stampa();

	friend lista operator +(lista, lista);
	friend lista operator -(lista, lista);
	friend void operator *(lista, int);
	friend void operator /(lista, int);
	friend bool operator <(lista, lista);
	friend bool operator <=(lista, lista);
	friend bool operator >(lista,lista);
	friend bool operator >=(lista, lista);
	friend ostream operator <<(ostream, lista);
};

lista::lista() {
	head = NULL;
	tail = NULL;
}


lista::lista(char c) {
	head = NULL;
	tail = NULL;
	paramentro = c;
}

lista::~lista() {
	while(head != NULL) {
		pop();
	}
}

void lista::push(int i) {
	nodo *aux;
	aux = new nodo;
	aux->setDato(i);

	if (paramentro == 'L') {
		aux->setNext(head);
		head->setNext(aux);
	}
	if (paramentro == 'F') {
		if (tail == NULL) {
			tail = aux;
		} else {
			tail->setNext(aux);
			tail = aux;
		}
	}
	// if (paramentro == 'O') {
	// 	insOrd(i);
	// }
	if ((head == NULL) || (tail == NULL)) {
		if (paramentro == 'L') {
			tail = head;
		}
		if (paramentro == 'F') {
			head = tail;
		}
	}
}

int lista::pop() {
	nodo *aux;
	int info = 0;

	if ((head != NULL)) {
		info = head->getDato();
		aux = head;
		head = head->getNext();
		delete(aux);
	} else {
		cout << "Lista vuota" << endl;
	}

	return info;
}

int lista::top() {
	if (head != NULL) {
		return head->getDato();
	} else {
		cout << "Lista vuota" << endl;
	}

	return 0;
}

// void lista::insOrd(int i) {
// 	nodo *aux;
// 	aux = new nodo;
// 	aux->setDato(i);
// 	insOrdRic(aux, head);
// }
//
// void insOrdRic(nodo *aux, nodo *&h) {
// 	if (h == NULL) {
// 		h = aux;
// 	} else {
// 		if (aux->dato > h->dato) {
// 			aux->next = h;
// 			h = aux;
// 		} else {
// 			insOrdRic(aux, h->next);
// 		}
// 	}
// 	return;
// }

void lista::stampa() {
	nodo *aux;
	aux = head;
	if (head == NULL) {
		cout << "Lista vuota" << endl;
	}
}

lista operator +(lista l1, lista l2) {
	lista l;
	nodo *aux1, *aux2;
	aux1 = l1.head;
	aux2 = l2.head;

	while(aux1!=NULL){
	  l.push(aux1->getDato());
	  aux1 = aux1->getNext();
	}

	while(aux2!=NULL){
	  l.push(aux2->getDato());
	  aux2 = aux2->getNext();
	}
	return l;
}

int main(int argc, char const *argv[]) {
	lista l1('L'), l2('L');

	l1.push(5);
	l1.push(6);
	l2.push(7);
	l2.push(8);

	lista l3;
	l3 = l1 + l2;


	return 0;
}
