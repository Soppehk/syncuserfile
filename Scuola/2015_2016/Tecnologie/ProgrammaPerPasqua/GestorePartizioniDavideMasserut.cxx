#include <iostream>
using namespace std;

void PartIniMem(int part[][2], int &np, int &dm) {
	int somma = 0;

	cout << "\nInserire dati su partizionamento iniziale" << endl;
	cout << "\nInserire dimensione della memoria(min 2MB, max 1024MB):" << endl;

	do {
        cout << "==> ";
		cin >> dm;
	} while ((dm < 2) || (dm > 1024));

	cout << "\nInserire il numero di partizioni occupate(min 0, max 20):" << endl;

	do {
		cout << "==> ";
		cin >> np;
	} while ((np < 0) || (np > 20));

	for (int i = 0; i < np; i++) {

		cout << "\nInserire l'indirizzo di partenza della partizione P" << i << " :" << endl;

		if (i == 0) {
			do {
				cout << "==> ";
				cin >> part[i][0];
			} while ((part[i][0] < 00) || (part[i][0] > dm));

		} else {
			do {
				cout << "==> ";
				cin >> part[i][0];
			} while ((part[i][0] < part[i - 1][0] + part[i - 1][1]) ||	(part[i][0] > dm));
		}

		cout << "Inserire la dimensione della partizione P" << i << " :" << endl;

		if (i == 0) {
			do {
				cout << "==> ";
				cin >> part[i][1];
			} while ((part[i][1] <= 0) || (part[i][1] > dm));

		} else {
			do {
				cout << "==> ";
				cin >> part[i][1];
			} while ((part[i][1] <= 0) || (part[i][1] > dm - (part[i - 1][0] + part[i - 1][1])));
		}

		somma = part[i][0] + part[i][1];

		if ((somma == dm) && (i < np - 1)) {
			cout << "\nNon è possibile aggiungere le partizioni rimanenti!\nIl programma cancellera' la partizione appena aggiunta";
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
	cout << "\nInd	Dim" << endl;
	if (n > 0) {
		for (int i = 0; i < n; i++) {
			cout << part[i][0];
			if (part[i][0] < 10) {
				cout << "		";
			}
			if ((part[i][0] < 100) && (part[i][0] > 9)) {
				cout << "	 ";
			}
			if ((part[i][0] < 1000) && (part[i][0] > 99)) {
				cout << "	";
			}
			if ((part[i][0] > 999)) {
				cout << " ";
			}
			cout << part[i][1];
			cout << endl;
		}
	} else {
		cout << "Nessuna partizione!" << endl;
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

	cout << "\nInserire il quantitativo di memoria del programma:" << endl;

	do {
		if (p > max) {
			cout << "Il nuovo programma non puo' richiedere piu' memoria di quella disponibile!" << endl;
		}
		cout << "==> ";
		cin >> p;
	} while ((p < 0) || (p > max));
	return p;
}

void InsProg(int part1[][2], int part2[][2], int i, int &npo, int &npl, int p,
						 int dm) {
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
		cout << "\nE' stato raggiunto il limite massimo di partizioni, impossibile crearne di nuove!";
	}

	cout << "\nStampa Partizioni occupate";
	StampaTabella(part1, npo);
	cout << "\nStampa Partizioni libere";
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

		cout << "\nPrememere 0 per terminare il programma o 1 per inserire un "
						"altro programma\n==> ";
		cin >> scelta;
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

		cout << "\nPrememere 0 per terminare il programma o 1 per inserire un altro programma\n==> ";
		cin >> scelta;
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

		cout << "\nPrememere 0 per terminare il programma o 1 per inserire un altro programma\n==> ";
		cin >> scelta;
	} while (scelta != 0);

	return;
}

int main() {
	int partocc[50][2], partlib[50][2]; // matrici contenenti i valori
	int numpartocc, numpartlib = 0, dimmem, scelta;

	cout << "Programma per la gestione delle partizioni di memoria" << endl;

	PartIniMem(partocc, numpartocc, dimmem);
	CalcPartLib(partocc, partlib, numpartocc, numpartlib, dimmem);

	cout << "\nStampa partizioni occupate";
	StampaTabella(partocc, numpartocc);
	cout << "\nStampa partizioni libere";
	StampaTabella(partlib, numpartlib);

	if (numpartlib != 0) {
		cout << "\nPer poter inserire nuovi programmi, scegliere una stratergia:";
		cout << "\n1) FirstFit\n2) BestFit\n3) WorstFit" << endl;

		do {
			cout << "==> ";
			cin >> scelta;
		} while ((scelta < 1) || (scelta > 3));

		switch (scelta) {
		case 1:
			cout << "\nStrategia FirstFit";
			FirstFit(partocc, partlib, numpartocc, numpartlib, dimmem);
			break;

		case 2:
			cout << "\nStrategia BestFit";
			BestFit(partocc, partlib, numpartocc, numpartlib, dimmem);
			break;

		case 3:
			cout << "\nStrategia WorstFit";
			WorstFit(partocc, partlib, numpartocc, numpartlib, dimmem);
			break;
		}
	} else {
		cout << "\nNessuna partizione libera!\nTerminazione del programma";
	}

	return 0;
}
