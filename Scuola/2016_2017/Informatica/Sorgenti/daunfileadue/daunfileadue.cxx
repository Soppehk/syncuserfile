#include <iostream>
#include <fstream>
using namespace std;

class stringhe {
fstream file;
char nomefile[128];
string v[100];
string confronto;
int n = 0;

public:
	void ControlloFile();
	void CaricoVett();
	void Chiedo();
	void Carico();
};

void stringhe::ControlloFile() {
	cout << "Inserisci il nome del file: ";
	cin >> nomefile;
	file.open(nomefile, ios::in);
	if(file.fail()) {
		cout << "Il file " << nomefile << " non esiste!" << endl;
		cout << "ERRORE" << endl;
		file.close();
		exit(1);
	} else {
		cout << "Il file " << nomefile << " e' valido" << endl;
		file.close();
	}

	return;
}

void stringhe::CaricoVett() {
	file.open(nomefile, ios::in);

	getline(file, v[n]);
	while (!file.eof()) {
		n++;
		getline(file, v[n]);
	}

	file.close();

	return;
}

void stringhe::Chiedo() {
	cout << "Inserisci parola da confrontare: ";
	cin >> confronto;

	return;
}

void stringhe::Carico() {
	cout << "Inserisci nome file: ";
	cin >> nomefile;
	file.open(nomefile, ios::out);
	for (int i = 0; i <= n; i++) {
		if (v[i] > confronto) {
			file << v[i] << endl;
		}
	}

	file.close();

	return;
}

int main(int argc, char const *argv[]) {
	stringhe s;

	s.ControlloFile();
	s.CaricoVett();
	s.Chiedo();
	s.Carico();

	return 0;
}
