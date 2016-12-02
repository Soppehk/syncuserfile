#include <iostream>
using namespace std;

struct persona {
	char cognome[20];
	char nome[20];
	char indirizzo[50];
};

struct nodo {
	persona dato;
	nodo *next;
};

class stack {
	nodo *head;
public:
	stack();
	~stack();
	void push(persona);
	persona pop();
	persona top();
	bool empty();
	void stampa();
};

stack::stack() {
	head = NULL;
}

stack::~stack() {
	persona p;
	
	while (!empty()) {
		p = pop();
	}
}

void stack::push(persona p) {
	nodo *aux;
	aux = new nodo;
	aux->dato = p;
	aux->next = head;
	head = aux;
}

persona stack::pop() {
	persona info;
	nodo *aux;
	
	info = head->dato;
	aux = head;
	head = head->next;
	delete(aux);
	return info;
}

persona stack::top() {
	
	return head->dato;
}

bool stack::empty() {
	return (head == NULL);
}

void stack::stampa() {
	nodo *aux;
	aux = head;
	if (this->empty()) {
		cout << "PILA VUOTA" << endl;
	}
	while (aux != NULL) {
		cout << "Cognome: " << aux->dato.cognome << endl;
		cout << "Nome: " << aux->dato.nome << endl;
		cout << "Indirizzo: " << aux->dato.indirizzo << endl;
		aux = aux->next;
	}
}

int main() {
	stack s;
	persona p;
	int scelta;
	
	do {
		cout << "1) PUSH" << endl;
		cout << "2) TOP" << endl;
		cout << "3) POP" << endl;
		cout << "4) STAMPA ELEMENTI" << endl;
		cout << "5) ESCI" << endl;
		do {
			cout << "==> ";
			cin >> scelta;			
		} while ((scelta < 1) || (scelta > 5));
		
		switch (scelta) {
			case 1: cout << "Inserisci cognome: ";
					cin >> p.cognome;
					cout << "Inserisci nome: ";
					cin >> p.nome;
					cout << "Inserisci indirizzo: ";
					cin >> p.indirizzo;
					s.push(p);
			case 2: if (!s.empty()) {
						p = s.top();
						cout << "TOP: " << endl;
						cout << "Cognome: " << p.cognome << endl;
						cout << "Nome: " << p.nome << endl;
						cout << "Indirizzo: " << p.indirizzo << endl;									
					} else {
						cout << "PILA VUOTA" << endl;
					}
					break;
			case 3:	if (!s.empty()) {
						p = s.pop();
						cout << "POP: " << endl;
						cout << "Cognome: " << p.cognome << endl;
						cout << "Nome: " << p.nome << endl;
						cout << "Indirizzo: " << p.indirizzo << endl;		
					} else {
						cout << "PILA VUOTA" << endl;
					}
					break;
			case 4: s.stampa();
					break;
			case 5: cout << "Uscita dal programma";
			
		}	
	} while (scelta != 5);
	
	return 0;
}
