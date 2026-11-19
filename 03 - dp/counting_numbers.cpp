#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;

/*
SOLUTION

calculate the # within [0, X] for any X, then use it on B and A - 1 --> subtract to win
represent X as a set of digits
handle all cases where a number has less digits than X as a sum powers of 9
for every case after, keep track of what's possible w/ digit dp && transition under the no-repeat condition
for any number clearly less than X, add a power of 9 to finish; for any number clearly greater, add 0
finish X by adding itself (1) if it works --> dp will tell you this at the end
*/

ll MAX_DIGITS = 19;
vector<ll> nine_pow;

ll solve(ll X) {
    // done if X == -1 or 0
    if (X <= 0) return X + 1;

    // compute representation of X
    vector<ll> digits(MAX_DIGITS, 0);
    ll copy = X;
    for (ll i = 0; i < MAX_DIGITS; i++) {
        digits[18 - i] = copy % 10;
        copy /= 10;
    }
    ll first_digit = 0;

    // handle everything whose # of digits is < X's # of digits
    while (digits[first_digit] == 0) first_digit++;
    ll ans = 0;
    for (ll lvl = first_digit; lvl < MAX_DIGITS; lvl++) {
        ans += nine_pow[MAX_DIGITS - 1 - lvl];
    }
    // handle everything whose # of digits is = X's # of digits w/ the first digit strictly less
    ans += (digits[first_digit] - 1) * nine_pow[MAX_DIGITS - 1 - first_digit];

    vector<ll> dp(10, 0);
    dp[digits[first_digit]] = 1;
    for (ll lvl = first_digit + 1; lvl < MAX_DIGITS; lvl++) {
        // dp -> next_dp, handle transition
        vector<ll> next_dp(10, 0);
        for (ll i = 0; i < 10; i++) for (ll j = 0; j < 10; j++) if (i != j) next_dp[j] += dp[i];

        // handle lesser digits (done early) and greater digits (0 possibilities)
        for (ll i = 0; i < digits[lvl]; i++) {
            ans += next_dp[i] * nine_pow[MAX_DIGITS - 1 - lvl];
        }
        for (ll i = 0; i < 10; i++) if (i != digits[lvl]) next_dp[i] = 0;
        dp = next_dp;
    }
    return ans + dp[digits[MAX_DIGITS - 1]];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // construct powers of 9
    nine_pow = {1};
    for (ll i = 1; i < MAX_DIGITS; i++) nine_pow.push_back(9 * nine_pow.back());
    ll A, B;
    cin >> A >> B;
    cout << solve(B) - solve(A - 1) << endl;
 
    return 0;
}