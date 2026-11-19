#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
SOLUTION

use 2ptr and ensure that every addition keeps the number of elements in the freq map <= K
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N >> K;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i];

    ll ans = 0;
    int right = 0;
    map<int, int> freq;
    freq[arr[0]] = 1;
    for (int left = 0; left < N; left++) {
        while (right + 1 < N && (freq.count(arr[right + 1]) || freq.size() < K)) {
            right++;
            freq[arr[right]]++;
        }
        ans += (right - left + 1);
        freq[arr[left]]--;
        if (freq[arr[left]] == 0) freq.erase(arr[left]);
    }
    cout << ans << endl;

    return 0;
}