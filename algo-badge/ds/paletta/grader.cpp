#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <vector>

static FILE *fr, *fw;

static int N;
static int *V;
static long long int numero_ribaltamenti;

long long mergeAndCount(std::vector<int> &arr, int l, int r, int mid) {
	long long inversions = 0;
	std::vector<int> temp(r - l + 1);
	int i = l, j = mid + 1, k = 0;

	while (i <= mid && j <= r) {
		if (arr[i] <= arr[j]) {
			temp[k++] = arr[i++];
		} else {
			temp[k++] = arr[j++];
			inversions += (mid - i + 1);
		}
	}

	while (i <= mid)
		temp[k++] = arr[i++];
	while (j <= r)
		temp[k++] = arr[j++];

	for (int i = 0; i < k; i++)
		arr[l + i] = temp[i];

	return inversions;
}

long long mergeSortAndCount(std::vector<int> &arr, int l, int r) {
	long long inversions = 0;
	if (l < r) {
		int mid = (l + r) / 2;
		inversions += mergeSortAndCount(arr, l, mid);
		inversions += mergeSortAndCount(arr, mid + 1, r);
		inversions += mergeAndCount(arr, l, r, mid);
	}

	return inversions;
}

long long int paletta_sort(int N, int *V) {

	std::vector<int> evens;
	std::vector<int> odds;

	for (int i = 0; i < N; i++) {
		if ((i & 1) != (V[i] & 1))
			return -1;
		i & 1 ? odds.push_back(V[i]) : evens.push_back(V[i]);
	}

	return mergeSortAndCount(evens, 0, (N + 1) / 2 - 1) +
		   mergeSortAndCount(odds, 0, N / 2 - 1);
}

int main() {
#ifdef EVAL
	fr = fopen("input.txt", "r");
	fw = fopen("output.txt", "w");
#else
	fr = stdin;
	fw = stdout;
#endif

	// Reading input
	fscanf(fr, "%d ", &N);
	V = (int *)malloc(N * sizeof(int));
	for (int i0 = 0; i0 < N; i0++) {
		fscanf(fr, "%d ", &V[i0]);
	}

	// Calling functions
	numero_ribaltamenti = paletta_sort(N, V);

	// Writing output
	fprintf(fw, "%lld\n", numero_ribaltamenti);

	fclose(fr);
	fclose(fw);
	return 0;
}
