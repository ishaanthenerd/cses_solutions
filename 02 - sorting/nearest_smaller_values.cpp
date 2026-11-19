#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

/*
SOLUTION

use a monotonic stack and win
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> arr(N + 1);
    for (int i = 1; i <= N; i++) cin >> arr[i];

    stack<int> mono;
    vector<int> ans(N + 1);
    for (int i = N; i >= 1; i--) {
        while (mono.size() > 0 && arr[i] < arr[mono.top()]) {
            ans[mono.top()] = i;
            mono.pop();
        }
        mono.push(i);
    }
    for (int i = 1; i <= N; i++) cout << ans[i] << " \n"[i == N];

    return 0;
}