#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
constexpr ll MOD = 1e9 + 7;

/*
SOLUTION

for each sum i, check for each coin whether i - coin is possible; if so, update dp[i] accordingly
answer is just the # of coins needed at X (i.e. dp[X]) or -1 if dp[X] == INT_MAX
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, X;
    cin >> N >> X;
    vector<int> C(N);
    for (int i = 0; i < N; i++) cin >> C[i];
    sort(C.begin(), C.end());

    vector<int> dp(X + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= X; i++) {
        for (int coin : C) {
            if (coin > i) break;
            if (dp[i - coin] != INT_MAX) dp[i] = min(dp[i], dp[i - coin] + 1);
        }
    }
    cout << (dp[X] == INT_MAX ? -1 : dp[X]) << endl;

    return 0;
}