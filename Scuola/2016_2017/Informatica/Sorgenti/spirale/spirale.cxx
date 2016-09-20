#include<iostream>

int input(int &n) {
	do {
		std::cout << "Inserisci un numero maggiore di 3 e massimo 9: ";
		std::cin >> n;
		std::cout << std::endl;
	} while((n < 3 ) || (n > 9));

	return 0;
}

void StampaTabella(int matrice[10][10], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << matrice[j][i] << " ";
		}
		std::cout << std::endl;
	}

	return;
}

void spiralizzatore(int matrice[10][10], int n) {
	int i = 1, x = n, y = n, j = 0, k = 0, l = 0, m = 0;

	do {
		for (j = l; j < x; j++) {
			matrice[j][k] = i;
			std::cout << matrice[j][k];
			i++;
		}
		x--;
		for (k = m; k < y; k++) {
			matrice[j][k] = i;
			std::cout << matrice[j][k];
			i++;
		}
		y--;
		for (l = j; l >= n - x; l--) {
			matrice[l][m] = i;
			std::cout << matrice[l][m];
			i++;
		}
		x--;
		for (m = k; m >= n - y; m--) {
			matrice[l][m] = i;
			std::cout << matrice[l][m];
			i++;
		}
		y--;

	} while (i <= n * n);

	return;
}

int main(int argc, char const *argv[]) {
	int n;
	int matrice[10][10];

	input(n);
	spiralizzatore(matrice, n);
	StampaTabella(matrice, n);

	return 0;
}
