#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;
constexpr ll special = 1073741824; // 2 ** 30
 
/*
SOLUTION

the idea is to compute 2^N % MOD
the funny idea is to take N in chunks of 30; this gets a submission time of 0.00s
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    ll ans = 1;
    for (int i = 0; i < N / 30; i++) ans = (ans * special) % MOD;
    for (int i = 0; i < N % 30; i++) ans = (ans << 1) % MOD;
    cout << ans << endl;
 
    return 0;
}