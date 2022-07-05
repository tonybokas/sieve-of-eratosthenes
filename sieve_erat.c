/*
Program: sieve-ajb.c
Description: Finds all prime numbers below a limit and displays them in a table
Author: Antonios J. Bokas
*/

#include <stdio.h>

// Function prototypes
int set_limit(void);
void find_primes(int array[], size_t size);
void print_primes(int array[], size_t size);

// Function "main" begins program execution
int main(void) {

	// Describes program to user
	puts("\nSieve of Eratosthenes 1.0\nby Antonios J. Bokas\n\n----------------------------------------------------------\nThis program finds every prime number below a given limit.\n\nA prime number is \"a positive integer that is greater than\n1 and has itself and 1 as its only factors.\"\n\n\t       -American Heritage Desk Dictionary, 5th ed.\n----------------------------------------------------------\n");
	
	// Calls function "set_limit"
	size_t size = set_limit();
	
	// Declares array "numbers" and sets values to 1 to indicate index is a prime number
	int numbers[size];
	for (size_t index = 0; index < size; ++index) {
		numbers[index] = 1;
	}
	
	// Calls function "find_primes"
	find_primes(numbers, size);
	
	// Calls function "print_primes"
	print_primes(numbers, size);
}

// Function "set_limit" receives array size from user
int set_limit(void) {
	
	printf("%s", "Enter an upper limit: ");
	size_t limit;
	scanf("%d", &limit);
	puts("");
	return limit;
}

// Function "find_primes" changes index value to 0 if index is a composite number
void find_primes(int array[], size_t size) {
	
	// Loops through array starting at index 2
	for (size_t base = 2; base < size; ++base) {
		
		// Checks if "base" index has already been checked
		if (array[base] == 1) {
		
			// Loops through array starting at index 3
			for (size_t test = base + 1; test < size; ++test) {
				
				// Checks if "base" index is factor of "test" index, if yes, "test" value set to 0
				if (test % base == 0) {
					array[test] = 0;
				}
			}
		}
	}
}

// Function "print_primes" prints results in a table
void print_primes(int array[], size_t size) {
	
	printf("Prime numbers below %d...\n\n", size);	
	int primes_found = 0;
	
	// Cycles through array starting at index 2
	for (size_t index = 2; index < size; ++index) {
		
		// Prints index if index value is 1 (i.e., prime)
		if (array[index] == 1) {
			
			// Determines spacing based on array size
			if (size < 10001) {
				printf("%5zu", index);
			}
			else if (size < 100001) {
				printf("%6zu", index);
			}
			else {
				printf("%7zu", index);
			}
			
			// Tallies number of prime numbers found and columns
			++primes_found;
			
			// Adds a blank line after 10 columns
			if (primes_found % 10 == 0) {
				puts("");
			}
		}
	}
	
	// Prints total number of primes found
	printf("\n\nTotal: %d prime numbers\n", primes_found);
}