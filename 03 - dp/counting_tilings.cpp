#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;

/*
SOLUTION

part 1 (initial solve, too slow)
every tile becomes ㄇ, ㄈ, ㄩ, or コ
assume that # of rows << # of cols; we can determine if a potential next row can follow a prior row by checking the up / down direction and for left / right pairsS
iterate across all possible pairs of rows, then store a dp where the idx is the mask for the row and the value is the # of ways to get there mod 1e9 + 7
repeat the dp transition listed above (# of rows) times and take the last row to have no ㄇ to finish

part 2 (optimized solve)
idea: collapse states ㄈ, ㄩ, and コ --> 口
now, to determine if row A can precede row B, the following two conditions must hold:
- A and B can't have a ㄇ in the same idx
- B will have to have idxs of ㄇ and ㄩ dictated by A and B together, so the leftover cells must form pairs of ㄈ and コ (unique choice)
create the adjacency list of rows as before, then repeat and filter as before to finish
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll N, M;
    cin >> N >> M;
    if ((N * M) % 2 == 1) {
        cout << 0 << endl;
        return 0;
    }

    // N is smaller now
    if (M < N) {
        ll temp = N;
        N = M;
        M = temp;
    }

    // 1 is the m bopomofo, 0 is anything else
    vector<vector<ll>> adj((1 << N));
    for (ll mask = 0; mask < (1 << N); mask++) {
        for (ll other = 0; other < (1 << N); other++) {
            // check for double 1 (failure)
            vector<ll> occupied = {-1};
            bool works = true;
            for (ll i = 0; i < N; i++) {
                if ((mask & (1 << i)) && (other & (1 << i))) {
                    works = false;
                    break;
                }
                else if ((mask & (1 << i)) || (other & (1 << i))) {
                    occupied.push_back(i);
                }
            }
            occupied.push_back(N);

            // check for left-right parity failure (odd # of between-cells)
            for (ll i = 0; i + 1 < occupied.size(); i++) {
                if ((occupied[i + 1] - occupied[i]) % 2 == 0) {
                    works = false;
                    break;
                }
            }
            if (works) {
                adj[mask].push_back(other);
            }
        }
    }

    // dp stores ways at a bitmask; rep it M times
    vector<ll> dp((1 << N), 0);
    dp[0] = 1;
    for (ll times = 0; times < M; times++) {
        vector<ll> next_dp((1 << N), 0);
        for (ll mask = 0; mask < (1 << N); mask++) {
            for (ll other : adj[mask]) {
                next_dp[other] = (next_dp[other] + dp[mask]) % MOD;
            }
        }
        dp = next_dp;
    }

    // lastly, filter for no 1s
    cout << dp[0] << endl;

    return 0;
}