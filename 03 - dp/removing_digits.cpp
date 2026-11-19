#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
 
/*
SOLUTION

for each i, solve the dp for all previous states, then iterate over digits of i to get where to transition from
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    vector<int> ans(N + 1, 1e9);
    ans[0] = 0;
    for (int i = 1; i <= N; i++) {
        int copy = i;
        while (copy > 0) {
            ans[i] = min(ans[i], ans[i - (copy % 10)] + 1);
            copy /= 10;
        }
    }
    cout << ans[N] << endl;
    
    return 0;
}
