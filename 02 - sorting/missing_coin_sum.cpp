#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
SOLUTION

sort the coins, let total = sum of first (i - 1) coins at the i^th step
if A[i] > total + 1, then total + 1 is impossible; else, all values from [0 ... total] and [0 ... total] + A[i] are possible
if there is no midway failure point, then total of all of A + 1 is the first failure
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end());

    ll total = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] > total + 1) {
            cout << total + 1 << endl;
            return 0;
        }
        total += A[i];
    }
    cout << total + 1 << endl;

    return 0;
}