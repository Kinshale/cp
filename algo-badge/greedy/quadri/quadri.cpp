int quadri(int N, long long M, int V[]) {
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
