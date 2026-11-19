#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;

/*
SOLUTION

just do it lol
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    vector<ll> weird = {n};
    while (weird.back() != 1) {
        if (weird.back() % 2 == 0) weird.push_back(weird.back() / 2);
        else weird.push_back(weird.back() * 3 + 1);
    }
    for (ll i = 0; i < weird.size(); i++) cout << weird[i] << " \n"[i + 1 == weird.size()];

    return 0;
}