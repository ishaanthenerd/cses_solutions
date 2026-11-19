#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
constexpr ll MOD = 1e9 + 7;

/*
SOLUTION

use 2D dp; at any given point, you can either get your best answer from going up, left, or up-left (+1 char)
compute best answer and store previous directions at each step, then work backwards from the end to generate the actual subsequence 
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    vector<int> A(N + 1), B(M + 1);
    for (int i = 1; i <= N; i++) cin >> A[i];
    for (int i = 1; i <= M; i++) cin >> B[i];

    vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));
    vector<vector<int>> dir(N + 1, vector<int>(M + 1, 0)); // 0 means up, 1 means left, 2 means both
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (dp[i - 1][j] > dp[i][j]) {
                dp[i][j] = dp[i - 1][j];
            }
            if (dp[i][j - 1] > dp[i][j]) {
                dp[i][j] = dp[i][j - 1];
                dir[i][j] = 1;
            }
            if (dp[i - 1][j - 1] + 1 >= dp[i][j] && A[i] == B[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                dir[i][j] = 2;
            }
        }
    }

    cout << dp[N][M] << endl;
    vector<int> ans;
    int x = N, y = M;
    while (x > 0 || y > 0) {
        if (x == 0) y--;
        else if (y == 0) x--;
        else if (dir[x][y] == 2) {
            ans.push_back(A[x]);
            x--;
            y--;
        }
        else if (dir[x][y] == 1) y--;
        else x--;
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " \n"[i + 1 == ans.size()];

    return 0;
}