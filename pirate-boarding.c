#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

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

long int return_to ; 
long int there_be_pirates = 0 ;


// FIND THE PIRATE SECRET THAT ALLOWS Long John Von Neumann to board the ship!

#define PIRATE_SECRET 3


void caribbean_voyage() {
	long int i ;  // a place on the stack, for the pirate's hook!
	printf("\nAre there pirates?\n" ) ;
	
	if (there_be_pirates) {
		// the pirate places the pirate ship on the return statck
		*(&i+PIRATE_SECRET) = return_to ;
	}
	return ;
}

void pirate_ship() {
	printf("*** You have been boarded by pirate Long John von Neumann! ***\n\n") ;
	exit(0) ;
}

//void test_values(int secret) {
//    PIRATE_SECRET = secret;
//    there_be_pirates = 1;
//    caribbean_voyage();
//}

int main(int argc, char * argv[]) {

	// pirate programming. it is often the case that a function
	// the address of its entry point, and that addresses are simply
	// long ints.
	
	// this allows our program to be boarded by the 
	// infamous pirate long john von neumann. 
	
	// YOU HAVE TO CHANGE 0 TO THE PROPER FUNCTION
	return_to = (long int)pirate_ship;

	//for(int i = 0; i < 10; i++) {                      // Used this for loop to test possible values of PIRATE_SECRET
        //	printf("Testing PIRATE_SECRET value: %d\n", i);
        //	test_values(i);
    	//}

    	// If no values worked, this was printed
    	//printf("No values worked\n");

	caribbean_voyage() ;
	printf("There were no pirates.\n") ;
	
	there_be_pirates = 1 ;
	caribbean_voyage() ;
	
	// never get here
	assert(0==1) ;
	return 0 ;
}
