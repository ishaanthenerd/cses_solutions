#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
constexpr ll MOD = 1e9 + 7;

/*
SOLUTION

list all 40320 possibilities where all rows + columns are distinct
filter by reserved spaces
filter by both diagonals (use x => x + order[x] and x => x - order[x] to determine which diagonals queen x is on)
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int ans = 0;
    vector<string> reserved(8);
    for (int i = 0; i < 8; i++) cin >> reserved[i];

    for (int i = 0; i < 40320; i++) {
        vector<int> pick = {0, 1, 2, 3, 4, 5, 6, 7};
        vector<int> order;
        int copy = i;
        for (int j = 8; j >= 1; j--) {
            order.push_back(pick[copy % j]);
            pick.erase(pick.begin() + (copy % j));
            copy /= j;
        }

        bool to_continue = false;
        for (int j = 0; j < 8; j++) if (reserved[j][order[j]] == '*') {
            to_continue = true;
            break;
        }
        if (to_continue) continue;

        for (int j = 0; j < 8; j++) {
            for (int k = 0; k < 8; k++) {
                if (j == k) continue;
                if (j + order[j] == k + order[k]) {
                    to_continue = true;
                    break;
                }
                if (j - order[j] == k - order[k]) {
                    to_continue = true;
                    break;
                }
            }
            if (to_continue) break; 
        }
        if (to_continue) continue;
        ans++;
    }
    cout << ans << endl;

    return 0;
}