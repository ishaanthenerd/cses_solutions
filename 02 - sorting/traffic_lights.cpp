#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

/*
SOLUTION

use a set<pii> to store what intervals currently exist and a map<int, int> to count # of intervals for each length
find which interval to split by using upper_bound on the first set
when splitting an interval, delete one count of its length (remember to ERASE from the map if freq hits 0) and add a count for each of the new lengths
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int X, N;
    cin >> X >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i];

    set<pii> lights;
    map<int, int> freq;
    lights.insert({0, X});
    freq[X] = 1;
    for (int i = 0; i < N; i++) {
        auto it = --lights.upper_bound({arr[i], INT_MAX});
        pii p = *it;
        lights.erase(it);
        lights.insert({p.first, arr[i]});
        lights.insert({arr[i], p.second});
        freq[p.second - p.first]--;
        if (freq[p.second - p.first] == 0) freq.erase(p.second - p.first);
        freq[p.second - arr[i]]++;
        freq[arr[i] - p.first]++;
        cout << (*freq.rbegin()).first << " \n"[i + 1 == N];
    }

    return 0;
}