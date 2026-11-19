#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
SOLUTION

use two pointer (update right when moving it forward adds a new element, delete left after it's done)
store all current elements in a set
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i];

    int right = 0, ans = 0;
    set<int> store;
    store.insert(arr[0]);
    for (int left = 0; left < N; left++) {
        while (right + 1 < N && store.find(arr[right + 1]) == store.end()) {
            store.insert(arr[right + 1]);
            right++;
        }
        ans = max(ans, right - left + 1);
        store.erase(arr[left]);
    }
    cout << ans << endl;

    return 0;
}