#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;

/*
SOLUTION

use a prefix xor sum
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    ll N, Q;
    cin >> N >> Q;
    vector<ll> X(N);
    for (ll i = 0; i < N; i++) cin >> X[i];
    vector<ll> xor_ps(N + 1, 0);
    for (ll i = 0; i < N; i++) xor_ps[i + 1] = X[i] ^ xor_ps[i];

    while (Q--) {
        ll A, B;
        cin >> A >> B;
        cout << (xor_ps[A - 1] ^ xor_ps[B]) << endl;
    }
 
    return 0;
}