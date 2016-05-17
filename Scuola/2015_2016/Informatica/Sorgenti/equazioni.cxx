#include <iostream>
#include <math.h>
using namespace std;

float equazione(float, float);

int main(){
	float a, b;
	cout<<"a => ";
	cin>>a;
	cout<<"b => ";
	cin>>b;
	
	cout<<"x: "<<equazione(a,b);
	
	return 1;
	}
	
float equazione(float c, float d){
	float x;
	x=-d/c;
	return x;
	}


#include <iostream>
#include <math.h>
using namespace std;

float equazionex1(float, float, float);
float equazionex2(float, float, float);

int main(){
	float a, b, c;
	cout<<"a => ";
	cin>>a;
	cout<<"b => ";
	cin>>b;
	cout<<"c => ";
	cin>>c;
	
	if(sqrt(pow(b,2)-4*a*c<=0)){
		cout<<"x1 e x2 valgono rispettivamente: "<<equazionex1(a,b,c)<<" "<<equazionex2(a,b,c);
		}
		else{
			cout<<"\nImpossibile in R";
			}
	
	return 1;
	}
	
float equazionex1(float c, float d, float e){
	float x1;
	
	if(sqrt(pow(d,2)-4*c*e<=0)){
		x1=(-d+sqrt(pow(d,2)-4*c*e))/2*c;
		}
		else{
			cout<<"\nImpossibile in R";
			}	
	return x1;
	}
	
float equazionex2(float c, float d, float e){
	float x2;
	
	if(sqrt(pow(d,2)-4*c*e<=0)){
		x2=(-d-sqrt(pow(d,2)-4*c*e))/2*c;
		}
	return x2;
	}	
