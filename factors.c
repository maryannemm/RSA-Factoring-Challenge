#include <stdio.h>
#include <stdlib.h>

/* Function to factorize a number into two smaller numbers */
void factorize(int n) {
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            printf("%d=%d*%d\n", n, i, n / i);
            return;
        }
    }

    printf("%d=%d*%d\n", n, 1, n);
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

    int number;
    while (fscanf(file, "%d", &number) == 1) {
        factorize(number);
    }

    fclose(file);
    return EXIT_SUCCESS;
}

