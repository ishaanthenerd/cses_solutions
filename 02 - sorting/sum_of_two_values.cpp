#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

/*
SOLUTION

use a map from value to index and win
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, X;
    cin >> N >> X;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    map<int, int> val_to_idx;
    for (int i = 0; i < N; i++) {
        if (val_to_idx.count(X - A[i])) {
            cout << val_to_idx[X - A[i]] + 1 << " " << i + 1 << endl;
            return 0;
        }
        val_to_idx[A[i]] = i;
    }
    cout << "IMPOSSIBLE\n";

    return 0;
}