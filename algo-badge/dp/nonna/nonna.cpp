#include <assert.h>
#include <stdio.h>

#include <bitset>

// Maximum number of pizzas
#define MAXN 5000
// Maximum sum we want to find (starting point)
#define MAXK 5000
// Maximum sum we're looking for
#define MAXP 1000000

std::bitset<MAXP + 1> S;

int mangia(int N, int K, int P[]) {
    // Reset bitset and mark 0 as achievable
    S.reset();
    S[0] = 1;

    // Dynamic programming: for each pizza, update achievable sums
    for (int p = 0; p < N; p++) {
        // Iterate backwards to avoid using same pizza twice
        for (int s = K - 1; s >= 0; s--) {
            if (S[s]) S[s + P[p]] = 1;
        }
    }

    // Find the smallest sum >= K that is achievable
    for (int r = K; r <= MAXP; r++) {
        if (S[r]) return r;
    }

    return -1;
}

int P[MAXN];

int main() {
    FILE *fr, *fw;
    int N, K, i;

    // Open input and output files
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    
    // Read N (number of pizzas) and K (minimum sum)
    assert(2 == fscanf(fr, "%d %d", &N, &K));
    
    // Read N pizza sizes
    for (i = 0; i < N; i++) assert(1 == fscanf(fr, "%d", &P[i]));

    // Compute and write result
    fprintf(fw, "%d\n", mangia(N, K, P));
    
    // Clean up
    fclose(fr);
    fclose(fw);
    return 0;
}