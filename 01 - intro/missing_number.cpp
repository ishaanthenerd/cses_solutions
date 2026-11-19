#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
SOLUTION

take N(N + 1) / 2 as the start & subtract every number you see
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll N;
    cin >> N;
    ll sum = N * (N + 1) / 2;
    for (ll i = 1; i < N; i++) {
        ll x;
        cin >> x;
        sum -= x;
    }
    cout << sum << endl;

    return 0;
}