#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
SOLUTION

take a determinant; first column is P2 - P1, second column is P3 - P1
det > 0 --> LEFT
det = 0 --> TOUCH
det < 0 --> RIGHT
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        ll x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

        ll det = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
        if (det > 0) cout << "LEFT" << endl;
        else if (det == 0) cout << "TOUCH" << endl;
        else cout << "RIGHT" << endl;
    }

    return 0;
}