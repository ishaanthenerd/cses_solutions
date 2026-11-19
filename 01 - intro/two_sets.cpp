#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
/*
SOLUTION

if N % 4 is 1 or 2, not possible (sum is not even)
if N % 4 is 3, write down 0, 1, ..., N - 1, N --> pair 0 o---o N, 1 o---o N - 1, etc and alternate pairs
if N % 4 is 0, write down 1, 2, ..., N - 1, N --> pair 1 o---o N, 2 o---o N - 1, etc and alternate pairs
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    ll N;
    cin >> N;
    if ((N % 4 == 1) || (N % 4 == 2)) {
        cout << "NO\n";
    }
    else if (N % 4 == 3) {
        cout << "YES\n";
        vector<ll> first_set, second_set;
        for (ll i = 0; i <= N / 2; i++) {
            if (i % 2 == 1) {
                first_set.push_back(i);
                first_set.push_back(N - i);
            }
            else {
                if (i != 0) second_set.push_back(i);
                second_set.push_back(N - i);
            }
        }
        cout << first_set.size() << endl;
        for (ll i = 0; i < first_set.size(); i++) cout << first_set[i] << " \n"[i + 1 == first_set.size()];
        cout << second_set.size() << endl;
        for (ll i = 0; i < second_set.size(); i++) cout << second_set[i] << " \n"[i + 1 == second_set.size()];
    }
    else {
        cout << "YES\n";
        vector<ll> first_set, second_set;
        for (ll i = 1; i <= N / 2; i++) {
            if (i % 2 == 1) {
                first_set.push_back(i);
                first_set.push_back(N + 1 - i);
            }
            else {
                second_set.push_back(i);
                second_set.push_back(N + 1 - i);
            }
        }
        cout << first_set.size() << endl;
        for (ll i = 0; i < first_set.size(); i++) cout << first_set[i] << " \n"[i + 1 == first_set.size()];
        cout << second_set.size() << endl;
        for (ll i = 0; i < second_set.size(); i++) cout << second_set[i] << " \n"[i + 1 == second_set.size()];
    }
 
    return 0;
}