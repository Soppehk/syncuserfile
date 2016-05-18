#include <iostream>
#define NFILE 5
#define NPOLTRONE 5
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

	cout<<"    PALCO"<<endl<<"    ";
	for (int i=0;i<NPOLTRONE*2;i++){
		cout<<"-";
	}
	cout<<endl<<"    ";

    for (int i=0;i<NPOLTRONE;i++){
		cout<<i+1<<"  ";
	}
    cout<<endl;

    for (int i=0;i<NFILE;i++){
        cout<<i+1;
		if(i+1<10){
			cout<<"   ";
		}
		if((i+1<100)&&(i+1>9)){
			cout<<"  ";
		}
		if((i+1<1000)&&(i+1>99)){
			cout<<" ";
		}

        for (int j=0;j<NPOLTRONE;j++){
            if (posti[i][j]==1){
                cout<<"X  ";
            } else {
                cout<<"-  ";
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

int Ricerca(int posti[NFILE][NPOLTRONE], int posticont, int fila){
	int contatore=0;
	int indice=-1;

	for(int i=0;i<NPOLTRONE;i++){
		if(posti[fila][i]==0){
			contatore++;
			if(indice==-1){
				indice=i;
			}
		}else{
			contatore=0;
			indice=i+1;
		}
	}

	if(contatore<posticont){
		indice=-1;
	}
	cout<<"ricerca indice: "<<indice;
	return indice;
}

void AssPostCont(int posti[NFILE][NPOLTRONE], int nposti, int &npostiocc){
	int posticont;

	cout<<"Inserire il numero di posti contigui desiderati, il programma assegnerà i primi posti disponibili:"<<endl;
	do {
		cout<<"==> ";
		cin>>posticont;
		if ((posticont<2)||(posticont>nposti)||(posticont+npostiocc>nposti)){
			cout<<"Errore!"<<endl;
		}
	} while((posticont<2)||(posticont>nposti)||(posticont+npostiocc>nposti));

	for (int i=0;i<NFILE;i++){
		if(Ricerca(posti,posticont,i)!=-1){
			for(int j=Ricerca(posti,posticont,i);j<posticont;j++){
				posti[i][j]=1;
				npostiocc++;
			}
			break;
		}
	}

	return;
}

void ElimPost(int posti[NFILE][NPOLTRONE], int nposti, int &npostiocc){
	int fila, poltrona;

	if (npostiocc==0) {
        cout<<"Nessun eliminazione possibile!"<<endl;
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

            if (posti[fila-1][poltrona-1]==0) {
                cout<<"Il posto è già libero!"<<endl;
            }
        } while(posti[fila-1][poltrona-1]==0);

        posti[fila-1][poltrona-1]=0;
		npostiocc--;
    }

	return;
}

int main(){
	int posti[NFILE][NPOLTRONE];
	int nposti=NFILE*NPOLTRONE;
	int npostiocc=0;
    int  scelta;

	cout<<"GESTORE POSTI TEATRO"<<endl;

	InizPosti(posti);

    do {
		Stampa(posti,nposti,npostiocc);
		cout<<"Premi 1 per assegnare un posto, 2 per assegnare più posti o 3 per liberare un posto"<<endl;
		do {
			cout<<"==> ";
			cin>>scelta;
		} while((scelta<1)||(scelta>3));
		switch (scelta) {
			case 1: cout<<"Assegnazione posto"<<endl;
					AssPosto(posti,nposti,npostiocc);
					break;
			case 2: cout<<"Assegnazione posti contigui"<<endl;
					AssPostCont(posti,nposti,npostiocc);
					break;
			case 3: cout<<"Eliminazione assegnazione posto"<<endl;
					ElimPost(posti,nposti,npostiocc);
					break;
		}

		Stampa(posti,nposti,npostiocc);
        cout<<"Premi 0 per uscire dal programma o 1 per continuare: "<<endl;
		do {
			cout<<"==> ";
			cin>>scelta;
		} while((scelta<0)||(scelta>1));

    } while(scelta);

	return 0;
}
