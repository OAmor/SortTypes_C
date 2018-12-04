#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

clock_t t1,t2;

void triGnome(int t[],int n){
	int z,j = 0;
	while(j<n){
		if(t[j] > t[j+1]){
			z = t[j+1];
			t[j+1] = t[j];
			t[j] = z;
			if(j == 0){ j++;}
			else {j--;} 
		}else{
			j++;
		}
	}
}

int* remplir(int* tab,int n){
	int i;
	for(i=0;i<n;i++){
		tab[i] = random()%n; 
	}
	return tab;
}

int main(){

	int n1 = 50000,n2 = 100000,n3 = 150000,n4 = 200000,n5 = 250000;

	int* tab1 = malloc(n1 * sizeof(int));
	int* tab2 = malloc(n2 * sizeof(int));
	int* tab3 = malloc(n3 * sizeof(int));
	int* tab4 = malloc(n4 * sizeof(int));
	int* tab5 = malloc(n5 * sizeof(int));


	printf("\n\n***************** TRI GNOME *****************\n");
	int k;
	for(k=1;k<=6;k++){
		printf("---- %i ----\n",k);
		
		switch(k){
		    case 1 : tab1 = remplir(tab1,n1);
			     t1 = clock();
			     triGnome(tab1,n1);	
			     break;
		    case 2 : tab2 = remplir(tab2,n2);
			     t1 = clock();
			     triGnome(tab2,n2);
			     break;
		    case 3 : tab3 = remplir(tab3,n3);
                             t1 = clock();
			     triGnome(tab3,n3);
			     break;
		    case 4 : tab4 = remplir(tab4,n4);
			     t1 = clock();
			     triGnome(tab4,n4);
			     break;
		    case 5 : tab5 = remplir(tab5,n5);
			     t1 = clock();
			     triGnome(tab5,n5);
			     break;
		   }

		t2 = clock();
		printf("tab[%d] = %f\n",k,((double)(t2-t1)/CLOCKS_PER_SEC ));
	
	}

	printf("\n");
	return -1;
}
