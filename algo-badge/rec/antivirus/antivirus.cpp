#include <cstddef>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // decommenta le due righe seguenti se vuoi leggere/scrivere da file
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        int N1, N2, N3, N4;
        cin >> N1 >> N2 >> N3 >> N4;

        int M;
        cin >> M;

        string F1;
        cin >> F1;

        string F2;
        cin >> F2;

        string F3;
        cin >> F3;

        string F4;
        cin >> F4;

        int p1 = 0, p2 = 0, p3 = 0, p4 = 0;

        // INSERISCI IL TUO CODICE QUI
        vector<string> v;
        for (size_t i = 0; i <= N1 - M; i++) v.push_back(F1.substr(i, M));

        for (size_t i = 0; i <= N1 - M; i++) {
            auto &s = v[i];
            if (F2.find(s) != string::npos && F3.find(s) != string::npos && F4.find(s) != string::npos) {
                p1 = i;
                p2 = F2.find(s);
                p3 = F3.find(s);
                p4 = F4.find(s);
                break;
            }
        }

        cout << "Case #" << test << ": ";
        cout << p1 << " " << p2 << " " << p3 << " " << p4 << endl;
    }

    return 0;
}
