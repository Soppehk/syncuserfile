#include <iostream>
#include <math.h>
#include <string.h>
#include <stdio.h>
using namespace std;

void Input(int &bi, char n[], int &bf){
	cout<<"Inserisci base iniziale";
	do{
		cout<<"\n==> ";
		cin>>bi;
	}while(bi<0);
	cout<<"\nInserisci numero da convertire";
	cin>>n;	
	cout<<"\nInserisci base finale";
	do{
		cout<<"\n==> ";
		cin>>bf;
	}while(bf<0);
	
	return;
}

void BiToDec(int bi, char n[], int bf){
	int 
	
	return;
}

int main(){
	int bi,bf;
	char n[10];
	
	Input(bi,n,bf);
	
	return 0;
}
