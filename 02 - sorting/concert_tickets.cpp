#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

/*
SOLUTION

use a multiset and win (barely - constant factor of 2 kills this!)
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    multiset<int> tickets;
    for (int i = 0; i < N; i++) {
        int X;
        cin >> X;
        tickets.insert(X);
    }
    while (M--) {
        int P;
        cin >> P;
        if (tickets.size() == 0 || P < (*tickets.begin())) {
            cout << -1 << endl;
        }
        else {
            auto it = --tickets.upper_bound(P);
            cout << (*it) << endl;
            tickets.erase(it);
        }
    }

    return 0;
}