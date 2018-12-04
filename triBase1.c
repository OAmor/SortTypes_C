#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

clock_t t1,t2;

int main(){
	
	int cle(int val,int x){
		int i,ch = 1;
		for(i=0;i<x;i++){ch=ch*10;}
		return (val%(ch*10))/ch;
	}

	void triAux(int t[],int n,int i){
		int z,j = 0;
		while(j<n){
			printf("compare %i with %i\n",cle(t[j],i), cle(t[j+1],i));
			if(cle(t[j],i) > cle(t[j+1],i)){
				z = t[j+1];
				t[j+1] = t[j];
				t[j] = z;
				if(j == 0){ j++;}
				else {j--;printf("j--");} 
			}else{
				j++;
			}
		}
	}
	
	void triBase(int t[],int n,int k){
		int j,i;
		for(i=0;i<=k;i++){
			triAux(t,n,i);		
			printf("\n--- %i ---\n",i);
			for(j=0;j<5;j++){
				printf("%i - ",t[j]);
			}		
		}
		
	}


	int t[5] = {141,232,45,112,143};
	triBase(t,4,2);
	int i;
	for(i=0;i<5;i++){
		printf("%i - ",t[i]);
	}

	
	return -1;
}
