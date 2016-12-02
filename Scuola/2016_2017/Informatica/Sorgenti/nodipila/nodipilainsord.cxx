#include <iostream>
using namespace std;


struct nodo {
	int dato;
	nodo *next;
};

class stack {
	nodo *head;
public:
	stack();
	void insOrd(int);
	void stampa();
	bool trova(int);
};

stack::stack() {
	head = NULL;
}

void stack::insOrd(int d){
	nodo *aux, *prec, *succ;

	aux = new nodo;
	// se voglio controllare if(aux!=NULL)

	aux->dato = d;
	aux->next = NULL;
	if(head == NULL || head->dato > d){
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


void stack::stampa() {
	nodo *aux;
	aux = head;
	while (aux != NULL) {
		cout << aux->dato << endl;
		aux = aux->next;
	}
}

bool stack::trova(int i) {
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

int main() {
	stack s;
	int j;

	cout << "Inserisci oridinatamente 5 numeri" << endl;

	for (int i = 0; i < 5; i++) {
		cout << "==> ";
		cin >> j;
		s.insOrd(j);
	}
	s.stampa();
	if (s.trova(5)) {
		cout << "Il numero 5 e' stato trovato";
	} else {
		cout << "Il numero 5 non è stato trovato";
	}

	return 0;
}
