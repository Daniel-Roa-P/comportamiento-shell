#include <iostream>
#include <stdlib.h>   
#include <time.h>

using namespace std;
	
	int *a;		
	int N;
	struct timespec Inicio={0,0}, Final={0,0};
	
ordenshell (int *a, int N){

	int i,j,h;  
	int v;
	
	for(h=1; h<N/9; h= 3*h+1);
	
	for(; h>0; h/=3)
	for(i=h;i<N; i++){

		v=a[i]; 
		j=i;
    	while(j >= h && a[j-h] > v){
		
            a[j] = a[j-h]; j-=h;
    	}
    	
        a[j]=v;
	
	}
}

int main(){
	
	while(true){
	
		cout<<"Ingrese el tamaño del arreglo: ";
	
		cin>>N;
		
		cout<<endl;
		cout<<endl;
		
		a=new int[N];
	
		int j=N*50;
	
		for(int i=0 ; i<N; i++){
		
			a[i]=j;
			j=j-50;
		
		}
 	
    	clock_gettime(CLOCK_MONOTONIC, &Inicio);
    
    	ordenshell(a,N);
    
    	clock_gettime(CLOCK_MONOTONIC, &Final);
	
		
		for(int i=0 ; i<N; i++){
		
			cout<<a[i]<<", ";
		
		}
		
		cout<<endl;
		cout<<endl;
		
		printf(" El tiempo que ha tardado es: %.5f nanosegundos.\n",
          	((double)Final.tv_nsec) - 
          	((double)Inicio.tv_nsec));
		
		cout<<endl;
		cout<<endl;
		
		for(int i=0 ; i<N; i++){
		
			cout<<a[i]<<", ";
		
		}
		
				
		delete a;

		Inicio={0,0};
		Final={0,0};
		
		cout<<endl;
		cout<<endl;
		
	}
}

