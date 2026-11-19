#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
constexpr ll MOD = 1e9 + 7;

/*
SOLUTION

go in layers (i.e. consecutive sections of numbers w/ the same # of digits)
then process w/in the layer the Kth step belongs to
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int Q;
    cin >> Q;
    while (Q--) {
        ll K;
        cin >> K;
        ll ans = 0, layer = 1, layer_total = 9;
        while (K > layer_total) {
            K -= layer_total;
            ans += layer_total / layer;
            layer_total = layer_total / layer * (layer + 1) * 10;
            layer++;
        }
        ll times = K / layer;
        ans += times;
        K -= layer * times;
        if (K == 0) {
            cout << ans % 10 << endl;
        }
        else {
            ans++;
            vector<int> digits;
            while (ans > 0) {
                digits.push_back(ans % 10);
                ans /= 10;
            }
            reverse(digits.begin(), digits.end());
            cout << digits[K - 1] << endl;
        }
    }

    return 0;
}