#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

static FILE *fr, *fw;

// Declaring variables
static int N;
static long long M;
static int *V;
static int B;

// Declaring functions
int quadri(int N, long long M, int *V) {
    int r;
    long long sum = 0;
    int i = 0, j = 0;

    while (i < N && sum + V[i] <= M) sum += V[i++];

    r = i;

    while (i < N && r != 0) {
        sum = sum + V[i++] - V[j++];

        while (sum > M && j != i) {
            sum -= V[j++];
            r--;
        }
    }
    return r;
}

int main() {
    fr = stdin;
    fw = stdout;

    // Iterators used in for loops
    int i0;

    // Reading input
    fscanf(fr, "%d %lld", &N, &M);
    V = (int *)malloc(N * sizeof(int));
    for (i0 = 0; i0 < N; i0++) {
        fscanf(fr, "%d", &V[i0]);
    }

    // Calling functions
    B = quadri(N, M, V);

    // Writing output
    fprintf(fw, "%d\n", B);

    fclose(fr);
    fclose(fw);
    return 0;
}
