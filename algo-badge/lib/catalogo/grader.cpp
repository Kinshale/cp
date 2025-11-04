#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<long long int, int> catalogo;

void aggiungi(long long int id) { catalogo[id]++; }

// Decrement the count for a given ID (if it exists)
void togli(long long int id) {
    if (catalogo[id] > 0) {
        catalogo[id]--;
    }
}

// Get the count for a given ID (returns 0 if the ID doesn't exist)
int conta(long long int id) { return catalogo[id]; }
// Declaring functions
/*void aggiungi(long long int id){*/
/*	auto it = catalogo.find(id);*/
/*	if (it == catalogo.end()){*/
/*		catalogo[id] = 1;*/
/*	} else {*/
/*		it -> second += 1;*/
/*	}*/
/*}*/
/**/
/*void togli(long long int id){*/
/*    auto it = catalogo.find(id);*/
/*	it -> second -= 1;*/
/*}*/
/**/
/*int conta(long long int id){*/
/*    auto it = catalogo.find(id);*/
/*	if (it != catalogo.end()){*/
/*		return it -> second; */
/*	}*/
/**/
/*	return 0;*/
/*}*/

int main() {
    ios::sync_with_stdio(false);

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++) {
        char t;
        long long int id;
        cin >> t >> id;

        if (t == 'a') {
            aggiungi(id);
        } else if (t == 't') {
            togli(id);
        } else if (t == 'c') {
            cout << conta(id) << '\n';
        }
    }

    return 0;
}
