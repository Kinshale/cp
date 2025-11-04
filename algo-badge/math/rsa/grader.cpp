#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

static FILE *fr, *fw;

// Declaring variables
static int N;
static int d;
static int L;
static int* messaggio;
static char* plaintext;

int fast_pow(int b, int e, int N) {
    if (e == 0) return 1;
    long long half = fast_pow(b, e / 2, N);
    long long r = (half * half) % N;

    if (e % 2) {
        return (r * b) % N;
    } else {
        return r;
    }
}

void decifra(int N, int d, int L, int* messaggio, char* plaintext) {
    for (int i = 0; i < L; i++) plaintext[i] = (char)fast_pow(messaggio[i] % N, d, N);

    plaintext[L] = '\0';
}

int main() {
    fr = stdin;
    fw = stdout;

    // Iterators used in for loops
    int i0;

    // Reading input
    fscanf(fr, "%d %d %d", &N, &d, &L);
    messaggio = (int*)malloc(100 * sizeof(int));
    plaintext = (char*)malloc(110 * sizeof(char));
    for (i0 = 0; i0 < L; i0++) fscanf(fr, "%d", &messaggio[i0]);

    // Calling functions
    decifra(N, d, L, messaggio, plaintext);

    // Writing output
    fprintf(fw, "%s\n", plaintext);

    fclose(fr);
    fclose(fw);
    return 0;
}
