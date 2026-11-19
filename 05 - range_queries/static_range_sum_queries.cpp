#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;

/*
SOLUTION

use a prefix sum
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll N, Q;
    cin >> N >> Q;
    vector<ll> X(N);
    for (ll i = 0; i < N; i++) cin >> X[i];
    vector<ll> ps(N + 1, 0);
    for (ll i = 0; i < N; i++) ps[i + 1] = X[i] + ps[i];

    while (Q--) {
        ll A, B;
        cin >> A >> B;
        cout << ps[B] - ps[A - 1] << endl;
    }

    return 0;
}