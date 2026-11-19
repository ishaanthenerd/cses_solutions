#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;
 
/*
SOLUTION

dp on the final value of the array at the {entry}^th step; when transitioning forward a step, apply the rule and if the current entry is fixed, turn the other dp values to 0
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N, M;
    cin >> N >> M;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i];

    vector<ll> dp(M + 1, 0);
    if (arr[0] == 0) for (int i = 1; i <= M; i++) dp[i] = 1;
    else dp[arr[0]] = 1;

    for (int entry = 1; entry < N; entry++) {
        vector<ll> next_dp(M + 1, 0);
        for (int i = 1; i <= M; i++) {
            for (int j = i - 1; j <= i + 1; j++) {
                if (j <= 0 || j > M) continue;
                next_dp[j] = (next_dp[j] + dp[i]) % MOD;
            }
        }
        if (arr[entry] != 0) {
            for (int i = 1; i <= M; i++) {
                if (i != arr[entry]) next_dp[i] = 0;
            }
        }
        dp = next_dp;
    }

    ll ans = 0;
    for (int i = 1; i <= M; i++) ans = (ans + dp[i]) % MOD;
    cout << ans << endl;

    return 0;
}
