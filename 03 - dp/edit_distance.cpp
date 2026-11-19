#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;
 
/*
SOLUTION

dp on the positions within S and T; transitions are (1) adding a character from S or T with cost 1 AND (2) using the same character from S and T (or editing it with cost 1)
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string S, T;
    cin >> S >> T;
    int N = S.length(), M = T.length();
    vector<vector<int>> dp(N + 1, vector<int>(M + 1, 1e9));
    for (int i = 0; i <= N; i++) dp[i][0] = i;
    for (int j = 1; j <= M; j++) dp[0][j] = j;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]) + 1, dp[i - 1][j - 1] + (S[i - 1] != T[j - 1]));
        }
    }
    cout << dp[N][M] << endl;

    return 0;
}
