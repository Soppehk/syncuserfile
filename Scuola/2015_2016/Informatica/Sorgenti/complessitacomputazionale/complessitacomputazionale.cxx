ls#include <iostream>
#include <stdlib.h>
#define DIM 100
using namespace std;

int quicksort(int v[],int sx, int dx){
	int s=sx, d=dx;
	int pivot=v[(sx+dx)/2];
	int aux;
	int contatoreqs=0;

	while(s<=d){
		while(v[s]<pivot){
			s++;
			contatoreqs++;
		}
		while(v[d]>pivot){
			d--;
			contatoreqs++;
		}
		if(s<=d){
			aux=v[s];
			v[s]=v[d];
			v[d]=aux;
			s++;
			d--;

			contatoreqs++;
		}
		contatoreqs++;
	}
	if(sx<d){
		quicksort(v,sx,d);

		contatoreqs++;
	}
	if(s<dx){
		quicksort(v,s,dx);

		contatoreqs++;
	}

	return contatoreqs;
}


int bubblesort(int v[]){
	int aux,sup,scambio;
	int contatorebs=0;
	sup=DIM;
	while(sup!=0){
		scambio=-1;
		for(int i=0;i<sup-1;i++){
			if(v[i]>v[i+1]){
				aux=v[i];
				v[i]=v[i+1];
				v[i+1]=aux;
				scambio=i;
				contatorebs++;
			}
		}
		sup=scambio+1;
		contatorebs++;
	}

	return contatorebs;
}


int ingenuo(int vett[]){
	int aux;
    int i, j;
    int contatorei=0;

    for(j=0;j<DIM-1;j++){
		for(i=j+1; i<DIM; i++){
            if(vett[j]>vett[i]){
                aux=vett[j];
                vett[j]=vett[i];
                vett[i]=aux;

                contatorei++;
            }
         }
     }

     return contatorei;
}

void Generazione(int v[]){
	srand((unsigned)time(NULL));
	for(int i=0;i<DIM;i++){
		v[i]=rand()%1000;
	}

	return;
}


int main(){
	int v[DIM], vettcp[DIM];

	Generazione(v);

	for(int i=0;i<DIM;i++){
		vettcp[i]=v[i];
	}


	cout<<"Il quicksort esegue "<<quicksort(vettcp, 0, DIM)<<" confronti";
	for(int k=0;k<DIM;k++){
		cout<<"\nN"<<k+1<<" "<<vettcp[k];
	}

	for(int i=0;i<DIM;i++){
		vettcp[i]=v[i];
	}

	cout<<"\nIl bubble sort esegue "<<bubblesort(vettcp)<<" confronti";
	for(int k=0;k<DIM;k++){
		cout<<"\nN"<<k+1<<" "<<vettcp[k];
	}

	for(int i=0;i<DIM;i++){
		vettcp[i]=v[i];
	}

	cout<<"\nL'ordinamento ingenuo esegue "<<ingenuo(vettcp)<<" confronti";
	for(int k=0;k<DIM;k++){
		cout<<"\nN"<<k+1<<" "<<vettcp[k];
	}


	return 0;
}




