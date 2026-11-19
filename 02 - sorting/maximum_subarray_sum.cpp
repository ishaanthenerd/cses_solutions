#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
SOLUTION

for each index i, the best thing you can do is take the current prefix sum and subtract the lowest prefix sum seen until this point (exception: subtract all elements of the current prefix sum to get 0)
compute prefix sum -> prefix minimum -> answer, be mindful that ans starts at LLONG_MIN to accomodate negatives!
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    vector<ll> ps(N + 1, 0);
    for (int i = 1; i <= N; i++) ps[i] = ps[i - 1] + A[i - 1];
    vector<ll> min_ps(N + 1, 0);
    for (int i = 1; i <= N; i++) min_ps[i] = min(min_ps[i - 1], ps[i]);
    ll ans = LLONG_MIN;
    for (int i = 1; i <= N; i++) ans = max(ans, ps[i] - min_ps[i - 1]);
    cout << ans << endl;

    return 0;
}