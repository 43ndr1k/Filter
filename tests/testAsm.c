#include <stdio.h>

int test (int a, int b) {

  int arg1, arg2, add, sub, mul, quo, rem ;
	

	arg1 = a;
	arg2 = b;

    /* Perform Addition, Subtraction, Multiplication & Division */
    asm ( "addl %%ebx, %%eax;" : "=a" (add) : "a" (arg1) , "b" (arg2) );
    asm ( "subl %%ebx, %%eax;" : "=a" (sub) : "a" (arg1) , "b" (arg2) );
    asm ( "imull %%ebx, %%eax;" : "=a" (mul) : "a" (arg1) , "b" (arg2) );

    asm ( "movl $0x0, %%edx;"
              "movl %2, %%eax;"
              "movl %3, %%ebx;"
               //"idivl %%ebx;" 
               : "=a" (quo), "=d" (rem) 
               : "g" (arg1), "g" (arg2) );

    printf( "%d + %d = %d\n", arg1, arg2, add );
    printf( "%d - %d = %d\n", arg1, arg2, sub );
    printf( "%d * %d = %d\n", arg1, arg2, mul );
    printf( "%d / %d = %d\n", arg1, arg2, quo );
    printf( "%d %% %d = %d\n", arg1, arg2, rem );





return 0;	
}

int main() {

test(2,2);
  

    return 0 ;
}

