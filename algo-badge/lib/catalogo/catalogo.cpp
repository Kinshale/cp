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
