#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
SOLUTION

for each prefix sum ps[i], count how many prefix sums before it have value ps[i] - X --> difference is X
use a map to keep track of frequencies of prefix sums and win
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    ll X;
    cin >> N >> X;
    vector<ll> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i];
    vector<ll> ps(N + 1);
    for (int i = 1; i <= N; i++) ps[i] = ps[i - 1] + arr[i - 1];

    ll ans = 0;
    map<ll, int> freq;
    freq[0] = 1;
    for (int i = 1; i <= N; i++) {
        ans += freq[ps[i] - X];
        freq[ps[i]]++;
    }
    cout << ans << endl;

    return 0;
}