#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int numero_random;

void Nrandom1(){
	int x, y, max, min;
	srand((unsigned)time(NULL));
	x=rand()%100;
	y=rand()%21+10;
	if(x>=y){
		max=x;
		min=y;
		}
		else{
			max=y;
			min=x;
			}
	do{
	numero_random=rand()%(max-min);
	}while((numero_random<min)||(numero_random>max));
	cout<<"\nRange "<<min<<" e "<<max;
	return;		
	}


int main(){
	int tmax, i, n;
	
	do{
		cout<<"Inserisci numero tentativi: ";
		cin>>tmax;
		}while(tmax<=0);
	
	Nrandom1();
		
	for(i=1;i<=tmax;i++){
		cout<<"\n"<<i<<". Inserisci un numero: ";
		cin>>n;
		if(n==numero_random){
			cout<<"\nHai vinto!!!";
			return 1;
			}
			else{
				cout<<"\nNo";
				}
			}
	return 1;		
	}
