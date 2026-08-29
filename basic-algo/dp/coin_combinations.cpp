// LINK: https://cses.fi/problemset/task/1634

// TITLE: Coin Combinations.

// Given a set of coin (e.g. {2, 3, 5}) and a desired sum, find how many distinct ways you can produce that sum with the avaible coins.

// IDEA: We have a dp array (count). Each cell i, tells us in how many ways we can produce the sum i.

#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;  // Often the numbers are so big that we are requested the modulo.

// {2, 2, 2, 5} is counted 3! times.
long long ordered_combinations(vector<int> coins, int n, int x) {
    vector<long long> count(x + 1, 0);

    count[0] = 1;
    for (int i = 0; i <= x; i++)
        for (auto c : coins)
            if (i - c >= 0) count[i] += count[i - c];

    return count[x];
}

// IDEA: For the undordered version we just invert the order of the two loops.
// {2, 2, 2, 5} counts as one.
long long unordered_combinations(vector<int> coins, int n, int x) {
    vector<long long> count(x + 1, 0);

    count[0] = 1;
    for (auto c : coins)
        for (int i = c; i <= x; i++) {
            count[i] += count[i - c];
            count[i] %= MOD;
        };

    return count[x];
}

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];

    cout << unordered_combinations(coins, n, x) << endl;

    return 0;
}
