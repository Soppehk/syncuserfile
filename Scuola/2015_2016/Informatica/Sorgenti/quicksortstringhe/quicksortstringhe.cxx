#include <iostream>
#include <stdio.h>
#define DIM 5
using namespace std;

void quicksort(string v[],int sx, int dx){
	int s=sx, d=dx;
	string pivot=v[(sx+dx)/2];
	string aux;
	
	while(s<=d){
		while(v[s]<pivot){
			s++;
		}
		while(v[d]>pivot){
			d--;
		}
		if(s<=d){
			aux=v[s];
			v[s]=v[d];
			v[d]=aux;
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

int main(){
	string v[DIM];
	int sx=0, dx=DIM-1;
	
	for(int i=0;i<DIM;i++){
		cout<<"\nN"<<i+1<<" Inserisci stringa: ";
		fflush(stdin);
		getline(cin,v[i]);
	}
	
	quicksort(v,sx,dx);	
	
	for(int k=0;k<DIM;k++){
		cout<<"\nN"<<k+1<<" "<<v[k];
	}
	
	return 0;
}
