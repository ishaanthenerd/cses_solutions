#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
SOLUTION

use bsearch on the sum; if the minimum subarray count required is <= K, then this sum is possible
make sure to set the initial low to the maximum value within the array, as this is the lowest possible answer
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N >> K;
    vector<ll> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i];
    
    ll low = LLONG_MIN, high = 1e15;
    for (int i = 0; i < N; i++) low = max(low, arr[i]);
    while (low < high) {
        ll mid = (low + high) / 2, cur_sum = 0;
        int sacnt = 1;
        for (int i = 0; i < N; i++) {
            if (cur_sum + arr[i] <= mid) cur_sum += arr[i];
            else {
                sacnt++;
                cur_sum = arr[i];
            }
        }
        if (sacnt <= K) high = mid;
        else low = mid + 1;
    }
    cout << low << endl;

    return 0;
}