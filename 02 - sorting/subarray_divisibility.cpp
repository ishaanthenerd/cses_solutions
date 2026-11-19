#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
SOLUTION

same idea as subarray sums ii, keep track of a map from prefix sum -> freq
only change is that each ps should be converted to its positive mod N first
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<ll> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i];
    vector<ll> ps(N + 1);
    for (int i = 1; i <= N; i++) ps[i] = ps[i - 1] + arr[i - 1];
    for (int i = 1; i <= N; i++) ps[i] = ((ps[i] % N) + N) % N; // positive mod N

    ll ans = 0;
    map<ll, int> freq;
    freq[0] = 1;
    for (int i = 1; i <= N; i++) {
        ans += freq[ps[i]];
        freq[ps[i]]++;
    }
    cout << ans << endl;

    return 0;
}