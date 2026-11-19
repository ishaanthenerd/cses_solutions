#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
constexpr ll MOD = 1e9 + 7;

/*
SOLUTION

consider every diagonal where i + j = X for some X; if any char is strictly better than another, we can greedily pick it to get the best substring
the trick is realizing that every diagonal's best options lead way to the next diagonal's best options through a down / right move (don't create duplicate pairs of indices or it screws itself over)
use dp to store the current list of the current diagonal's best options, then set their candidacy as true
at the end of the problem, work backwords from the end to generate the solution
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    string s;
    vector<vector<string>> arr(N, vector<string>(N));
    for (int i = 0; i < N; i++) {
        cin >> s;
        for (int j = 0; j < N; j++) arr[i][j] = s.substr(j, 1);
    }

    vector<vector<bool>> contention(N, vector<bool>(N));
    contention[0][0] = true;
    vector<pii> contention_list = {{0, 0}};
    for (int i = 1; i < 2 * N; i++) {
        vector<pii> next_contention_list;
        for (pii v : contention_list) {
            if (v.first + 1 < N) {
                if (!(next_contention_list.size() >= 1 && next_contention_list.back().first == v.first + 1 && next_contention_list.back().second == v.second)) {
                    next_contention_list.push_back({v.first + 1, v.second});
                }
            }
            if (v.second + 1 < N) {
                next_contention_list.push_back({v.first, v.second + 1});
            }
        }
        string best_letter = "Z";
        vector<pii> mod_contention_list;
        for (pii v : next_contention_list) {
            if (arr[v.first][v.second] == best_letter) {
                mod_contention_list.push_back(v);
            }
            else if (arr[v.first][v.second] < best_letter) {
                best_letter = arr[v.first][v.second];
                mod_contention_list = {v};
            }
        }
        contention_list = mod_contention_list;
        for (pii v : mod_contention_list) contention[v.first][v.second] = true;
    }

    pii cur = {N - 1, N - 1};
    vector<pii> path = {cur};
    while (path.back().first != 0 || path.back().second != 0) {
        if (cur.first - 1 >= 0 && contention[cur.first - 1][cur.second]) {
            cur.first--;
        }
        else {
            cur.second--;
        }
        path.push_back(cur);
    }
    reverse(path.begin(), path.end());
    for (pii v : path) {
        cout << arr[v.first][v.second];
    }
    cout << endl;

    return 0;
}