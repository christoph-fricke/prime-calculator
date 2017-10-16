#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
struct node{ int value; struct node *following ;};
void print_primes(int max);
int is_prime(struct node *start, int number_to_test);
int main( int argc, char **args){
print_primes(atoi(args[1]));
return 0;
}
void print_primes(int max){
clock_t start, stop;
struct node begin;
struct node *last;
last = &begin;
begin.value = 2; 
begin.following = NULL;
for(int i = 3; i <= max; i++){
	start = clock();
	if(is_prime(&begin,i)){
		stop = clock();
		printf("%d,%f\n",i, (stop-start)/(double)CLOCKS_PER_SEC);
		struct node *next = malloc(sizeof(struct node));
		(*next).value = i;
		(*next).following = NULL;
		(*last).following = next;
		last = next;	
	}
}
}

int is_prime(struct node *start, int number_to_test){
	for(struct node *next = start; (*next).value <= sqrt(number_to_test) && (*next).following != NULL; next = (*next).following){
		if(number_to_test % (*next).value == 0){
			return 0;
		}
	} 
	return 1;
}

