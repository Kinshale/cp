#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

void solve(int t) {
	int N;
	cin >> N;
	string S;
	cin >> S;

	int r = 1;
	int a = -1;
	int b = -1;
	for (int i = 0; i < N; i++) {
		if (S[i] == '0') {
			r = std::max(r, i - a - 1);
			a = b;
			b = i;
		}
	}

	r = std::max(r, N - a - 1);

	cout << "Case #" << t << ": " << r << "\n";
}

int main() {

	/*freopen("input.txt", "r", stdin);*/
	/*freopen("output.txt", "w", stdout);*/

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		solve(t);
	}

	return 0;
}
