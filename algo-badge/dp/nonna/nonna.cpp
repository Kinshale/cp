#include <assert.h>
#include <bitset>
#include <stdio.h>

#define MAXN 5000
#define MAXK 5000
#define MAXP 1000000

std::bitset<MAXP + 1> S;

int mangia(int N, int K, int P[]) {
	S.reset();
	S[0] = 1;

	for (int p = 0; p < N; p++) {
		for (int s = K - 1; s >= 0; s--) {
			if (S[s])
				S[s + P[p]] = 1;
		}
	}

	for (int r = K; r <= MAXP; r++) {
		if (S[r])
			return r;
	}

	return -1;
}

int P[MAXN];

int main() {
	FILE *fr, *fw;
	int N, K, i;

	fr = fopen("input.txt", "r");
	fw = fopen("output.txt", "w");
	assert(2 == fscanf(fr, "%d %d", &N, &K));
	for (i = 0; i < N; i++)
		assert(1 == fscanf(fr, "%d", &P[i]));

	fprintf(fw, "%d\n", mangia(N, K, P));
	fclose(fr);
	fclose(fw);
	return 0;
}
