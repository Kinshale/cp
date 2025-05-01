#include <iostream>
#include <cassert>
#include <utility>
#include <vector>
#include <set>

using namespace std;

set<long long> autogrill;

void inizia(){
	autogrill.clear();
}

void apri(long long p){
    autogrill.insert(p);
}

void chiudi(long long p){
    autogrill.erase(p);
}

long long chiedi(long long p){
	if (autogrill.size() == 0)
		return -1;

	long long r;
    auto it = autogrill.lower_bound(p);
    if (it == autogrill.begin()){
		r = *it;
	} else if (it == autogrill.end()) {
		r = *(--it);
	} else {
		long long a = *it;
		long long b = *(--it);
		r = (a - p <= p - b ? a : b);
	}
	return r; 
}

int main() {
    int Q;
    cin >> Q;

    inizia();

    for (int i = 0; i < Q; i++){
        long long p;
        char t;
        cin >> t >> p;
        if (t == 'a') apri(p);
        else if (t == 'c') chiudi(p);
        else cout << chiedi(p) << endl;
    }

    return 0;
}
