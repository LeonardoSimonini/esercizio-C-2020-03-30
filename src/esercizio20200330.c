#include <stdio.h>
#include <stdlib.h>

#define N 39

unsigned long fibonacci(unsigned int n);
unsigned long * fibonacci_array(unsigned int n);
unsigned long * reverse_array(unsigned long * array, unsigned int length);
void bubble_sort(unsigned long * array, int array_dimension);
void print_array(unsigned long * array, int length);

int main(int argc, char *argv[]) {

	int equals = 1;

	printf("Array fibonacci:");

	unsigned long * fibonacci_result = fibonacci_array(N);
	print_array(fibonacci_result, N+1);

	unsigned long * fibonacci_result_copy = calloc(N+1, sizeof(long));
	if (fibonacci_result_copy == NULL) {
		perror("calloc error");
		exit(EXIT_FAILURE);
	}

	for(int i = 0; i < N+1; i++){
		fibonacci_result_copy[i] = fibonacci_result[i];
	}

	printf("\nL'array copia e' il seguente:");
	print_array(fibonacci_result_copy, N+1);

	reverse_array(fibonacci_result_copy, N+1); //sizeof(fibonacci_result_copy)/sizeof(long));
	printf("\nL'array copia ribaltato e' il seguente:");
	print_array(fibonacci_result_copy, N+1);

	bubble_sort(fibonacci_result_copy, N+1);
	printf("\nL'array copia ribaltato e poi riordinato e' il seguente:");
	print_array(fibonacci_result_copy, N+1);



	for(int i = 0; i < sizeof(fibonacci_result)/sizeof(long); i++){
		if(fibonacci_result[i] != fibonacci_result_copy[i]){
			equals = 0;
		}
	}

	if(equals){
		printf("\nI due array sono uguali\n");
	}
	else{
		printf("\nI due array sono diversi\n");
	}

}


unsigned long fibonacci(unsigned int n){

	unsigned long result = 0;

	if(n == 0){
		return 0;
	}

	if(n == 1){
		return 1;
	}

	result = fibonacci(n-1) + fibonacci(n-2);

	return result;
}

unsigned long * fibonacci_array(unsigned int n){
	unsigned long * result = calloc(n+1, sizeof(long));

	if (result == NULL) {
		perror("calloc error");
		exit(EXIT_FAILURE);
	}


	for(int i = 0; i < n+1; i++){
		result[i] = fibonacci(i);
	}

	return result;
}



unsigned long * reverse_array(unsigned long * array, unsigned int length)
{
	int i = 0;
	unsigned long buff = 0;
	while(i < length){
		length--;
		buff = array[length];
		array[length] = array[i];
		array[i] = buff;
		i++;
	}

	return array;
}


void bubble_sort(unsigned long * array, int array_dimension) {
	int swapped = 1;
	unsigned long buff = 0;
	while(swapped){
	  swapped = 0;
	  for(int i = 0; i < array_dimension-1; i++){
	     if(array[i] > array[i+1]){
	    	buff = array[i];
	   		array[i] = array[i+1];
	 		array[i+1] = buff;
	       swapped = 1;
	     }
	  }
	}
	return;
}

void print_array(unsigned long * array, int length){
	printf("\n{");

	for(int i = 0; i < length; i++){
		printf(" %lu ", array[i]);
	}

	printf("}\n");

	return;
}

