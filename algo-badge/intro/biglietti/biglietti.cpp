#include <assert.h>
#include <stdio.h>

#include <algorithm>

using namespace std;

int compra(int N, int M, int A, int B) {
    int r;
    if (A * M <= B) r = A * N;
    else r = (N / M) * B + min((N % M) * A, B);

    return r;
}

int main() {
    FILE *fr, *fw;
    int N, M, A, B;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");

    assert(4 == fscanf(fr, "%d%d%d%d", &N, &M, &A, &B));

    fprintf(fw, "%d\n", compra(N, M, A, B));
    fclose(fr);
    fclose(fw);
    return 0;
}
