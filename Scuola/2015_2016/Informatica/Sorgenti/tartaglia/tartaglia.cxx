#include <iostream>
#define DIM 20
using namespace std;

void Scelta(int &nrighe){
	do{
		cout<<"\nInserisci numero righe\n==> ";
		cin>>nrighe;
	}while((nrighe<1)||(nrighe>DIM));

	return;
}

void Inizializzazione(int vett1[], int vett2[]){
	for(int i=0;i<DIM;i++){
		vett1[i]=0;
		vett2[i]=0;
	}

	return;
}

void Tartaglia(int vett1[], int vett2[], int nrighe){
	int f;

	vett1[0]=1;
	vett2[0]=1;
	vett2[1]=1;

	for(int i=0;i<nrighe;i++){
		vett1[i]=1;
		vett2[i]=1;

		f=nrighe-i-1;
		do{
			cout<<" ";
			f--;
		}while(f>=0);

		for(int j=0;j<=i;j++){
			if(i%2==0){
				for(int k=j;k<j+1;k++){
					vett1[j+1]=vett2[k]+vett2[k+1];
				}
				vett1[i]=1;
				cout<<vett1[j]<<" ";
			}
			else{
				for(int k=j;k<j+1;k++){
					vett2[j+1]=vett1[k]+vett1[k+1];
				}
				vett2[i]=1;
				cout<<vett2[j]<<" ";
			}
		}
		cout<<"\n";
	}
	return;
}

int main(){
	int vett1[DIM], vett2[DIM], nrighe;

	Scelta(nrighe);
	//Inizializzazione(vett1,vett2);
	Tartaglia(vett1,vett2,nrighe);

	return 1;
}
