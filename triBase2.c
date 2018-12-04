#include <stdio.h>

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
	int arr[] = {170, 45, 75, 90, 802, 24, 2, 66}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	triBase(arr, n); 
	afficherRes(arr, n); 
	return 0; 
} 

