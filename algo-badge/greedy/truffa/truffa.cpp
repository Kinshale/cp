#include <algorithm>
#include <assert.h>
#include <stdio.h>

#define MAXN 100000

int sfangate(int N, int V[]) {
	int bilancio = 0;
	for (int i = 0; i < N; i++)
		bilancio += V[i];

	std::sort(V, V + N);

	int r = 0;
	while (bilancio <= 0)
		bilancio += -2 * V[r++];
	return r;
}

int V[MAXN];

int main() {
	FILE *fr, *fw;
	int N, i;

	fr = fopen("input.txt", "r");
	fw = fopen("output.txt", "w");
	assert(1 == fscanf(fr, "%d", &N));
	for (i = 0; i < N; i++)
		assert(1 == fscanf(fr, "%d", &V[i]));

	fprintf(fw, "%d\n", sfangate(N, V));
	fclose(fr);
	fclose(fw);
	return 0;
}
