#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

void InputMessaggio(char stringa[]){
	for(int i=0;i<100;i++){
		stringa[i]=' ';
	}
	cout<<"Scrivi il messaggio(MAX 100 caratteri): ";
	fgets(stringa,100,stdin);
	
	return;	
}

int InputKey(){
	int key=0;
	
	cout<<"\nInserire chiave\n==> ";
	cin>>key;
	
	return key;
}

void Codifica(char stringa[]){
	int key=InputKey();
	for(unsigned int i=0;i<strlen(stringa);i++){
		stringa[i]=stringa[i]+key;
	}
	cout<<"\nMessaggio criptato: "<<stringa;
	
	return;
}

void Decodifica(char stringa[]){
	int key=InputKey();
	for(unsigned int i=0;i<strlen(stringa);i++){
		stringa[i]=stringa[i]-key;
	}
	cout<<"\nMessaggio decriptato: "<<stringa;
	
	return;	
}

int main(){
	int scelta;
	char stringa[100];
	
	cout<<"CIFRARIO DI CESARE\n";
	scelta=0;
	InputMessaggio(stringa);
		
	do{
	cout<<"\n1)Codificare un messaggio usando una chiave di criptazione.";
	cout<<"\n2)Decodificare un messaggio usando una chiave di decriptazione.";
	cout<<"\n==> ";
	cin>>scelta;
	}while((scelta<1)&&(scelta>2));
	
	switch(scelta){
		case 1: cout<<"\nCodifica del messaggio";
				Codifica(stringa);
				break;
		case 2: cout<<"\nDecodifica del messaggio";
				Decodifica(stringa);
				break;
		}
		
	return 1;
}
