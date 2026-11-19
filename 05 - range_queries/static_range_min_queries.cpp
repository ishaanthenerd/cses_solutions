#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;

/*
SOLUTION

use a sparse table
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;
    vector<vector<int>> st(20, vector<int>(N, INT_MAX));
    for (int i = 0; i < N; i++) cin >> st[0][i];
    for (int lvl = 1; lvl < 20; lvl++) {
        for (int i = 0; i < N; i++) {
            if (i + (1 << lvl) <= N) {
                st[lvl][i] = min(st[lvl - 1][i], st[lvl - 1][i + (1 << (lvl - 1))]);
            }
            else break;
        }
    }

    while (Q--) {
        int A, B;
        cin >> A >> B;
        A--;
        B--;
        int lvl = (int)log2(B - A + 1);
        cout << min(st[lvl][A], st[lvl][B - (1 << lvl) + 1]) << endl;
    }

    return 0;
}