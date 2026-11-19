#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

/*
SOLUTION

use bfs to go thru the grid, make sure each spot is accessed once
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<pii> dir = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};
    vector<vector<int>> ans(N, vector<int>(N, INT_MAX));
    ans[0][0] = 0;
    queue<pii> q;
    q.push({0, 0});
    while (!q.empty()) {
        pii p = q.front();
        q.pop();
        for (pii d : dir) {
            pii new_p = {p.first + d.first, p.second + d.second};
            if (min(new_p.first, new_p.second) >= 0 && max(new_p.first, new_p.second) < N && ans[new_p.first][new_p.second] == INT_MAX) {
                ans[new_p.first][new_p.second] = 1 + ans[p.first][p.second];
                q.push(new_p);
            }
        }
    }
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cout << ans[i][j] << " \n"[j + 1 == N];

    return 0;
}