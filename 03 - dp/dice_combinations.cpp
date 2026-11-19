#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;
 
/*
SOLUTION

state = sum, transition: dp[sum] = dp[sum - 1] + ... + dp[sum - 6]
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    vector<ll> dp = {1, 1, 2, 4, 8, 16, 32};
    while (dp.size() <= N) {
        ll cur_sum = 0;
        for (int i = 1; i <= 6; i++) {
            cur_sum = (cur_sum + dp[dp.size() - i]) % MOD;
        }
        dp.push_back(cur_sum);
    }
    cout << dp[N] << endl;
    
    return 0;
}