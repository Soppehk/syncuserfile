#include <iostream>
using namespace std;

int rp,ra,cp,ca,somma;

void ParteTavolaPitagorica(int rp,int ra,int cp,int ca,int somma){
	int n, c, r, i;
	do{
		cout<<"\nRiga di partenza: ";
		cin>>rp;
		cout<<"\nRiga di arrivo: ";
		cin>>ra;
		}while((rp>ra)||(rp<=0));
	do{
		cout<<"\nColonna di partenza: ";
		cin>>cp;
		cout<<"\nColonna di arrivo: ";
		cin>>ca;
		}while((cp>ca)||(cp<=0));
		r=rp;
		c=cp;
	
		do{
			do{
				n=r*(c+i);
				cout<<n<<"  ";
				somma=somma+n;
				i=i+1;
				}while(n!=(r*ca));
		i=0;
		c=cp;
		cout<<"\n";
		r=r+1;
		}while(n!=(ra*ca));
		cout<<"\nSomma: "<<somma;
	return;	
	}

int main(){
	ParteTavolaPitagorica(rp,ra,cp,ca,somma);
	return 1;
	}
