#include<iostream>

#define DIM 100

int input(int &n) {
	do {
		std::cout << "Inserisci un numero maggiore di 3 e massimo " << DIM -1 << " : ";
		std::cin >> n;
		std::cout << std::endl;
	} while((n < 3 ) || (n > DIM - 1));

	return 0;
}

void StampaTabella(int matrice[DIM][DIM], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%4d", matrice[i][j]);
		}
		std::cout << std::endl;
	}

	return;
}

void spiralizzatore(int matrice[DIM][DIM], int n) {
	int i = 0, c = 0, r = 0, x = n, y = n;

	while (i <= n * n) {
		while (c < x) {
			i++;
			matrice[r][c] = i;
			c++;
		}
		i--;
		c--;
		while (r < y) {
			i++;
			matrice[r][c] = i;
			r++;
		}
		i--;
		r--;
		y--;
		while (c >= n - x) {
			i++;
			matrice[r][c] = i;
			c--;
		}
		i--;
		c++;
		x--;
		while (r >= n - y) {
			i++;
			matrice[r][c] = i;
			r--;
		}
		i--;
		r++;
	}

	return;
}

int main(int argc, char const *argv[]) {
	int n;
	int matrice[DIM][DIM];

	input(n);
	spiralizzatore(matrice, n);
	StampaTabella(matrice, n);

	return 0;
}
