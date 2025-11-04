#include <iostream>

using namespace std;

long long removeMSB(long long num) {
    if (num == 0) return 0;

    long long msb = 1;
    while (msb <= num) msb <<= 1;

    msb >>= 1;

    return num - msb;
}

int main() {
    long long Q;
    cin >> Q;
    for (long long row = 1; row <= Q; row++) {
        long long N;
        cin >> N;

        long long r;
        r = (removeMSB(N) << 1) + 1;

        cout << r << endl;
    }
    return 0;
}
