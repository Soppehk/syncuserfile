#include <stdio.h>

struct studente {
	char nome[20];
	char cognome[20];
	int matricola;
};

int main() {
	FILE *fp;
	struct studente stud;
	//struct studente ustud[10];
	int n = 0;

	std::cout << "Apriamo il file e lo popoliamo" << std::endl;
	fp = fopen("text.bin","wb");
	for (size_t i = 0; i < 5; i++) {
		std::cout << "\nDigita il nome: ";
		std::cin >> stud.nome;
		std::cout << "\nDigita il cognome: ";
		std::cin >> stud.cognome;
		std::cout << "\nDigita la matricola: ";
		std::cin >> stud.matricola;
		fwrite(&stud, sizeof(struct studente), 1, fp);
	}

	fclose(fp);
	std::cout << "\nOra leggo da file" << std::endl;
	fp = fopen("text.bin","rb");
	fread(&stud, sizeof(struct studente), 1, fp);
	while (!feof(fp)) {
		n++;
		std::cout << "\nNome:" << stud.nome << std::endl;
		std::cout << "\nCognome: " << stud.cognome << std::endl;
		std::cout << "\nMatricola: " << stud.matricola << std::endl;
	}

	return 0;
}
