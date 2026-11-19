#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;

/*
SOLUTION

use a 2D prefix sum
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;
    vector<vector<int>> tree(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
        char x;
        cin >> x;
        if (x == '*') tree[i][j] = 1;
    }

    vector<vector<int>> ps(N + 1, vector<int>(N + 1, 0));
    for (int i = 1; i <= N; i++) for (int j = 0; j <= N; j++) {
        ps[i][j] = ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1] + tree[i - 1][j - 1];
    }

    while (Q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << ps[x2][y2] - ps[x1 - 1][y2] - ps[x2][y1 - 1] + ps[x1 - 1][y1 - 1] << endl;
    }

    return 0;
}