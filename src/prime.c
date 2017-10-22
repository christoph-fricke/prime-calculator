#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
struct node{ int value; struct node *following ;};
/* using a linked list, as this is the only way to have a data structure that can expand in c */
void print_primes(int max);
int is_prime(struct node *start, int number_to_test);

int main( int argc, char **args){
print_primes(atoi(args[1]));
return 0;
}

void print_primes(int max){
clock_t start, stop;
struct node begin;
struct node *last;// this node is always the latest addition to the linked list
last = &begin;
begin.value = 2; 
begin.following = NULL; // an empty pointer has to be NULL
for(int i = 3; i <= max; i++){ // starting at three, because the first node has value 2
	start = clock();
	if(is_prime(&begin,i)){ 
		stop = clock();
		printf("%d,%f\n",i, (stop-start)/(double)CLOCKS_PER_SEC);
		struct node *next = malloc(sizeof(struct node)); // allocating memory for the next node
		(*next).value = i;
		(*next).following = NULL;// an empty pointer has to be NULL
		(*last).following = next; 
		last = next; // assinging pointer last
	}
}
}

int is_prime(struct node *start, int number_to_test){
	for(struct node *next = start; (*next).value <= sqrt(number_to_test) && (*next).following != NULL; next = (*next).following){
		/*
		this loop is going through all primes discoverd so far
		it terminates either if the next prime to check is above the square root of the number that is going to be checked
		or if the last discovered prime has been reached.
		if one of the two above circumstances is reached, the number has to be prime
		*/
		if(number_to_test % (*next).value == 0){
			return 0;
		}
	} 
	return 1;
}

