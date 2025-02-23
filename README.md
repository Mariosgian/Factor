# Title of the project: Factorization

## Description

<b>The program  efficiently factors semiprime numbers. Even though the problem of factoring semiprimes seems simple , because all we have to do is find two numbers that their product gives us the number we started with, no one has found so far an efficient solution to this problem. </b>
<br>

## How the program works

### <b> 1. Input </b>

The program expects two (2) arguments :

```c
./factor <semiprime>
```

<b> &#x2022;  " ./factor " : The compiled executable file <br>

 &#x2022; " semiprime" : A semiprime number  </b>

### 2. Main function

The main function checks whether exactly one command-line argument is provided.(input validation). If not, it prints the usage instructions :
```c
Usage: ./factor <semiprime>
```
and exits with an error code (1). It then converts the input string (a number provided as text) to a __uint128_t type using the convert function.This allows it to handle very large numbers (up to 128-bit unsigned integers). If the input number is less than 2, the program prints an error :
```c
Error: Input must be greater than 1.
```
and exitswith return code of 1.Finally it calls the factor function to attempt to factorize the given number n using Pollard's Rho algorithm. If factorization is successful, it prints the factors in the following format :
```c
Factors: <factor1> <factor2>
```
where 'factor1' and 'factor2' are the two factors.If factorization fails (after testing several constants), it prints:
```c
Error: Failed to factorize
```

### 3. The other functions 

#### a. gcd
 This function implements Euclid's algorithm to find the GCD of two numbers and is used to check if the public exponent (e) is coprime with phi(N).

 #### b. mod_mult
This function performs modular multiplication: (a*b) mod 'mod'(a variable), while avoiding overflow. It initializes result to 0, reduces a modulo mod and while b > 0, if b is odd, it adds 'a' to result and takes modulo mod.It then doubles the value of a (mod 'mod') and halves b. Finally it returns the result after the loop ends.This approach ensures safe multiplication without overflow for large values.

#### c. convert
 This function converts a string representation of a number to a __uint128_t type (128-bit unsigned integer). It initializes the result(a variable) to 0.
For each character in the string it subtracts '0' to get the digit value.It then multiplys the current result by 10 and adds the digit value.Finally it C
continues until the end of the string, and then returns the result.

#### d. print_uint128
Prints a __uint128_t number to the standard output. If n is 0, it prints 0 and returns.It then uses a buffer array to store digits in reverse order,it extracts digits using n % 10 and store them as characters.It divides n by 10 to remove the last digit and prints the digits in reverse order to display the number correctly.

#### e. factor
This function attempts to factorize a number n using [Pollard's Rho algorithm](https://en.wikipedia.org/wiki/Pollard%27s_rho_algorithm). If it works correctly it prints the two factors of the number. If not then it prints "Error: Failed to factorize".


### Each function works together to support the main program's goal of factorizing a large semiprime number.

## How to use

### <u> Running the program </u>

In order to run the program you have to compile it using the following command 

```c
gcc -O3 -Wall -Wextra -Werror -o factor factor.c -lm
```

### <u> Excecution </u>

To excecute the program and factor a semiprime number you can use it like this :

```c
./factor <semirpime>
```
# Examples

## Examples with wrong amount of arguments :

### 1. If the user doesn't give 2 arguments in the command line the program will print the following message :

```c
Usage: ./factor <semiprime>
```
### The program then ends with exit code of 1 , which we can check by using the following comand :

```c
$ echo $?
1
```

## Examples with small numbers :


### <b> A. </b> 

### Input :
```c
$ ./factor 93
```
### Output :
```c
Factors: 3 31
```
### Exit code :
```c
$ echo $?
0
```

### <b> B. </b>

### Input :
```c
$ ./factor 621
```
### Output :
```c
Factors: 3 207
```
### Exit code :
```c
$ echo $?
0
```

## Examples with big numbers :

### Input :
```c
$ ./factor 9827348119
```
### Output :
```c
Factors: 613 16031563
```
### Exit code :
```c
$ echo $?
0
```

## Examples with very big numbers :

### <b> A. </b>

### Input :
```c
$ ./factor 2524891914334062643
```
### Output :
```c
Factors: 1175747593 2147477851
```

### <b> B. </b>

### Input :
```c
$ ./factor 809724910412139638697047
```
### Output :
```c
Factors: 783108713587 1033987869581
```





