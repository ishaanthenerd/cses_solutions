#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
constexpr ll MOD = 1e9 + 7;

/*
SOLUTION

just check for each number what's already been seen to the left / above, then update 
(same as propagating right / below, which is done in this solve)
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    vector<vector<int>> ans(N, vector<int>(N, 0));
    vector<vector<set<int>>> seen(N, vector<set<int>>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            while (seen[i][j].find(ans[i][j]) != seen[i][j].end()) ans[i][j]++;
            for (int k = i + 1; k < N; k++) {
                seen[k][j].insert(ans[i][j]);
            }
            for (int k = j + 1; k < N; k++) {
                seen[i][k].insert(ans[i][j]);
            }
        }
    }
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cout << ans[i][j] << " \n"[j + 1 == N];

    return 0;
}