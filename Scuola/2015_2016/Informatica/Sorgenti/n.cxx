#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    int n, i=0, c=0, d;
        
    for(d=0;d<10;d++){
	cout <<"==> ";
        cin >>n;
	if(n%2==0){
	    i++;
	    }
	    else{
		c++;
		}
	}
	cout <<"\nsomma numeri pari: "<<i;
	cout <<"\nsomma numeri dispari: "<<c;
	getchar();
	return 1;
    }
