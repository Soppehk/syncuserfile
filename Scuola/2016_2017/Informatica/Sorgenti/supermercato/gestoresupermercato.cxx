#include <iostream>
#include <fstream>
#include "supermercato.h"
#define DIM 10
using namespace std;

void menu(int step) {
	if (step == 0) {
		cout << "1) Crea un nuovo supermercato" << endl;
		cout << "2) Gestisci un supermercato esistente" << endl;
		cout << "3) Esci dal programma" << endl;
		cout << "==> ";
	}

	if (step == 1) {
		cout << "CREAZIONE NUOVO SUPERMERCATO" << endl;
		cout << "1) Inserisci nome del file di salvataggio" << endl;
		cout << "2) Vai al livello superiore" << endl;
		cout << "==> ";
	}

	if (step == 2) {
		cout << "GESTIONE SUPERMERCATO ESISTENTE" << endl;
		cout << "1) Inserisci il nome del file" << endl;
		cout << "2) Vai al livello superiore" << endl;
		cout << "==> ";
	}

	if (step == 3) {
		cout << "OPERAZIONI SUPERMERCATO" << endl;
		cout << "1) Inserisci nuovo prodotto" << endl;
		cout << "2) Acquista prodotto" << endl;
		cout << "3) Vendi prodotto" << endl;
		cout << "4) Elimina prodotto" << endl;
		cout << "5) Visualizza prodotti eliminati" << endl;
		cout << "6) Elimina per sempre prodotti" << endl;
		cout << "7) Stampa situazione" << endl;
		cout << "8) Ordina prodotti per codice" << endl;
		cout << "9) Ordina prodotti per descrizione" << endl;
		cout << "10) Vai al livello superiore" << endl;
	}
}

int main() {
	int scelta;
	char nomefile[256];

	cout << "GESTORE SUPERMERCATO" << endl;

	do {
		do {
			menu(0);
			cin >> scelta;
		} while ((scelta < 1) || (scelta > 3));
		switch (scelta) {
			case 1: {
				do {
					menu(1);
					cin.ignore();
					cin >> scelta;
				} while ((scelta < 1) || (scelta > 2));
				if (scelta == 1) {
					cout << "CREAZIONE NUOVO SUPERMERCATO" << endl;
					cout << "Inserisci nome del file: ";
					cin >> nomefile;
					Supermercato s(nomefile, 'W');
					s.nuovoProd();
					s.scriviFile();
					if (scelta !=3) {
						do {
							menu(3);
							cin.ignore();
							cin >> scelta;
						} while ((scelta < 1) || (scelta > 10));
						switch (scelta) {
							case 1: {
								s.nuovoProd();
								break;
							}
							case 2: {
								cout << "Acquisto prodotto" << endl;
								s.incDecGiacProd('I');
								break;
							}
							case 3: {
								cout << "Vendita prodotto" << endl;
								s.incDecGiacProd('D');
								break;
							}
							case 4: {
								cout << "Elimina prodotto" << endl;
								s.elProdLog();
								break;
							}
							case 5: {
								cout << "Stampa prodotti eliminati" << endl;
								s.stampaEliminati();
								break;
							}
							case 6: {
								cout << "Elimina per sempre i prodotti" << endl;
								s.elProdFis();
								break;
							}
							case 7: {
								cout << "Stampa situazione" << endl;
								s.stampaSituazione();
								break;
							}
							case 8: {
								cout << "Ordina prodotti per codice" << endl;
								s.quickSortCod(0, s.getNumProd() -1);
								break;
							}
							case 9: {
								cout << "Ordina prodotti per descrizione" << endl;
								s.quickSortDescr(0, s.getNumProd() -1);
								break;
							}
						}
					}
				}
				break;
			}
			case 2: {
				do {
					menu(2);
					cin >> scelta;
				} while ((scelta < 1) || (scelta > 2));
				if (scelta == 1) {
					cout << "RECUPERO INFORMAZIONI SUPERMERCATO" << endl;
					cout << "Inserisci nome del file: ";
					cin >> nomefile;
					Supermercato s(nomefile, 'R');
					s.stampaSituazione();
					if (scelta !=3) {
						do {
							menu(3);
							cin.ignore();
							cin >> scelta;
						} while ((scelta < 1) || (scelta > 10));
						switch (scelta) {
							case 1: {
								s.nuovoProd();
								break;
							}
							case 2: {
								cout << "Acquisto prodotto" << endl;
								s.incDecGiacProd('I');
								break;
							}
							case 3: {
								cout << "Vendita prodotto" << endl;
								s.incDecGiacProd('D');
								break;
							}
							case 4: {
								cout << "Elimina prodotto" << endl;
								s.elProdLog();
								break;
							}
							case 5: {
								cout << "Stampa prodotti eliminati" << endl;
								s.stampaEliminati();
								break;
							}
							case 6: {
								cout << "Elimina per sempre i prodotti" << endl;
								s.elProdFis();
								break;
							}
							case 7: {
								cout << "Stampa situazione" << endl;
								s.stampaSituazione();
								break;
							}
							case 8: {
								cout << "Ordina prodotti per codice" << endl;
								s.quickSortCod(0, s.getNumProd() -1);
								break;
							}
							case 9: {
								cout << "Ordina prodotti per descrizione" << endl;
								s.quickSortDescr(0, s.getNumProd() -1);
								break;
							}
						}
					}
				}
				break;
			}
		}

	} while(scelta != 3);
	cout << "Uscita dal programma" << endl;
	gets(nomefile);
	// Supermercato s(nomefile, 'R');
	// s.stampaSituazione();

	return 0;
}
