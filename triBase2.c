#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

clock_t t1,t2;
int n1 = 50000,n2 = 100000,n3 = 150000,n4 = 200000,n5 = 250000;
void afficherRes(int arr[], int n) 
{ 
	for (int i = 0; i < n; i++) 
		printf("%i - ",arr[i]); 
} 
void permuter(int *a,int *b){
    int tmp = *a;
    *a=*b;
    *b=tmp;
}
int* remplir(int* tab,int n){
	int i;
	for(i=0;i<n;i++){
		tab[i] = random()%n; 
	}
	return tab;
}

int getSizeByIndicator(int i){
	switch(i){
		case 1 : return n1;
		case 2 : return n2;
		case 3 : return n3;
		case 4 : return n4;
		case 5 : return n5;
	}
}
/***************** TRI BASE *****************/
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
 

 /***************** END TRI BASE *****************/

/***************** TRI BULLE *****************/
void TriBulle(int *T,int n){
    int changement = 1;
    int i;
    while (changement == 1) {
        changement = 0 ;
        for(i=0; i<=n-1;i++){
            if(*(T+i) > *(T+i+1)){
                permuter(&(T[i]),&(T[i+1]));
                changement = 1;
            }
        }
    }
}

void TriBulleOpt(int *T,int n){
     int m = n-1;
     int i;
     int changement = 1;
     while (changement == 1) {
        changement = 0 ;
        for(i=0; i<=m;i++){
            if(*(T+i) > *(T+i+1)){
               permuter(&(T[i]),&(T[i+1]));
                changement = 1;
            }
        }
        m=m-1;
    }
}

/***************** END TRI BULLE *****************/

/*****************  TRI GNOME *****************/
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

/***************** END TRI GNOME *****************/


/***************** TRI RAPIDE *****************/

int partitionner(int *tab,int d,int f){
    int eltPivot;//on considère que tab est un tableau d'entiers
    int i, j, x ;
    eltPivot = *(tab+f);
    i = d;j = f;
    do{
        while(i<f && *(tab+i)<= eltPivot) {i++ ;}
        while(j>d && *(tab+j)> eltPivot) {j--;}
        if (i<j) { x = *(tab+j) ; *(tab+j) = *(tab+i) ; *(tab+i) = x;j--;i++;}
    }while (j>i);
    return i ;
}
void triRapide(int *tab,int p,int r){
    int q;
    if (p<r) {
        q = partitionner(tab, p, r);
        triRapide(tab, p, q-1);
        triRapide(tab, q+1, r);
    }
}


/***************** END TRI RAPIDE *****************/


/***************** TRI PAR TAS *****************/
void heapify(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2*i + 1; // left = 2*i + 1
    int r = 2*i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i)
    {
        permuter(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}
/***************** END TRI PAR TAS *****************/
// main function to do heap sort
void triTas(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i=n-1; i>=0; i--)
    {
        permuter(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}
// Driver program to test above functions 

int printMenuAndGetUserChoice(){
	system("clear");
	printf("\t\tMenu\n\n");
	printf("\t1 - Tri Bulle\n");
	printf("\t2 - Tri Bulle Optimal\n");
	printf("\t3 - Tri Gnome\n");
	printf("\t4 - Tri Bas\n");
	printf("\t5 - Tri Rapide\n");
	printf("\t6 - Tri Tas\n");
	printf("\t0 - Quitter\n");
	int choice;
	do{
		printf("[0-6] : ");
		scanf("%d",&choice);
	}while(choice <0 || choice >6);
}
int main() 
{ 

	int* tab1 = malloc(n1 * sizeof(int));
	int* tab2 = malloc(n2 * sizeof(int));
	int* tab3 = malloc(n3 * sizeof(int));
	int* tab4 = malloc(n4 * sizeof(int));
	int* tab5 = malloc(n5 * sizeof(int));



	int k;
	while(1){
		int userChoice = printMenuAndGetUserChoice();
		switch(userChoice) {
			case 0 : exit(0); break;
			case 1 :
					printf("\n\n***************** TRI BULLE *****************\n");
					for(k=1;k<6;k++){
						printf("---- %i ----\n",k);
						
						switch(k){
						    case 1 : tab1 = remplir(tab1,n1);
							     t1 = clock();
							     TriBulle(tab1,n1);	
							     break;
						    case 2 : tab2 = remplir(tab2,n2);
							     t1 = clock();
							     TriBulle(tab2,n2);
							     break;
						    case 3 : tab3 = remplir(tab3,n3);
				                             t1 = clock();
							     TriBulle(tab3,n3);
							     break;
						    case 4 : tab4 = remplir(tab4,n4);
							     t1 = clock();
							     TriBulle(tab4,n4);
							     break;
						    case 5 : tab5 = remplir(tab5,n5);
							     t1 = clock();
							     TriBulle(tab5,n5);
							     break;
						   }

						t2 = clock();
						printf("tab[%d] = %f,\n",getSizeByIndicator(k),((double)(t2-t1)/CLOCKS_PER_SEC ));
					}
					/************************* END TRI BULLE ***************/
				break;

			case 2 : 

				printf("\n\n***************** TRI BULLE OPT *****************\n");
				for(k=1;k<6;k++){
					printf("---- %i ----\n",k);
					
					switch(k){
					    case 1 : tab1 = remplir(tab1,n1);
						     t1 = clock();
						     TriBulleOpt(tab1,n1);	
						     break;
					    case 2 : tab2 = remplir(tab2,n2);
						     t1 = clock();
						     TriBulleOpt(tab2,n2);
						     break;
					    case 3 : tab3 = remplir(tab3,n3);
			                             t1 = clock();
						     TriBulleOpt(tab3,n3);
						     break;
					    case 4 : tab4 = remplir(tab4,n4);
						     t1 = clock();
						     TriBulleOpt(tab4,n4);
						     break;
					    case 5 : tab5 = remplir(tab5,n5);
						     t1 = clock();
						     TriBulleOpt(tab5,n5);
						     break;
					   }

					t2 = clock();
					printf("tab[%d] = %f,\n",getSizeByIndicator(k),((double)(t2-t1)/CLOCKS_PER_SEC ));
				}

				/************************* END TRI BULLE OPT ***************/
					break;

			case 3 : 

					printf("\n\n***************** TRI GNOME *****************\n");
				for(k=1;k<6;k++){
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
					printf("tab[%d] = %f,\n",getSizeByIndicator(k),((double)(t2-t1)/CLOCKS_PER_SEC ));
				
				}

				/************************* END TRI BULLE OPT ***************/

				break;

			case 4 : 
					printf("\n\n***************** TRI BASE *****************\n");
					for(k=1;k<6;k++){
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
						printf("tab[%d] = %f,\n",getSizeByIndicator(k),((double)(t2-t1)/CLOCKS_PER_SEC ));

			
		
		}
		/************************* END TRI BAS ***************/
			break;

			case 5 : 
				printf("\n\n***************** TRI RAPIDE *****************\n");
				for(k=1;k<6;k++){
					printf("---- %i ----\n",k);
					
					switch(k){
					    case 1 : tab1 = remplir(tab1,n1);
						     t1 = clock();
						     triRapide(tab1,0,n1);	
						     break;
					    case 2 : tab2 = remplir(tab2,n2);
						     t1 = clock();
						     triRapide(tab2,0,n2);
						     break;
					    case 3 : tab3 = remplir(tab3,n3);
			                             t1 = clock();
						     triRapide(tab3,0,n3);
						     break;
					    case 4 : tab4 = remplir(tab4,n4);
						     t1 = clock();
						     triRapide(tab4,0,n4);
						     break;
					    case 5 : tab5 = remplir(tab5,n5);
						     t1 = clock();
						     triRapide(tab5,0,n5);
						     break;
					   }

					t2 = clock();
					printf("tab[%d] = %f,\n",getSizeByIndicator(k),((double)(t2-t1)/CLOCKS_PER_SEC ));

			
		
		}
		/************************* END TRI RAPIDE ***************/

			break;

			case 6 : 

			printf("\n\n***************** TRI PAR TAS *****************\n");
				for(k=1;k<6;k++){
					printf("---- %i ----\n",k);
					
					switch(k){
					    case 1 : tab1 = remplir(tab1,n1);
						     t1 = clock();
						     triTas(tab1,n1);	
						     break;
					    case 2 : tab2 = remplir(tab2,n2);
						     t1 = clock();
						     triTas(tab2,n2);
						     break;
					    case 3 : tab3 = remplir(tab3,n3);
			                             t1 = clock();
						     triTas(tab3,n3);
						     break;
					    case 4 : tab4 = remplir(tab4,n4);
						     t1 = clock();
						     triTas(tab4,n4);
						     break;
					    case 5 : tab5 = remplir(tab5,n5);
						     t1 = clock();
						     triTas(tab5,n5);
						     break;
					   }

					t2 = clock();
					printf("tab[%d] = %f,\n",getSizeByIndicator(k),((double)(t2-t1)/CLOCKS_PER_SEC ));

					
				
				}
		/************************* END TRI PAR TAS ***************/

		break;
		}// end main switch
		printf("Press ENTER key to Continue\n");  
		getchar();
		int c = getchar();
	}

	printf("\n");
	return 0; 
} 

