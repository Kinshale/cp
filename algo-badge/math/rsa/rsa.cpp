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
