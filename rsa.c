#include <stdio.h>
#include <stdlib.h>

/* Function to calculate the greatest common divisor */
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

/* Function to perform Pollard's rho algorithm for prime factorization */
long long pollards_rho(long long n) {
    if (n % 2 == 0) {
        return 2;
    }

    long long x = rand() % (n - 2) + 2;
    long long y = x;
    long long d = 1;

    long long f(long long x) {
        return (x * x + 1) % n;
    }

    while (d == 1) {
        x = f(x);
        y = f(f(y));
        d = gcd(abs(x - y), n);
    }

    return d;
}

/* Function to find the prime factorization of n */
void prime_factorization(long long n) {
    if (n <= 1) {
        printf("%lld=%lld*%lld\n", n, n, (long long)1);
        return;
    }

    long long factor = pollards_rho(n);
    if (factor == n) {
        printf("%lld=%lld*%lld\n", n, n, (long long)1);
    } else {
        printf("%lld=%lld*%lld\n", n, factor, n / factor);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    long long number;
    while (fscanf(file, "%lld", &number) == 1) {
        prime_factorization(number);
    }

    fclose(file);
    return EXIT_SUCCESS;
}

