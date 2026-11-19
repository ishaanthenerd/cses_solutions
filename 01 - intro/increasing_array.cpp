#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
SOLUTION

keep track of the current greatest element, then add to ans if the current element is smaller
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<ll> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i];
    ll ans = 0, target = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] < target) ans += (target - arr[i]);
        else target = arr[i];
    }
    cout << ans << endl;

    return 0;
}