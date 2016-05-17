#include <iostream>
#define NFILE 1
#define NPOLTRONE 2
using namespace std;

void InizPosti(int posti[NFILE][NPOLTRONE]){

	for (int i=0;i<NFILE;i++){
		for (int j=0;j<NPOLTRONE;j++){
			posti[i][j]=0;
		}
	}

	return;
}

void Stampa(int posti[NFILE][NPOLTRONE], int nposti, int npostiocc){

	cout<<" PALCO"<<endl<<" ";
	for (int i=0;i<NPOLTRONE;i++){
		cout<<"-";
	}
	cout<<endl<<" ";

    for (int i=0;i<NPOLTRONE;i++){
		cout<<i+1;
	}
    cout<<endl;

    for (int i=0;i<NFILE;i++){
        cout<<i+1;
        for (int j=0;j<NPOLTRONE;j++){
            if (posti[i][j]==1){
                cout<<"X";
            } else {
                cout<<"-";
            }
        }
        cout<<endl;
    }

    cout<<"Numero posti totali: "<<nposti<<endl;
    cout<<"Numero posti occupati: "<<npostiocc<<endl;
    cout<<"Numero posti liberi: "<<nposti-npostiocc<<endl;

	return;
}

void AssPosto(int posti[NFILE][NPOLTRONE], int nposti, int &npostiocc){
    int fila, poltrona;

    if (nposti-npostiocc==0) {
        cout<<"Posti terminati!"<<endl;
    } else {
        do {
            do {
                cout<<"Inserire fila: ";
                cin>>fila;
            } while((fila>NFILE)||(fila<1));

            do {
                cout<<"Inserire poltrona: ";
                cin>>poltrona;
            } while((poltrona>NPOLTRONE)||(poltrona<1));

            if (posti[fila-1][poltrona-1]==1) {
                cout<<"Il posto è già occupato!"<<endl;
            }
        } while(posti[fila-1][poltrona-1]==1);
        posti[fila-1][poltrona-1]=1;
		npostiocc++;
    }

    return;
}

int main(){
	int posti[NFILE][NPOLTRONE];
	int nposti=NFILE*NPOLTRONE;
	int npostiocc=0;
    bool scelta=true;

	cout<<"GESTORE POSTI TEATRO"<<endl;

	InizPosti(posti);

    do {
		Stampa(posti,nposti,npostiocc);
        AssPosto(posti,nposti,npostiocc);
		Stampa(posti,nposti,npostiocc);
        cout<<"Premi 0 per uscire dal programma o 1 per continuare: ";
        cin>>scelta;
    } while(scelta);

	return 0;
}
