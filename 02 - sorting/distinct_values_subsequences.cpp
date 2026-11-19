#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;

/*
SOLUTION

for each value that appears with a certain freq, there are freq + 1 options for which idx (if any) to pick
multiply these and subtract 1 for the empty choice
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    map<int, ll> freq;
    for (int i = 0; i < N; i++) {
        int X;
        cin >> X;
        freq[X]++;
    }

    ll ans = 1;
    for (auto &p : freq) ans = (ans * (p.second + 1)) % MOD;
    ans = (ans - 1 + MOD) % MOD;
    cout << ans << endl;

    return 0;
}