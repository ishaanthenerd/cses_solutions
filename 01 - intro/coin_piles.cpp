#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;
 
/*
SOLUTION

calculate # of times for each operation needed, determine if both end up as positive integers
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    // 2x +  y = A
    //  x + 2y = B
    // -3y = A - 2B --> y = (2B - A) / 3, x = (2A - B) / 3

    int T;
    cin >> T;
    while (T--) {
        int A, B;
        cin >> A >> B;
        bool cond = ((2 * B - A) % 3 == 0) && ((2 * B - A) >= 0) && ((2 * A - B) % 3 == 0) && ((2 * A - B) >= 0);
        cout << (cond ? "YES\n" : "NO\n");
    }

    return 0;
}