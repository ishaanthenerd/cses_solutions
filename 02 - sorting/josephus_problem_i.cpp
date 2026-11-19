#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;

/*
SOLUTION

use a deque and win
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    deque<int> d;
    for (int i = 1; i <= N; i++) d.push_back(i);
    while (d.size() > 0) {
        int x = d.front();
        d.pop_front();
        d.push_back(x);
        int y = d.front();
        d.pop_front();
        cout << y << " ";
    }
    cout << endl;

    return 0;
}