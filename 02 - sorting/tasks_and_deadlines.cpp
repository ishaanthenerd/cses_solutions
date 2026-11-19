#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

/*
SOLUTION

say that we do the tasks in some order: order[0], order[1], ..., order[N - 1]
then the total completion time at all task ends is N * order[0] + ... + 1 * order[N - 1]
to minimize this quantity (& maximize the answer), order the tasks in ascending order by duration
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<pll> tasks(N);
    for (int i = 0; i < N; i++) cin >> tasks[i].first >> tasks[i].second;
    sort(tasks.begin(), tasks.end());

    ll ans = 0, cur_time = 0;
    for (int i = 0; i < N; i++) {
        cur_time += tasks[i].first;
        ans = ans + tasks[i].second - cur_time;
    }
    cout << ans << endl;

    return 0;
}