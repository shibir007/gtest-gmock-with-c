#include "module_b.h"

/*
 * Returns total number of prime numbers
 * in the range [0 .. end_interval]
 *
 */

int module_a_func(int end_interval)
{
    int i, prime_count=0, is_prime;
    for (i=0; i<=end_interval; i++) {

        // module_b_func checks if an int is prime
        // returns -1 in case of failure
        
        is_prime = module_b_func(i);
        if (is_prime < 0) return -1;
        if (is_prime) prime_count++;
    }

    return prime_count;
}
