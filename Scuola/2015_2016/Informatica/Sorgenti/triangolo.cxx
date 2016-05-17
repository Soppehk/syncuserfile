#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main(){
	double l1, l2, l3, perimetro, area, h;
	
	printf("Inserire il primo lato ");
	cin >> l1;
    printf("\nInserire il secondo lato ");
	cin >> l2;
	printf("\nInserire il terzo lato ");
	cin >> l3;
	
	perimetro = l1+l2+l3;
	printf("\nIl perimetro e' %f",perimetro);
	
	if(l1==l2 && l2==l3){
		h = sqrt(l2*l2-(l3/2)*(l3/2));
		area = (l2*h)/2;
		printf("\nL'area e' %f",area);		
	} else{
		if((l1==l2 && l3!=l2) || (l2==l3 && l1!=l2) || (l1==l3 && l2!=l1)){
			h = sqrt((l1==l2 || l2==l3)*(l1==l2 || l2==l3)-((l1<l2 || l2<l3)/2)*((l1<l2 || l2<l3)/2));
			area = (l1==l2 || l2==l3)*h/2;
			printf("\nL'area e' %f",area);
		} else{
			area = sqrt(perimetro/2*(perimetro/2-l1)*(perimetro/2-l2)*(perimetro/2-l3));
			printf("\nL'area e' %f",area);
		}
    }
    getchar();
    return 1;
}
