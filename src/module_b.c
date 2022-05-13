#include <stdio.h>

/*
 * Function checks if an integer is Prime
 * Returns: 0 if not-prime
 *          1 if prime
 */

int module_b_func(int n)
{
      if(n==1||n==0) return false;
   
      for(int i=2; i<n; i++){
        if(n%i==0) return false;
      }

      return true;
}
