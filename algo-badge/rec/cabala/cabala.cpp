#include <assert.h>
#include <stdio.h>

#include <iostream>

void cabala(long long a, long long N, int M, int cifra, int &max) {
    if (max == M - 1 || cifra == N + 1) return;

    if (a % M > max) max = a % M;

    for (int i = 3; i < 10; i += 3) {
        if (a % 10 != i) cabala(a * 10 + i, N, M, cifra + 1, max);
    }
}

long long occulta(long long N, int M) {
    int max = -1;
    cabala(0, N, M, 0, max);
    return max;
}

int main() {
    FILE *fr, *fw;
    int T, M, i;
    long long N;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &T));
    for (i = 0; i < T; i++) {
        assert(2 == fscanf(fr, "%lld %d", &N, &M));
        fprintf(fw, "%lld ", occulta(N, M));
    }

    fprintf(fw, "\n");
    fclose(fr);
    fclose(fw);
    return 0;
}
