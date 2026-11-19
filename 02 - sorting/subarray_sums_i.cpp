#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
SOLUTION

use 2ptr to get sums >= X, increment the answer when exactly == X
make sure that left <= right at all times, or else you will WA when consecutive individual values exceed X
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    ll X;
    cin >> N >> X;
    vector<ll> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i];

    int right = 0, ans = 0;
    ll total = arr[0];
    for (int left = 0; left < N; left++) {
        while (right < left || (right + 1 < N && total < X)) {
            right++;
            total += arr[right];
        }
        if (total == X) ans++;
        total -= arr[left];
    }
    cout << ans << endl;

    return 0;
}