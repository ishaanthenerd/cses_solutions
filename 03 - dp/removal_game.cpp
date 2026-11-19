#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

/*
SOLUTION

use range dp, where the ans at [start, end) is the best score of P1 and P2 when starting the game there
for whoever's turn it is, they have two options; maximize their final score
NOTE: do NOT fixate on who is in the lead, as that is completely irrelevant!
*/

int main() {
    ll N;
    cin >> N;
    vector<ll> arr(N);
    for (ll i = 0; i < N; i++) cin >> arr[i];

    // dp represents each player's best score at the point of the game where there is said range left
    vector<vector<ll>> P1(N + 1, vector<ll>(N + 1, 0));
    vector<vector<ll>> P2(N + 1, vector<ll>(N + 1, 0));
    if (N % 2 == 0) for (ll i = 0; i < N; i++) P2[i][i + 1] = arr[i];
    else for (ll i = 0; i < N; i++) P1[i][i + 1] = arr[i];

    for (ll l = 2; l <= N; l++) {
        for (ll i = 0; i + l <= N; i++) {
            if ((N % 2 == 0) ^ (l % 2 == 1)) {
                // P1's turn
                ll lhs = P1[i + 1][i + l] + arr[i];
                ll rhs = P1[i][i + l - 1] + arr[i + l - 1];
                if (lhs > rhs) {
                    P1[i][i + l] = lhs;
                    P2[i][i + l] = P2[i + 1][i + l];
                }
                else {
                    P1[i][i + l] = rhs;
                    P2[i][i + l] = P2[i][i + l - 1];
                }
            }
            else {
                // P2's turn
                ll lhs = P2[i + 1][i + l] + arr[i];
                ll rhs = P2[i][i + l - 1] + arr[i + l - 1];
                if (lhs > rhs) {
                    P2[i][i + l] = lhs;
                    P1[i][i + l] = P1[i + 1][i + l];
                }
                else {
                    P2[i][i + l] = rhs;
                    P1[i][i + l] = P1[i][i + l - 1];
                }
            }
        }
    }
    cout << P1[0][N] << endl;

    return 0;
}