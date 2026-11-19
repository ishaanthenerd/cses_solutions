#include <bits/stdc++.h>
using namespace std;
 
/*
SOLUTION

dp on the width and height; transition down to lower widths and lower heights to find the best # of cuts
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int A, B;
    cin >> A >> B;
    vector<vector<int>> dp(A + 1, vector<int>(B + 1, INT_MAX));
    for (int i = 0; i <= A; i++) dp[i][0] = 0;
    for (int j = 0; j <= B; j++) dp[0][j] = 0;
    for (int k = 1; k <= min(A, B); k++) dp[k][k] = 0;
    
    for (int i = 1; i <= A; i++) {
        for (int j = 1; j <= B; j++) {
            for (int k = 1; k <= i - 1; k++) {
                dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
            }
            for (int k = 1; k <= j - 1; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
            }
        }
    }
    cout << dp[A][B] << endl;
    
    return 0;
}
