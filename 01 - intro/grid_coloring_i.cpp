#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
constexpr ll MOD = 1e9 + 7;

/*
SOLUTION

if a cell is A/B, switch it to C/D s.t. the new C/D cells form a checkerboard
if a cell is C/D, switch it to A/B s.t. the new A/B cells form a checkerboard
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N, M;
    cin >> N >> M;
    vector<vector<char>> grid(N, vector<char>(M));
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) cin >> grid[i][j];
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
        if (grid[i][j] == 'A' || grid[i][j] == 'B') grid[i][j] = ((i + j) % 2 == 0 ? 'C' : 'D');
        else grid[i][j] = ((i + j) % 2 == 0 ? 'A' : 'B');
    }
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
        cout << grid[i][j];
        if (j + 1 == M) cout << endl;
    }

    return 0;
}