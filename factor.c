#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Function to find the gcd (greatest common divisor) of two numbers.
__uint128_t gcd(__uint128_t a, __uint128_t b) {
  while (b != 0) {  // Use iterative approach for clarity and stack safety.
    __uint128_t temp = b;
    b = a % b;
    a = temp;
  }
  return a;  // When b becomes 0, a is the GCD.
}

// Function to perform modular multiplication safely.
__uint128_t mod_mult(
    __uint128_t a, __uint128_t b,
    __uint128_t mod) {  // This function performs modular multiplication (𝑎*𝑏)
                        // % mod without risking overflow.
  __uint128_t result = 0;  // Initialize result to 0.
  a = a % mod;
  while (b > 0) {
    if (b % 2 == 1) {  // If b is odd, add 'a' to result.
      result = (result + a) % mod;
    }
    a = (a * 2) % mod;  // Double 'a' and halve 'b'.
    b /= 2;
  }
  return result;
}

// Function to convert a string to __uint128__ type.
__uint128_t convert(const char *str) {
  __uint128_t result = 0;  // Initialize the result to 0.
  while (*str) {  // Iterate through the string until the null terminator is
                  // encountered, which is the \0.
    result =
        result * 10 +
        (*str -
         '0');  // Update the result by shifting and adding the current digit
    str++;      // Move to the next character in the string.
  }
  return result;  // Return the final __uint128_t result.
}

// Function to print __uint128_t numbers.
void print_uint128(__uint128_t n) {
  if (n == 0) {  // If the number is 0, we print '0' and return immediately.
    putchar('0');
    return;
  }
  char
      buffer[40];  // Buffer to store the digits of the number in reverse order.
  int index = 0;   // Index to track the current position in the buffer.
  while (n > 0) {  // Loop to extract digits from the number and store them in
                   // reverse order.
    buffer[index++] =
        (n % 10) +
        '0';  // Extract the last digit and convert it to a character.
    n /= 10;  // Remove the last digit by dividing the number by 10.
  }
  while (index > 0) {  // Loop to print the digits from the buffer in reverse
                       // order (correct order).
    putchar(buffer[--index]);  // Print digits in reverse order to get the
                               // correct number.
  }
}

// Function to factorize using Pollard's Rho algorithm.
void factor(__uint128_t n) {
  for (__uint128_t c = 1; c < 100;
       c++) {  // Test constants from 1 to 99.This way we can loop through a
               // range of more constants of 'c' to increase the chance of
               // factorization.
    __uint128_t x = 2, y = 2, d = 1;
    while (d == 1) {  // Main Pollard's Rho loop: continues until a non-trivial
                      // factor is found (d != 1).
      x = (mod_mult(x, x, n) + c) %
          n;  // Update 'x' using the polynomial x = (x^2 + c) % n.
      y = (mod_mult(y, y, n) + c) % n;
      y = (mod_mult(y, y, n) + c) % n;
      d = gcd(x > y ? x - y : y - x,
              n);  // Ensure that x - y is always positive.
    }
    if (d != n) {             // We check if a factor has been found.
      __uint128_t k = n / d;  // We calculate the second factor k = n / d.
      printf("Factors: ");
      print_uint128(d);  // We print the first factor
      printf(" ");
      print_uint128(k);  // We print the second factor
      printf("\n");      // We change the line
      return;            // We exit the function after successful factorization.
    }
  }
  printf("Error: Failed to factorize\n");  // If no factors are found after
                                           // testing all constants, we print an
                                           // error message.
}

// The Main Function
int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: ./factor <semiprime>\n");  // We show the user how to
                                              // correctly use the program
    return 1;                                 // We exit with error code
  }
  __uint128_t n = convert(argv[1]);  // Convert input string to __uint128_t.
  if (n < 2) {
    printf("Error: Input must be greater than 1.\n");
    return 1;  // We exit with error code
  }
  factor(n);  // Factorize the given semiprime number.
  return 0;
}
