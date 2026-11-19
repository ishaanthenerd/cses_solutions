#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
/*
SOLUTION

the layer of the spiral is equal to the maximum
compute the value on the layer and on the diagonal, then make an adjustment based on which of X, Y is bigger (this adjustment is reversed from an even layer to an odd one!)
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int T;
    cin >> T;
    while (T--) {
        ll X, Y;
        cin >> X >> Y;
        ll M = max(X, Y);
        cout << ((M - 1) * (M - 1) + M + ((M % 2 == 0) ? 1 : -1) * (X - Y)) << endl;
    }
 
    return 0;
}