#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
/*
SOLUTION

find the closed formula - take all possibilities, subtract 4 X {failed cases per direction}
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    vector<ll> ans = {0, 0, 6, 28};
    for (ll i = 4; i <= 10000; i++) {
        ans.push_back(i * i * (i * i - 1) / 2 - 4 * (i - 1) * (i - 2));
    }

    ll N;
    cin >> N;
    for (ll i = 1; i <= N; i++) cout << ans[i] << endl;
 
    return 0;
}