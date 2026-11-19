#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll N, X;
    cin >> N >> X;
    vector<ll> W(N);
    for (ll i = 0; i < N; i++) cin >> W[i];

    // trick: dp stores rides & min weight of LAST ride
    vector<pll> dp((1 << N), {INT_MAX, 0}); 
    dp[0] = {1, 0};
    for (ll mask = 0; mask < (1 << N); mask++) {
        for (ll bit = 0; bit < N; bit++) {
            if (!(mask & (1 << bit))) {
                if (W[bit] + dp[mask].second > X) {
                    dp[mask | (1 << bit)] = min(dp[mask | (1 << bit)], {dp[mask].first + 1, W[bit]});
                }
                else {
                    dp[mask | (1 << bit)] = min(dp[mask | (1 << bit)], {dp[mask].first, dp[mask].second + W[bit]});
                }
            }
        }
    }
    cout << dp[(1 << N) - 1].first << endl;

    return 0;
}