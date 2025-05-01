#include <vector>
using namespace std;

int trova_massimo(int N, vector<int> V) {
    int max = V[0];
    for (auto elem : V)
      if (elem > max)
            max = elem;
    return max;
}
