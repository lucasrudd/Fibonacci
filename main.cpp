#include <iostream>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <string>
#include <math.h>
#include <gmp.h>

using namespace std;


///Constant global variable declarations
#define ZERO 0
#define ONE  1
#define SIZE 2


///Function declarations
void fib(mpz_t, mpz_t);


///Function definitions
void fib(mpz_t result, mpz_t n)
{
    /* The if and else-if statements are the base
     * cases. If n is equal to 0 then the result is
     * to be set to 0, and if n is equal to 1 then
     * the result is to be set to 1. From this we
     * can then calculate the rest of the Fibonacci
     * numbers recursively. */
    mpz_t i, prev, next;
    mpz_init_set_ui(prev, ONE); mpz_init_set_ui(next, ONE); mpz_init(i);

    for(mpz_add(i, i, n); mpz_cmp_ui(i, ZERO); mpz_sub_ui(i, i, ONE))
    {
        mpz_set(result, prev);
        mpz_set(prev, next);
        mpz_add(next, prev, result);
    }
    /*
    if(!mpz_cmp_ui(n, ZERO))
    {
        mpz_set_ui(result, ZERO);
    }
    else if(!mpz_cmp_ui(n, ONE))
    {
        mpz_set_ui(result, ONE);
    }

    else
    {
        mpz_t temp1, temp2;
        mpz_t fib1,  fib2;

        mpz_init(temp1); mpz_init(temp2);
        mpz_init(fib1);  mpz_init(fib2);

        mpz_sub_ui(temp1, n, 1);
        mpz_sub_ui(temp2, n, 2);

        fib(fib1, temp1);
        fib(fib2, temp2);

        mpz_add(result, fib1, fib2);

        //Failing to clear the initialized variables
        //will result in a memory leak.
        mpz_clear(temp1); mpz_clear(temp2);
        mpz_clear(fib1); mpz_clear(fib2);
    }*/

}


///Begin main function
int main()
{
    ofstream file;
    string input;
    mpz_t num, query;

    file.open("fibResults.txt");
    file.precision(10);
    mpz_init(num); mpz_init(query);

    for(double i = 0.0; i < 25.0; i++)
    {
        mpz_set_ui(query, pow(2.0, i));

        clock_t start = clock();
        fib(num, query);
        clock_t dif = clock() - start;

        double elapsed_ms = double((1000)*(dif)/CLOCKS_PER_SEC);
        file << "2^" << i << " : " << elapsed_ms << endl;


    }
    printf("Finished");
    file.close();
    mpz_clear(num); mpz_clear(query);
    return 0;
}

