#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

/*
SOLUTION

process events where customers arrive (+1) and leave (-1)
sort all the events, then keep track of a running total & update the answer
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<pii> events;
    for (int i = 0; i < N; i++) {
        int X, Y;
        cin >> X >> Y;
        events.push_back({X, 1});
        events.push_back({Y, -1});
    }
    sort(events.begin(), events.end());

    int ans = 0, cur = 0;
    for (pii p : events) {
        cur += p.second;
        ans = max(ans, cur);
    }
    cout << ans << endl;

    return 0;
}