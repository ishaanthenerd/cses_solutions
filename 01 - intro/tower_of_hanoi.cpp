#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
constexpr ll MOD = 1e9 + 7;

/*
SOLUTION

for N = 1, just move the disk directly
for each N where N >= 2, the solve takes the first N - 1 disks to the intermediate tower, then the last disk to the final tower, then the intermediate to the final
recursively get the ordering of operations to solve the problem
*/

vector<pii> solve(int N, int start, int end) {
    if (N == 1) {
        vector<pii> ans = {{start, end}};
        return ans;
    }
    vector<pii> prev = solve(N - 1, start, 6 - start - end);
    prev.push_back({start, end});
    vector<pii> next = solve(N - 1, 6 - start - end, end);
    for (pii p : next) prev.push_back(p);
    return prev;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    vector<pii> ans = solve(N, 1, 3);
    cout << ans.size() << endl;
    for (pii p : ans) cout << p.first << " " << p.second << endl;

    return 0;
}