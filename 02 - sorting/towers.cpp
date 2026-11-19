#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
SOLUTION

find length of LIS and win
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i];

    vector<int> lis;
    for (int i = 0; i < N; i++) {
        auto it = upper_bound(lis.begin(), lis.end(), arr[i]);
        if (it == lis.end()) lis.push_back(arr[i]);
        else *it = arr[i];
    }
    cout << lis.size() << endl;

    return 0;
}