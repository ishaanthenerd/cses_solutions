#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;
 
/*
SOLUTION

divide N by 5 & floor, then add to ans, then repeat until N hits 0
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll N;
    cin >> N;
    ll ans = 0;
    while (N >= 5) {
        ans += (N / 5);
        N /= 5;
    }
    cout << ans << endl;

    return 0;
}