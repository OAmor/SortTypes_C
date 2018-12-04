#include <stdio.h>
#include <time.h>

int main(){

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

	int t[5] = {141,232,45,112,143};
	triGnome(t,5);
	int i;
	for(i=0;i<5;i++){
		printf("%i - ",t[i]);
	}

	
	return -1;
}
