#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
constexpr ll MOD = 1e9 + 7;

/*
SOLUTION

use bitmask and brute force all apple divisions
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    vector<ll> apples(N);
    for (int i = 0; i < N; i++) cin >> apples[i];

    ll ans = LLONG_MAX;
    for (int mask = 0; mask < (1 << N); mask++) {
        ll cur = 0;
        for (int bit = 0; bit < N; bit++) {
            cur += ((mask & (1 << bit)) ? 1 : -1) * apples[bit];
        }
        ans = min(ans, abs(cur));
    }
    cout << ans << endl;

    return 0;
}