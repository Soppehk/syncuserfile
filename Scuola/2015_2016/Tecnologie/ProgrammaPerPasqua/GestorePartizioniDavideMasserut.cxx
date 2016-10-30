#include <iostream>

void PartIniMem(int part[][2], int &np, int &dm) {
	int somma = 0;

	std::cout << "\nInserire dati su partizionamento iniziale" << std::endl;
	std::cout << "\nInserire dimensione della memoria(min 2MB, max 1024MB):" << std::endl;

	do {
		std::cout << "==> ";
		std::cin >> dm;
	} while ((dm < 2) || (dm > 1024));

	std::cout << "\nInserire il numero di partizioni occupate(min 0, max 20):" << std::endl;

	do {
		std::cout << "==> ";
		std::cin >> np;
	} while ((np < 0) || (np > 20));

	for (int i = 0; i < np; i++) {

		std::cout << "\nInserire l'indirizzo di partenza della partizione P" << i << " :" << std::endl;

		if (i == 0) {
			do {
				std::cout << "==> ";
				std::cin >> part[i][0];
			} while ((part[i][0] < 00) || (part[i][0] > dm));

		} else {
			do {
				std::cout << "==> ";
				std::cin >> part[i][0];
			} while ((part[i][0] < part[i - 1][0] + part[i - 1][1]) ||	(part[i][0] > dm));
		}

		std::cout << "Inserire la dimensione della partizione P" << i << " :" << std::endl;

		if (i == 0) {
			do {
				std::cout << "==> ";
				std::cin >> part[i][1];
			} while ((part[i][1] <= 0) || (part[i][1] > dm));

		} else {
			do {
				std::cout << "==> ";
				std::cin >> part[i][1];
			} while ((part[i][1] <= 0) || (part[i][1] > dm - (part[i - 1][0] + part[i - 1][1])));
		}

		somma = part[i][0] + part[i][1];

		if ((somma == dm) && (i < np - 1)) {
			std::cout << "\nNon è possibile aggiungere le partizioni rimanenti!\nIl programma cancellera' la partizione appena aggiunta";
			somma = somma - part[i][1];
			i--;
		}
	}

	return;
}

void CalcPartLib(int part1[][2], int part2[][2], int npo, int &npl, int dm) {
	npl = 0;

	if (npo == 0) {
		part2[0][1] = dm;
		npl++;
	} else {
		if (part1[0][0] == 0) {
			for (int i = 0; i < npo; i++) {
				if (i < npo - 1) {
					if (part1[i + 1][0] > (part1[i][0] + part1[i][1])) {
						part2[npl][0] = part1[i][0] + part1[i][1];
						part2[npl][1] = part1[i + 1][0] - part2[npl][0];
						npl++;
					}
				} else {
					if (dm > (part1[i][0] + part1[i][1])) {
						part2[npl][0] = part1[i][0] + part1[i][1];
						part2[npl][1] = dm - part2[npl][0];
						npl++;
					}
				}
			}
		} else {
			part2[npl][0] = 0;
			part2[npl][1] = part1[0][0];
			npl++;
			for (int i = 1; i < npo; i++) {
				if (i <= npo - 1) {
					if (part1[i][0] > (part1[i - 1][0] + part1[i - 1][1])) {
						part2[npl][0] = part1[i - 1][0] + part1[i - 1][1];
						part2[npl][1] = part1[i][0] - part2[npl][0];
						npl++;
					}
				}
			}
			if (dm > (part1[npo - 1][0] + part1[npo - 1][1])) {
				part2[npl][0] = part1[npo - 1][0] + part1[npo - 1][1];
				part2[npl][1] = dm - part2[npl][0];
				npl++;
			}
		}
	}

	return;
}

void StampaTabella(int part[][2], int n) {
	std::cout << "\nInd	Dim" << std::endl;
	if (n > 0) {
		for (int i = 0; i < n; i++) {
			std::cout << part[i][0];
			if (part[i][0] < 10) {
				std::cout << "		";
			}
			if ((part[i][0] < 100) && (part[i][0] > 9)) {
				std::cout << "	 ";
			}
			if ((part[i][0] < 1000) && (part[i][0] > 99)) {
				std::cout << "	";
			}
			if ((part[i][0] > 999)) {
				std::cout << " ";
			}
			std::cout << part[i][1];
			std::cout << std::endl;
		}
	} else {
		std::cout << "Nessuna partizione!" << std::endl;
	}

	return;
}

int InputProgrammi(int part[][2], int n) {
	int p = 0, max = 0;

	for (int i = 0; i < n; i++) {
		if (part[i][1] > max) {
			max = part[i][1];
		}
	}

	std::cout << "\nInserire il quantitativo di memoria del programma:" << std::endl;

	do {
		if (p > max) {
			std::cout << "Il nuovo programma non puo' richiedere piu' memoria di quella disponibile!" << std::endl;
		}
		std::cout << "==> ";
		std::cin >> p;
	} while ((p < 0) || (p > max));
	return p;
}

void InsProg(int part1[][2], int part2[][2], int i, int &npo, int &npl, int p, int dm) {
	int k = npo - 1;

	if (npo <= 50) {
		while (part1[k][0] > part2[i][0]) {
			part1[k + 1][0] = part1[k][0];
			part1[k + 1][1] = part1[k][1];
			k--;
		}

		part1[k + 1][0] = part2[i][0];
		part1[k + 1][1] = p;
		npo++;

		CalcPartLib(part1, part2, npo, npl, dm);
	} else {
		std::cout << "\nE' stato raggiunto il limite massimo di partizioni, impossibile crearne di nuove!";
	}

	std::cout << "\nStampa Partizioni occupate";
	StampaTabella(part1, npo);
	std::cout << "\nStampa Partizioni libere";
	StampaTabella(part2, npl);

	return;
}

void FirstFit(int part1[][2], int part2[][2], int &npo, int &npl, int dm) {
	int prog, i = 0, scelta;

	do {
		prog = InputProgrammi(part2, npl);

		while (part2[i][1] < prog) {
			i++;
		}

		InsProg(part1, part2, i, npo, npl, prog, dm);

		std::cout << "\nPrememere 0 per terminare il programma o 1 per inserire un "
						"altro programma\n==> ";
		std::cin >> scelta;
	} while (scelta != 0);

	return;
}

void BestFit(int part1[][2], int part2[][2], int &npo, int &npl, int dm) {
	int prog, i = 0, scelta, min;

	do {
		min = 1024;
		prog = InputProgrammi(part2, npl);

		for (int k = 0; k < npl; k++) {
			if ((part2[k][1] <= min) && (part2[k][1] >= prog)) {
				min = part2[k][1];
				i = k;
			}
		}

		InsProg(part1, part2, i, npo, npl, prog, dm);

		std::cout << "\nPrememere 0 per terminare il programma o 1 per inserire un altro programma\n==> ";
		std::cin >> scelta;
	} while (scelta != 0);

	return;
}

void WorstFit(int part1[][2], int part2[][2], int &npo, int &npl, int dm) {
	int prog, i = 0, scelta, max;

	do {
		max = 0;
		prog = InputProgrammi(part2, npl);

		for (int k = 0; k < npl; k++) {
			if ((part2[k][1] >= max) && (part2[k][1] >= prog)) {
				max = part2[k][1];
				i = k;
			}
		}

		InsProg(part1, part2, i, npo, npl, prog, dm);

		std::cout << "\nPrememere 0 per terminare il programma o 1 per inserire un altro programma\n==> ";
		std::cin >> scelta;
	} while (scelta != 0);

	return;
}

int main() {
	int partocc[50][2], partlib[50][2]; // matrici contenenti i valori
	int numpartocc, numpartlib = 0, dimmem, scelta;

	std::cout << "Programma per la gestione delle partizioni di memoria" << std::endl;

	PartIniMem(partocc, numpartocc, dimmem);
	CalcPartLib(partocc, partlib, numpartocc, numpartlib, dimmem);

	std::cout << "\nStampa partizioni occupate";
	StampaTabella(partocc, numpartocc);
	std::cout << "\nStampa partizioni libere";
	StampaTabella(partlib, numpartlib);

	if (numpartlib != 0) {
		std::cout << "\nPer poter inserire nuovi programmi, scegliere una stratergia:";
		std::cout << "\n1) FirstFit\n2) BestFit\n3) WorstFit" << std::endl;

		do {
			std::cout << "==> ";
			std::cin >> scelta;
		} while ((scelta < 1) || (scelta > 3));

		switch (scelta) {
		case 1:
			std::cout << "\nStrategia FirstFit";
			FirstFit(partocc, partlib, numpartocc, numpartlib, dimmem);
			break;

		case 2:
			std::cout << "\nStrategia BestFit";
			BestFit(partocc, partlib, numpartocc, numpartlib, dimmem);
			break;

		case 3:
			std::cout << "\nStrategia WorstFit";
			WorstFit(partocc, partlib, numpartocc, numpartlib, dimmem);
			break;
		}
	} else {
		std::cout << "\nNessuna partizione libera!\nTerminazione del programma";
	}

	return 0;
}
