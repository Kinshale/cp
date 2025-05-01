#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve(int t) {
    int N, M, Q;
    cin >> N >> M >> Q;

    string S;
    cin >> S;

    // Aggiungi codice se vuoi
	vector<string> baskets(M);
	baskets[0] = S;

    string risposta;

    for (int i = 0; i < Q; i++) {
        char type;
        int a, b;
        cin >> type >> a >> b;

        if (type == 's') {
			char temp = baskets[a].back(); 
			baskets[a].pop_back();
			baskets[b].push_back(temp);
        } else {
            risposta.push_back(baskets[a][b]);
        }
    }

    cout << "Case #" << t << ": " << risposta << endl;
}

int main() {

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        solve(t);
    }

    return 0;
}
