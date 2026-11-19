#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
SOLUTION

soln 1
use ternary search and win

soln 2
every time that mid goes down by 1, it helps everything below and hurts above + vice versa
therefore, the best mid value is the median of A (works even when A has even length) -> compute answer and win
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    int low = 1, high = 1e9;
    while (high - low > 3) {
        int m1 = low + (high - low) / 3, m2 = high - (high - low) / 3;
        ll m1_total = 0, m2_total = 0;
        for (int i = 0; i < N; i++) m1_total += abs(m1 - A[i]);
        for (int i = 0; i < N; i++) m2_total += abs(m2 - A[i]);
        if (m1_total >= m2_total) low = m1;
        if (m1_total <= m2_total) high = m2;
    }
    
    ll ans = LLONG_MAX;
    for (int mid = low; mid <= high; mid++) {
        ll total = 0;
        for (int i = 0; i < N; i++) total += abs(mid - A[i]);
        ans = min(ans, total);
    }
    cout << ans << endl;

    return 0;
}