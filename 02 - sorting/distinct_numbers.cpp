#include <bits/stdc++.h>
using namespace std;

/*
SOLUTION

use a set and win
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    set<int> s;
    while (N--) {
        int X;
        cin >> X;
        s.insert(X);
    }
    cout << s.size() << endl;

    return 0;
}