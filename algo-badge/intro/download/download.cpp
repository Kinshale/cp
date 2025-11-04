#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        int N, F, C;
        cin >> N >> F >> C;

        int nf = 0, nc = 0;

        // INSERISCI IL TUO CODICE QUI
        nf = N / F;
        nc = (N % F) / C;

        cout << "Case #" << test << ": ";
        cout << nf << " " << nc << endl;
    }

    return 0;
}
