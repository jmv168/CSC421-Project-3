#include<stdio.h>
#include<stdlib.h>

/*
 * long john von neumann hooks the stack
 * author: 
 * last-update:
 *
 * NOTICE - THESE ARE PIRATE TECHINQUES! This code is most likely not portable
 * across operating systems or machine architectures.
 *
 */

// pirates also like globals

char ** location ;
int there_be_pirates = 0 ;

// FIND THE PIRATE SECRET THAT ALLOWS Long John Von Neumann to print There Be Pirates!!

#define PIRATE_SECRET 0

void pirate_boarding(void) {
	int stack_marker ;
	char * ip = (char *) &stack_marker ;
    *(ip+PIRATE_SECRET) = "*** There be pirates! ***" ;	
	return ;
}

void print_it(char * string_pointer_on_stack) {

	// YOU HAVE TO CHANGE 0 TO & OF THE PROPER VARIABLE
	location = 0 ;
	
	if (there_be_pirates) {
		pirate_boarding() ;
	}
	printf("%s\n", string_pointer_on_stack) ;
	return ;
}

int main(int argc, char * argv[]) {
	printf("Are there pirates in these cyberwaters?\n") ;
	print_it("No, there are no pirates.\n" ) ;
	there_be_pirates = 1 ;
	printf("Are there pirates in these cyberwaters?\n") ;
	print_it("No, there are no pirates.\n" ) ;
	return 0 ;
}

