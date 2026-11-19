#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

/*
SOLUTION

the main problem here is avoiding N^3 - here's a (questionable) way
extract all the sums and place them in a map: ll -> vector<pii>
iterate through the map; for each sum Y, check if X - Y is there --> check if there are two pairs, one within each vector that are compatible with each other
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    ll X;
    cin >> N >> X;
    vector<ll> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i];
    if (N < 4) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    map<ll, vector<pii>> two_sum_to_idxs; 
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            two_sum_to_idxs[arr[i] + arr[j]].push_back({i, j});
        }
    }

    for (auto &p : two_sum_to_idxs) {
        if (p.first <= X && two_sum_to_idxs.count(X - p.first)) {
            for (pii p1 : two_sum_to_idxs[p.first]) {
                for (pii p2 : two_sum_to_idxs[X - p.first]) {
                    if (p1.first != p2.first && p1.first != p2.second && p1.second != p2.first && p1.second != p2.second) {
                        cout << p1.first + 1 << " " << p1.second + 1 << " " << p2.first + 1 << " " << p2.second + 1 << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << "IMPOSSIBLE\n";

    return 0;
}