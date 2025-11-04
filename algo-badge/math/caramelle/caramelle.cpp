// NOTA: si raccomanda di usare questo template anche se non lo si capisce completamente.
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) { return (a / gcd(a, b)) * b; }

int main() {
    // decommenta le due righe seguenti se vuoi leggere/scrivere da file
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        int N;
        cin >> N;

        vector<int> V(N);
        for (int i = 0; i < N; ++i) cin >> V[i];

        int c = 1;

        // INSERISCI IL TUO CODICE QUI
        for (int i = 0; i < N; ++i) c = lcm(V[i], c);

        cout << "Case #" << test << ": ";
        cout << c << endl;
    }

    return 0;
}
