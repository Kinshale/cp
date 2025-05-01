#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int main() {
	// decommenta le due righe seguenti se vuoi leggere/scrivere da file
	// ifstream cin("input.txt");
	// ofstream cout("output.txt");

	int T;
	cin >> T;
	for (int test = 1; test <= T; ++test) {
		long long N, M, K;
		cin >> N >> M >> K;

		long long r;

		if (N < M)
			swap(N, M);

		if (K <= N - M) {
			r = (N - K) * M;
		} else {
			K -= N - M;
			r = (M - K / 2) * (M - (K + 1) / 2);
		}

		cout << "Case #" << test << ": ";
		cout << r << endl;
	}

	return 0;
}
