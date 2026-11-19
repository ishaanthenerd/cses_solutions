#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

/*
SOLUTION

use 2ptr; for each left idx, find the furthest right idx s.t. all elements are distinct (use a set for this)
at each left, add right - left + 1 to the answer
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<ll> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i];

    set<ll> cur;
    ll right = 0, ans = 0;
    cur.insert(arr[0]);
    for (ll left = 0; left < N; left++) {
        while (right + 1 < N && cur.find(arr[right + 1]) == cur.end()) {
            right++;
            cur.insert(arr[right]);
        }
        ans += (right - left + 1);
        cur.erase(arr[left]);
    }
    cout << ans << endl;

    return 0;
}