#include <iostream>
using namespace std;

int Input(int& n){
	do{
		cout<<"\n==>";
		cin>>n;
		}while(n<1);
	return n;	
	}
	
void MinMaxSomma(int& somma, int& min, int& max, int& posMax, int& posMin, float& media){
	int n, i, num;
	
	cout<<"\nInserire numero numeri che si vuole inserire";
	Input(n);
	for(i=1;i<=n;i++){
		cout<<"\nN"<<i;
		cout<<"\n==> ";
		cin>>num;
		somma=somma+num;
		if(num>max){
			max=num;
			posMax=i;
			}
		if(num<min){
			min=num;
			posMin=i;	
			}
		}
		media=somma/n;
	
	return;
	}	
	
int main(){
	int somma, min, max, posMin, posMax;
	float media;
	MinMaxSomma(somma, min, max, posMax, posMin, media);
	cout<<"\nLa somma dei numeri e' "<<somma;
	cout<<"\nIl numero maggiore immesso e' "<<max<<" in posizione "<<posMax;
	cout<<"\nIl numero minore immesso e' "<<min<<" in posizione "<<posMin;
	cout<<"\nLa media e' "<<media;
	
	return 1;
	}	
