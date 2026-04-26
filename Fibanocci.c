AIM:To write a C program to find the nth Fibonacci number using recursion.
PROGRAM:
#include <stdio.h>

// Recursive function to find Fibonacci number
int fib(int n){  
    // Base case: fib(0) = 0
    if (n == 0){
        return 0;
    }

    // Base case: fib(1) = 1
    if (n == 1) {
        return 1;
    }

    // Recursive case
    return fib(n-1) + fib(n-2); 
}  

int main() {
    int n;

    // Input from user
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    // Check for invalid input
    if (n < 0){
        printf("Invalid number");
        return 0;
    }

    // Display nth Fibonacci number
    printf("Fibonacci term is: %d", fib(n));

    return 0;
}

OUTPUT:
Enter the number of terms: 11
Fibonacci term is: 89
