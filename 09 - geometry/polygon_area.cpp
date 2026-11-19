#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
SOLUTION

use shoelace formula and win
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<ll> X(N), Y(N);
    for (int i = 0; i < N; i++) cin >> X[i] >> Y[i];
    ll ans = 0;
    for (int i = 0; i < N; i++) ans += (X[i] * Y[i + 1] - Y[i] * X[i + 1]);
    ans += (X[N - 1] * Y[0] - Y[N - 1] * X[0]);
    cout << abs(ans) << endl;

    return 0;
}