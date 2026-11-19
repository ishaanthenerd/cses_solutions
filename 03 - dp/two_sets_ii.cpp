#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;

/*
SOLUTION

if N * (N + 1) / 2 is odd, give up; else, let S = N * (N + 1) / 4
set up knapsack dp from 0 to S with 1x item of each of 1 ... N; answer is dp[S] / 2 where division is done wrt MOD
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll N;
    cin >> N;
    if ((N * (N + 1) / 2) % 2 == 1) {
        cout << 0 << endl;
        return 0;
    }
    ll S = N * (N + 1) / 4;
    
    vector<ll> dp(S + 1, 0);
    dp[0] = 1;
    for (ll i = 1; i <= N; i++) {
        for (ll j = S - i; j >= 0; j--) {
            dp[j + i] = (dp[j + i] + dp[j]) % MOD;
        }
    }
    cout << ((dp[S] % 2 == 0) ? (dp[S] / 2) : ((dp[S] + MOD) / 2)) << endl;
    
    return 0;
}