#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
/*
SOLUTION

for each coordinate (x and y), find its contribution
sort the points by the given coord, then for each i, find sum of (this idx - prev idx) for all previous pts
this can be done with a prefix sum on the coord-at-idx values
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll N;
    cin >> N;
    vector<vector<ll>> pts(N, vector<ll>(2, 0));
    for (ll i = 0; i < N; i++) cin >> pts[i][0] >> pts[i][1];
    
    __int128 total = 0;
    for (ll idx = 0; idx < 2; idx++) {
        sort(pts.begin(), pts.end(), [&](vector<ll> a, vector<ll> b) { return a[idx] < b[idx]; });
        for (ll i = 0; i < N; i++) total += ((__int128)(2 * i + 1 - N)) * pts[i][idx];
    }
    vector<int> digits;
    do {
        digits.push_back(total % 10);
        total /= 10;
    } while (total > 0);
    reverse(digits.begin(), digits.end());
    for (int i = 0; i < digits.size(); i++) cout << digits[i];
    cout << endl;
    
    return 0;
}
