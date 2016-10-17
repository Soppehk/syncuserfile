#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char const *argv[]) {
	fstream file1, file2;
	int eta[3], contatore = 0, iaux;
	string nome[3], cognome[3], saux;
	float media = 0;

	// file1.open("in", ios::out | ios::binary);
	//
	// saux = "Marco";
	// file1.write((char *)&saux, sizeof(string));
	// saux = "Rello";
	// file1.write((char *)&saux, sizeof(string));
	// saux = 40;
	// file1.write((char *)&iaux, sizeof(int));
	// saux = "Davide";
	// file1.write((char *)&saux, sizeof(string));
	// saux = "Masserut";
	// file1.write((char *)&saux, sizeof(string));
	// saux = 50;
	// file1.write((char *)&iaux, sizeof(int));
	// saux = "Giovanni";
	// file1.write((char *)&saux, sizeof(string));
	// saux = "Turchez";
	// file1.write((char *)&saux, sizeof(string));
	// saux = 30;
	// file1.write((char *)&iaux, sizeof(int));
	//
	// file1.close();
	file1.open("in", ios::in | ios::binary);
	file2.open("out", ios::out | ios::binary);

	file1.read((char *)&nome[0], sizeof(string));
	file1.read((char *)&cognome[0], sizeof(string));
	file1.read((char *)&eta[0], sizeof(int));
	media = eta[0];

	while (!file1.eof()) {
		contatore++;
		file1.read((char *)&cognome[contatore], sizeof(string));
		file1.read((char *)&cognome[contatore], sizeof(string));
		file1.read((char *)&eta[contatore], sizeof(int));
		media = media + eta[contatore];
	}

	for (int i = contatore; i >= 0; i--) {
		file2.write((char *)&eta[i], sizeof(int));
		file2.write((char *)&cognome[i], sizeof(string));
		file2.write((char *)&cognome[i], sizeof(string));
	}

	cout << "Media :" << media / contatore;

	file1.close();
	file2.close();

	return 0;
}