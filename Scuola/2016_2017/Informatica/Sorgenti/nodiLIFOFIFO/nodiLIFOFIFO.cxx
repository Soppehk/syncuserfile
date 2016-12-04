#include <iostream>
using namespace std;

struct nodo {
	int dato;
	nodo *next;
};

class lista {
	nodo *head;
	nodo *tail;
	int nel;
	char strategia;
public:
	lista();
	lista(char);
	~lista();
	void push(int);
	int pop();
	int top();
	bool empty();
	void stampa();
	void insOrd(int);
	bool pres(int);
	int pos(int);
	int quanti(int);
};

lista::lista() {
	head = NULL;
	tail = NULL;
	nel = 0;
}

lista::lista(char c) {
	head = NULL;
	tail = NULL;
	nel = 0;
	strategia = c;
}

lista::~lista() {
	while (!empty()) {
		pop();
	}
}

void lista::push(int p) {
	nodo *aux;
	aux = new nodo;
	aux->dato = p;
	aux->next = NULL;

	if (strategia == 'L') {
		aux->next = head;
		head = aux;
	}
	if (strategia == 'F') {
		if (tail == NULL) {
			tail = aux;
		} else {
			tail->next = aux;
			tail = aux;
		}
	}
	if (strategia == 'O') {
		insOrd(p);
	}
	if (nel == 0) {
		if (strategia == 'L') {
			tail = head;
		}
		if (strategia == 'F') {
			head = tail;
		}
	}

	nel++;
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

void lista::insOrd(int p){
	nodo *aux, *prec, *succ;

	aux = new nodo;
	// se voglio controllare if(aux!=NULL)

	aux->dato = p;
	aux->next = NULL;
	if(head == NULL || head->dato > p){
		aux->next = head;
		head = aux;
	}
	else{
		prec = head;
		succ = head->next;
		while (succ != NULL && succ->dato < aux->dato){
			prec = prec->next;
			succ = succ->next;
		}
		prec->next = aux;
		aux->next = succ;
	}
	return;
}

bool lista::pres(int i) {
	nodo *aux;
	aux = head;
	while (aux != NULL) {
		if (aux->dato == i) {
			return true;
		}
		aux = aux->next;
	}

	return false;
}

int lista::quanti(int i) {
	int n = 0;
	nodo *aux;
	aux = head;
	while (aux != NULL) {
		if (aux->dato == i) {
			n++;
		}
		aux = aux->next;
	}

	return n;
}

int lista::pos(int i) {
	int n = 0;
	nodo *aux;
	aux = head;
	while (aux != NULL) {
		if (aux->dato == i) {
			return n;
		}
		aux = aux->next;
		n++;
	}

	return -1;
}

int main() {
	//strategie F = FIFO, L = LIFO, O = Lista ordinata
	int scelta;
	char c;

	cout << "Scegli strategia:" << endl;
	cout << "1)FIFO" << endl;
	cout << "2)LIFO" << endl;
	cout << "3)Lista ordinata" << endl;
	do {
		cout << "==> ";
		cin >> scelta;
	} while ((scelta < 1) || (scelta > 3));

	if (scelta == 1) {
		c = 'F';
	}
	if (scelta == 2) {
		c = 'L';
	}
	if (scelta == 3) {
		c = 'O';
	}

	lista l(c);
	do {
		cout << "1) PUSH" << endl;
		cout << "2) TOP" << endl;
		cout << "3) POP" << endl;
		cout << "4) STAMPA ELEMENTI" << endl;
		cout << "5) PRESENTE" << endl;
		cout << "6) QUANTI" << endl;
		cout << "7) POSIZIONE" << endl;
		cout << "8) ESCI" << endl;
		do {
			cout << "==> ";
			cin >> scelta;
		} while ((scelta < 1) || (scelta > 8));

		switch (scelta) {
			case 1: cout << "Inserisci numero: ";
					cin >> scelta;
					l.push(scelta);
					break;
			case 2: cout << "TOP: " << l.top() << endl;
					break;
			case 3:	cout << "POP: " << l.pop() << endl;
					break;
			case 4: l.stampa();
					break;
			case 5: cout << "Inserisci numero: ";
					cin >> scelta;
					if (l.pres(scelta)) {
						cout << "E' presente!" << endl;
					} else {
						cout << "Non e' presente!" << endl;
					}
					break;
			case 6: cout << "Inserisci numero: ";
					cin >> scelta;
					cout << "Elemento presente " << l.quanti(scelta) << " volte" << endl;
					break;
			case 7: cout << "Inserisci numero: ";
					cin >> scelta;
					cout << "Elemento presente in posizione " << l.pos(scelta) << endl;;
					break;
			case 8: cout << "Uscita dal programma";
		}
	} while (scelta != 8);


	return 0;
}
