#include <iostream>
#include <fstream>
using namespace std;

struct libro{
	string num;
	string titolo;
	string autore;
	string editore;
};

void Input(struct libro libri[], int &num){
	fstream filelibri;
	
	filelibri.open("libri.txt",ios::app);
	
	cout<<"\nLibro N"<<num;
	filelibri<<num<<endl;
	libri[num-1].num=num;
	fflush(stdin);
	
	cout<<"\nInserire titolo: ";
	getline(cin,libri[num-1].titolo);
	filelibri<<libri[num-1].titolo<<endl;
	fflush(stdin);
	
	cout<<"Inserire autore: ";
	getline(cin,libri[num-1].autore);
	filelibri<<libri[num-1].autore<<endl;
	fflush(stdin);
	
	cout<<"Inserire editore: ";
	getline(cin,libri[num-1].editore);
	filelibri<<libri[num-1].editore<<endl;
	fflush(stdin);
	
	num++;
	filelibri.close();
	
	return;
}

void StampaEditore(struct libro libri[], string editore, int num){
	for(int i=0;i<=num;i++){
		if(libri[i].editore==editore){
			cout<<libri[i].titolo<<endl;
		}
	}
	
	return;
}

void quicksort(struct libro v[],int sx, int dx){
	int s=sx, d=dx;
	string pivot=v[(sx+dx)/2].autore;
	string aux;
	
	while(s<=d){
		while(v[s].autore<pivot){
			s++;
		}
		while(v[d].autore>pivot){
			d--;
		}
		if(s<=d){
			aux=v[s].autore;
			v[s].autore=v[d].autore;
			v[d].autore=aux;
			aux=v[s].titolo;
			v[s].titolo=v[d].titolo;
			v[d].titolo=aux;
			aux=v[s].editore;
			v[s].editore=v[d].editore;
			v[d].editore=aux;
			s++;
			d--;
		}
	}
	if(sx<d){
		quicksort(v,sx,d);
	}

    if(s<dx){
        quicksort(v,s,dx);
    }	
	return;
}

void StampaAutore(struct libro libri[], int num){
	struct libro copia[100];
	
	for(int i=0;i<=num;i++){
		copia[i]=libri[i];
	}
	quicksort(copia,0,num-1);
	
	for(int i=0;i<=num;i++){
		cout<<copia[i].autore<<endl;
		cout<<copia[i].titolo<<" "<<copia[i].editore<<endl;
	}
	
	return;
}

int main(){
	struct libro libri[100];
	int num=1, scelta, i=0;
	string editore;
	fstream filelibri;

	
	filelibri.open("libri.txt",ios::in);
	
	if(!filelibri.fail()){
		num=0;
		cout<<"\nCaricamento dati da file in RAM";
		while(!filelibri.eof()){
			fflush(stdin);
			getline(filelibri,libri[i].num);
			getline(filelibri,libri[i].titolo);
			getline(filelibri,libri[i].autore);
			getline(filelibri,libri[i].editore);
			
			num++;
			i++;
		}
	}		
	filelibri.close();
	
	do{
		cout<<"\n1. Caricare dati\n2. Stampa libri di un editore\n3. Stampa libri in ordine di autore\n4. Uscita dal programma";
		do{
			cout<<"\n==> ";
			cin>>scelta;
			getline(cin,editore); //Usato per pulire il buffer
		}while((scelta<1)&&(scelta>4));
		
		switch(scelta){
			case 1: cout<<"\nCaricamento dati da file o tastiera";
					Input(libri,num);
					break;
			case 2: cout<<"\nStampa libri di un editore";
					cout<<"\nInserire editore: ";
					fflush(stdin);
					getline(cin,editore);
					StampaEditore(libri,editore,num);
					break;
			case 3: cout<<"\nStampa libri in ordine di autore"<<endl;
					StampaAutore(libri,num);
					break;				
		}
		cout<<endl;	
		
	}while(scelta!=4);
	
	return 0;
}
