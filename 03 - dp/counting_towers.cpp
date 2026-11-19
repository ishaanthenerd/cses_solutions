#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;

/*
SOLUTION:

the idea is that there is a set of horizontal segments that go through the whole tower, creating jumps
for jumping X layers, there's either a single X-by-2 block (1 way) or split X-by-1 blocks that converge at the jump
at each internal layer, either the left side connects, the right side does, or both do, for 3^(X - 1) ways
hence, jumping X has (3^(X - 1) + 1) total ways

now the goal becomes computing sum((3^(j - 1) + 1) * dp[i - j] for j in 1 ... i)
variables: sum keeps track of dp[i - j] terms, three_sum keeps track of the terms w/ the powers of three

ex.
dp[1] = (3^0 * dp[0]) + (dp[0])
dp[2] = (3^0 * dp[1] + 3^1 * dp[0]) + (dp[1] + dp[0])
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll MAX_N = 1000000, three_sum = 1, sum = 1;
    vector<ll> dp(MAX_N + 1, 0);
    dp[0] = 1;
    for (ll i = 1; i <= MAX_N; i++) {
        dp[i] = (three_sum + sum) % MOD;
        three_sum = (3 * three_sum + dp[i]) % MOD;
        sum = (sum + dp[i]) % MOD;
    }

    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        cout << dp[n] << endl;
    }

    return 0;
}