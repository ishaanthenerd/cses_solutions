#include <bits/stdc++.h>
using namespace std;

/*
SOLUTION

use knapsack dp and win
*/
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N, X;
    cin >> N >> X;
    vector<int> price(N), pages(N);
    for (int i = 0; i < N; i++) cin >> price[i];
    for (int i = 0; i < N; i++) cin >> pages[i];    
    
    vector<int> dp(X + 1, INT_MIN);
    dp[0] = 0;
    for (int i = 0; i < N; i++) {
        for (int p = X - price[i]; p >= 0; p--) {
            if (dp[p] != INT_MIN) {
                dp[p + price[i]] = max(dp[p + price[i]], dp[p] + pages[i]);
            }
        }
    }
    
    int ans = INT_MIN;
    for (int i = 0; i <= X; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    
    return 0;
}
