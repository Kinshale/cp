#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

// Declaring functions
int trova_massimo(int N, vector<int> V) {
    int max = V[0];
    for (auto elem : V)
        if (elem > max) max = elem;
    return max;
}

int main() {
    ios::sync_with_stdio(false);

    // Uncomment the following lines if you want to read/write from files
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int N;
    cin >> N;

    vector<int> V(N);
    for (int i = 0; i < N; i++) {
        cin >> V[i];
    }

    cout << trova_massimo(N, move(V)) << endl;

    return 0;
}
