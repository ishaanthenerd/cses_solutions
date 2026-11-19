#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
 
/*
SOLUTION

sweep line approach; keep track of the current best squared distance ans
letting d = floor(sqrt(ans)), only keep points in [x - d, x] for the current x, sort by y, then process points which are in [y - d, y + d] for the current y
the number of processed points at each step should be <= 6
*/

vector<pll> pts;
ll dist2(int x, int y) {
    return (pts[x].first - pts[y].first) * (pts[x].first - pts[y].first) + (pts[x].second - pts[y].second) * (pts[x].second - pts[y].second);
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int N;
    cin >> N;
    pts.resize(N);
    for (int i = 0; i < N; i++) cin >> pts[i].first >> pts[i].second;
    sort(pts.begin(), pts.end());
 
    ll ans = 8000000000000000000, d = (ll) sqrt(ans);
    int left = 0;
    set<pll> y_and_idx;
    for (int right = 0; right < N; right++) {
        while (left + 1 <= right && (pts[right].first - pts[left].first) > d) {
            y_and_idx.erase({pts[left].second, left});
            left++;
        }
        auto it_start = y_and_idx.lower_bound({pts[right].second - d, 0});
        auto it_end = y_and_idx.upper_bound({pts[right].second + d, N});
        for (auto it = it_start; it != it_end; it++) {
            pll p = *it;
            ans = min(ans, dist2(right, p.second));
        }
        d = (ll) sqrt(ans);
        y_and_idx.insert({pts[right].second, right});
    }
    cout << ans << endl;
 
    return 0;
}
