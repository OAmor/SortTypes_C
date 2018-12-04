#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

clock_t t1,t2;

int* remplir(int* tab,int n){
	int i;
	for(i=0;i<n;i++){
		tab[i] = random()%n; 
	}
	return tab;
}


int max(int arr[], int n) 
{ 
	int mx = arr[0]; 
	for (int i = 1; i < n; i++) 
		if (arr[i] > mx) 
			mx = arr[i]; 
	return mx; 
} 


void TriAux(int arr[], int n, int exp) 
{ 
	int output[n]; 
	int i, count[10] = {0}; 

	// incrementer les cases concernées 
	for (i = 0; i < n; i++) 
		count[ (arr[i]/exp)%10 ]++; 

	// faire la somme des cases
	for (i = 1; i < 10; i++) 
		count[i] += count[i - 1]; 

	// creation du tableau en sortie
	for (i = n - 1; i >= 0; i--) 
	{ 
		output[count[ (arr[i]/exp)%10 ] - 1] = arr[i]; 
		count[ (arr[i]/exp)%10 ]--; 
	} 

	//recopie le resultat
	for (i = 0; i < n; i++) 
		arr[i] = output[i]; 
} 

void triBase(int arr[], int n) 
{ 
	int m = max(arr, n); 

	for (int exp = 1; m/exp > 0; exp *= 10) 
		TriAux(arr, n, exp); 
} 
 
void afficherRes(int arr[], int n) 
{ 
	for (int i = 0; i < n; i++) 
		printf("%i - ",arr[i]); 
} 

// Driver program to test above functions 
int main() 
{ 
	/*int arr[] = {170, 45, 75, 90, 802, 24, 2, 66}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	triBase(arr, n); 
	afficherRes(arr, n); */

	int n1 = 50000,n2 = 100000,n3 = 150000,n4 = 200000,n5 = 250000;

	int* tab1 = malloc(n1 * sizeof(int));
	int* tab2 = malloc(n2 * sizeof(int));
	int* tab3 = malloc(n3 * sizeof(int));
	int* tab4 = malloc(n4 * sizeof(int));
	int* tab5 = malloc(n5 * sizeof(int));


	printf("\n\n***************** TRI BASE *****************\n");
	int k;
	for(k=1;k<=6;k++){
		printf("---- %i ----\n",k);
		
		switch(k){
		    case 1 : tab1 = remplir(tab1,n1);
			     t1 = clock();
			     triBase(tab1,n1);	
			     break;
		    case 2 : tab2 = remplir(tab2,n2);
			     t1 = clock();
			     triBase(tab2,n2);
			     break;
		    case 3 : tab3 = remplir(tab3,n3);
                             t1 = clock();
			     triBase(tab3,n3);
			     break;
		    case 4 : tab4 = remplir(tab4,n4);
			     t1 = clock();
			     triBase(tab4,n4);
			     break;
		    case 5 : tab5 = remplir(tab5,n5);
			     t1 = clock();
			     triBase(tab5,n5);
			     break;
		   }

		t2 = clock();
		printf("tab[%d] = %f\n",k,((double)(t2-t1)/CLOCKS_PER_SEC ));
	
	}

	printf("\n");
	return 0; 
} 

