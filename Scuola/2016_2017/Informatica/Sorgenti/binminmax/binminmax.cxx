#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct persona {
	char nome[20];
	int eta;
};

void creoBin() {

	struct persona p[3];

	p[0].eta = 50;
	strcpy(p[0].nome, "Marco");
	p[1].eta = 65;
	strcpy(p[1].nome, "Dio");
	p[2].eta = 45;
	strcpy(p[2].nome, "Gio");


	FILE *file;
	file = fopen("bin", "wb+");
	fwrite(&p, sizeof(struct persona),3,file);
	fclose(file);

	return;
}

int main () {
	//creoBin();
	struct persona per, pv, pg;
	int n = 0;
	bool ord = true;
	int eta;

	FILE *file;

	file = fopen("bin", "rb");

	fread(&per, sizeof(struct persona), 1, file);

	pv = per;
	pg = per;

	eta = per.eta;

	while (!feof(file)) {
		fread(&per, sizeof(struct persona), 1, file);
		if (per.eta > eta) {
			eta = per.eta;
		} else {
			ord = false;
		}
		if (per.eta > pv.eta) {
			pv.eta = per.eta;
		}
		if (per.eta < pg.eta) {
			pg.eta = per.eta;
		}
		n++;
	}

	cout << "vecchio " << pv.nome << pv.eta << endl;
	cout << "giovane " << pg.nome << pg.eta << endl;
	cout << "n " << n << endl;
	cout << "ord" << ord;

	fclose(file);

	return 0;
}
