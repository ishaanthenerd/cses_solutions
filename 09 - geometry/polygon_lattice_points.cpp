#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

/*
SOLUTION

use shoelace to get the area, count boundary points using gcd of consecutive pairs of points, then solve for what the interior point count should be
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<pll> pts(N);
    for (int i = 0; i < N; i++) cin >> pts[i].first >> pts[i].second;

    ll double_area = 0;
    for (int i = 0; i < N; i++) {
        int j = (i + 1) % N;
        double_area += (pts[i].first * pts[j].second - pts[j].first * pts[i].second);
    }
    double_area = abs(double_area); // = 2 * I + B - 2

    ll boundary = 0;
    for (int i = 0; i < N; i++) {
        int j = (i + 1) % N;
        ll dx = abs(pts[j].first - pts[i].first), dy = abs(pts[j].second - pts[i].second);
        boundary += gcd(dx, dy);
    }
    ll interior = (double_area + 2 - boundary) / 2;
    cout << interior << " " << boundary << endl;

    return 0;
}