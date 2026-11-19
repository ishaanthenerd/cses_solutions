#include <bits/stdc++.h>
using namespace std;

/*
SOLUTION

dp on the total sum with a boolean array, update it with each new coin
*/
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    vector<int> coins(N);
    for (int i = 0; i < N; i++) cin >> coins[i];
    
    vector<bool> dp(100001, false);
    dp[0] = true;
    for (int coin : coins) {
        for (int i = 100000 - coin; i >= 0; i--) {
            dp[i + coin] = dp[i + coin] | dp[i];
        }
    }
    
    cout << accumulate(dp.begin(), dp.end(), -1) << endl;
    for (int i = 1; i <= 100000; i++) {
        if (dp[i]) cout << i << " ";
    }
    cout << endl;
    
    return 0;
}
