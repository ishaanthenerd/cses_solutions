#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
 
/*
SOLUTION

dp on the coin sum; go in order of coin value when transitioning, and iterate forward to allow multiple uses
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N, X;
    cin >> N >> X;
    vector<ll> C(N);
    for (int i = 0; i < N; i++) cin >> C[i];
    sort(C.begin(), C.end());
    
    vector<ll> dp(1000001, 0);
    dp[0] = 1;
    for (ll coin : C) {
        for (int i = 0; i <= 1000000 - coin; i++) {
            dp[i + coin] = (dp[i + coin] + dp[i]) % MOD;
        }
    }
    cout << dp[X] << endl;
    
    return 0;
}
