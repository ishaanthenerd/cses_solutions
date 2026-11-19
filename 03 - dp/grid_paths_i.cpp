#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;

/*
SOLUTION

use dp on the number of ways, transition from the above and left cells to the current cell
*/
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    vector<string> grid(N);
    for (int i = 0; i < N; i++) cin >> grid[i];
    
    vector<vector<ll>> dp(N + 1, vector<ll>(N + 1, 0));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == 1 && j == 1) {
                dp[i][j] = (grid[0][0] != '*');
            }
            else if (grid[i - 1][j - 1] != '*') {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
            }
        }
    }
    cout << dp[N][N] << endl;
    
    return 0;
}
