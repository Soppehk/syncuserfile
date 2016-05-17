#include <iostream>
#include <fstream>
using namespace std;

void Init(string title){
	fstream index;

	index.open("index.html",ios::out);
	index<<"<!DOCTYPE html>\n<html lang=\"it\">\n<head>\n<title>"<<title<<"</title>\n</head>\n<body>\n";
	index.close();

	return;
}

void Tabella(){
	fstream index;
	string title;
	int colonne;
	int righe;
	string aux;

	index.open("index.html",ios::app);
	index<<"<table>\n";
	cout<<"\nInserire titolo tabella: ";
	getline(cin, title);
	index<<"<caption>"<<title<<"</caption>\n";
	cout<<"\nQuante colonne? ";
	cin>>colonne;
	cout<<"\nQuante righe? ";
	cin>>righe;
	cout<<endl;
	getline(cin,aux);
	index<<"<tfoot>\n";
	for(int i=0;i<righe;i++){
		index<<"<tr>\n";
		for(int j=0;j<colonne;j++){
			cout<<"Inserire contenuto riga"<<i+1<<" colonna"<<j+1<<" : ";
			getline(cin,aux);
			index<<"<th>"<<aux<<" </th>\n";
		}
		index<<"</tr>\n";
	}
	index<<"</tfoot>\n";
	index<<"</table>\n";

	index.close();

	return;
}


void Elenco(){
	fstream index;
	int n;
	string aux;

	index.open("index.html",ios::app);

	cout<<"\nQuanti punti deve avere l'elenco? ";
	cin>>n;
	getline(cin,aux);

	index<<"<ol>\n";
	for(int i=0;i<n;i++){
		cout<<"\nInserire contenuto punto"<<i+1<<" : ";
		getline(cin,aux);
		index<<"<li>"<<aux<<"</li>\n";
	}
	index<<"</ol>\n";

	index.close();
	return;
}

int main(){
	int scelta=0;
	fstream index;
	string title;

	cout<<"Programma per creare file html"<<endl;
	cout<<"Inserisci nome della pagina: ";
	getline(cin,title);
	Init(title);
	cout<<endl;

	cout<<"1.)Tabella\n2.)Elenco";
	do{
		cout<<"\n==> ";
		cin>>scelta;
	}while(scelta<1||scelta>2);

	switch(scelta){
		case 1: Tabella();
			  	break;
		case 2:	Elenco();
				break;	  
	}

	index.open("index.html",ios::app);
	index<<"\n</body>\n</html>";
	index.close();

	return 0;
}
