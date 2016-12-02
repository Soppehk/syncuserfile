#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <cstdio>
#include "prodotto.h"
#define DIM 10
using namespace std;

class Supermercato {
	char nomefile[256];
	prodotto p[DIM];
	int nprod;
	float valore;
	fstream file;
	int trovaProd(int);
public:
	Supermercato(char*, char); // Se string == "R" => legge il file, Se string == "W" => crea file
	void setNomeFile(char*);
	int getNumProd();
	float getValore();
	char *getNomeFile();
	void nuovoProd();
	void nuovoSuper();
	void elProdLog();
	void elProdFis();
	void scriviFile();
	void leggiFile();
	void incDecGiacProd(char);
	void stampaSituazione();
	void stampaEliminati();
	void quickSortCod(int, int);
	void quickSortDescr(int, int);
};

int Supermercato::trovaProd(int cod) {
	for (int i = 0; i < nprod; i++) {
		if (p[i].getCod() == cod) {
			return i;
		}
	}

	return -1;
}

Supermercato::Supermercato(char *c, char parametro) {  // Se parametro == 'R' => legge il file, Se parametro == 'W' => crea file
	nprod = 0;
	strcpy(nomefile, c);
	if (parametro == 'R') {
		do {
			file.open(nomefile, ios::in);
			if (file.fail()) {
				cout << "File non esistente o leggibile, inserire un altro nome: ";
				cin.ignore();
				gets(nomefile);
			}
		} while (file.fail());
		leggiFile();
	}
	if (parametro == 'W') {
		//controllare perche' il programma dice che esiste un file che non esiste quando il primo file inserito effettivamente non esiste
		do {
			file.open(nomefile, ios::in);
			if (file.is_open()) {
				cout << "File già esistente, inserire un altro nome: ";
				gets(nomefile);
			}
		} while(file.is_open());
		file.open(nomefile, ios::out);
		file.close();
	}
}


int Supermercato::getNumProd() {
	return nprod;
}

float Supermercato::getValore() {
	return valore;
}

char *Supermercato::getNomeFile() {
	return nomefile;
}

void Supermercato::nuovoProd() {
	int iaux;
	char cauxd[25];
	char cauxu[5];
	float faux;

	cout << "NUOVO PRODOTTO" << endl;

	do {
		cout << "Inserisci codice del prodotto: ";
		cin >> iaux;
		if (trovaProd(iaux) != -1) {
			cout << "Codice gia' inserito!" << endl;
		}
		if (iaux < 0) {
			cout << "Codice negativo!" << endl;
		}
	} while ((trovaProd(iaux) != -1) || iaux < 0);
	p[nprod].setCod(iaux);
	cout << "Inserisci il nome/descrizione del prodotto (max 25): ";
	cin.ignore();
	gets(cauxd);
	p[nprod].setDescr(cauxd);
	cout << "Insersci l'unita' di misura (max 5): ";
	gets(cauxu);
	p[nprod].setUnMis(cauxu);

	do {
		cout << "Inserisci quantita' di prodotti: ";
		cin >> iaux;
		if (iaux < 0) {
			cout << "Quantita' negativa!" << endl;
		}
	} while (iaux < 0);
	p[nprod].setNum(iaux);

	do {
		cout << "Inserisci prezzo del prodotto: ";
		cin >> faux;
		if (faux < 0.0) {
			cout << "Non regalare soldi ai clienti!" << endl;
		}
	} while (faux < 0.0);
	p[nprod].setPrez(faux);
	valore += faux;
	nprod++;

	return;
}


void Supermercato::scriviFile() {
	file.open(nomefile, ios::binary | ios::out);

	file.write((char*)&*this, sizeof(Supermercato));

	file.close();
}

void Supermercato::leggiFile() {
	file.open(nomefile, ios::binary | ios::in);

	file.read((char*)&*this, sizeof(Supermercato));

	file.close();
}

void Supermercato::elProdLog() {
	int indice;

	cout << "Inserisci codice prodotto:" << endl;
	do {
		cout << "==> ";
		cin >> indice;
		if (trovaProd(indice)) {
			cout << "Prodotto non esistente!" << endl;
		}
	} while(trovaProd(indice));
	p[indice].setCanc(false);
	valore -= p[indice].getPrez() * p[indice].getNum();
}

void Supermercato::elProdFis() {
	//da fare entro ieri
}

void Supermercato::incDecGiacProd(char c) {
	int indice, el;
	if ((c == 'I') || (c == 'D')) {
		cout << "Parametro non valido!!!" << endl;
	}

	cout << "Inserisci codice prodotto:" << endl;
	do {
		cout << "==> ";
		cin >> indice;
		if (trovaProd(indice)) {
			cout << "Prodotto non esistente!" << endl;
		}
	} while(trovaProd(indice));

	cout << "Inserisci nuove giacenze:" << endl;
	if (c == 'D') {
		cout << "==> ";
		cin >> el;
		p[indice].DecNum(el);
		valore -= p[indice].getPrez() * el;
	} else {
		cout << "==> ";
		cin >> el;
		p[indice].IncNum(el);
		valore += p[indice].getPrez() * el;
	}
}

void Supermercato::stampaSituazione() {
	cout << "Supermercato " << nomefile << endl;
	cout << "Valore complessivo: " << valore << endl;
	for (int i = 0; i <= nprod; i++) {
		if (p[i].getCod() != -1) {
			cout << p[i];
		}
	}
	cout << endl;
}

void Supermercato::stampaEliminati() {
	for (int i = 0; i < nprod; i++) {
		if (p[i].getCod() == -1) {
			cout << p[i];
		}
	}
}

void Supermercato::quickSortCod(int sx, int dx) {
	int s=sx, d=dx;
	int pivot=p[(sx+dx)/2].getCod();
	prodotto aux;

	while(s<=d){
		while(p[s].getCod()<pivot){
			s++;
		}
		while(p[d].getCod()>pivot){
			d--;
		}
		if(s<=d){
			aux = p[s];
			p[s] = p[d];
			p[d] = aux;
			s++;
			d--;
		}
	}
	if(sx<d){
		quickSortCod(sx,d);
	}
	if(s<dx){
		quickSortCod(s,dx);
	}

	return;
}

void Supermercato::quickSortDescr(int sx, int dx) {
	int s = sx, d = dx;
	char pivot = p[(sx + dx) / 2].getDescr();
	prodotto aux;

	while (s <= d) {
		while (p[s].getDescr() < pivot) {
			s++;
		}
		while (p[d].getDescr() > pivot){
			d--;
		}
		if (s <= d){
			aux = p[s];
			p[s] = p[d];
			p[d] = aux;
			s++;
			d--;
		}
	}
	if (sx < d){
		quickSortCod(sx, d);
	}
	if (s < dx){
		quickSortCod(s, dx);
	}

	return;
}
