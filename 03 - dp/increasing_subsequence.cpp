#include <bits/stdc++.h>
using namespace std;

/*
SOLUTION

use textbook LIS (NlogN method) and win
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i];

    vector<int> lis = {arr[0]};
    for (int i = 1; i < N; i++) {
        auto it = lower_bound(lis.begin(), lis.end(), arr[i]);
        if (it == lis.end()) lis.push_back(arr[i]);
        else *it = arr[i];
    }
    cout << lis.size() << endl;
    
    return 0;
}
