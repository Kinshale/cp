// Il template è errato. N è di tipo long long int.
#include <assert.h>
#include <stdio.h>

double scosse(long long int N) { return N * (N - 1) / 4.0; }

int main() {
    FILE *fr, *fw;
    long long int N;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(fr != NULL && fw != NULL);
    assert(1 == fscanf(fr, "%lld", &N));

    fprintf(fw, "%.6f\n", scosse(N));

    fclose(fr);
    fclose(fw);
    return 0;
}
