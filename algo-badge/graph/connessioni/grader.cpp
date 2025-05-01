#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// Using the Disjoint Set Union
vector<int> parent;
vector<int> rDSU;
int components;

void inizia(int N) {
	parent.resize(N);
	rDSU.resize(N, 0);
	components = N;

	for (int i = 0; i < N; i++)
		parent[i] = i;
}

int find(int X) {
	if (parent[X] != X)
		parent[X] = find(parent[X]); // Path compression
	return parent[X];
}

int collega(int X, int Y) {
	int pX = find(X);
	int pY = find(Y);

	if (pX != pY) {
		// Rank optimization
		if (rDSU[pX] > rDSU[pY]) {
			parent[pY] = pX;
		} else if (rDSU[pX] < rDSU[pY]) {
			parent[pX] = pY;
		} else {
			parent[pY] = pX;
			rDSU[pX]++;
		}
		components--;
	}

	return components;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, Q;
	cin >> N >> Q;

	inizia(N);

	for (int i = 0; i < Q; i++) {
		int X, Y;
		cin >> X >> Y;
		cout << collega(X, Y) << "\n";
	}
}
