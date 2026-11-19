#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
SOLUTION

sort the array, fix one value at a certain index, then use 2ptr to get X - arr[fixed] from two other values
to retrieve the original indices, use a map: ll -> vector<int> and pop back every time to ensure unique indices
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    ll X;
    cin >> N >> X;
    vector<ll> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i];
    if (N < 3) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    map<ll, vector<int>> val_to_idx;
    for (int i = 0; i < N; i++) val_to_idx[arr[i]].push_back(i);

    sort(arr.begin(), arr.end());
    vector<ll> answers = {-1, -1, -1};
    for (int fixed = 0; fixed < N; fixed++) {
        int left = 0 + (fixed == 0), right = N - 1 - (fixed == (N - 1));
        while (left < right) {
            if (arr[left] + arr[right] == X - arr[fixed]) {
                answers = {arr[left], arr[right], arr[fixed]};
                break;
            }
            else if (arr[left] + arr[right] < X - arr[fixed]) {
                left++;
                if (left == fixed) left++;
            }
            else {
                right--;
                if (right == fixed) right--;
            }
        }
        if (answers[0] != -1) break;
    }

    if (answers[0] == -1) {
        cout << "IMPOSSIBLE\n";
    }
    else {
        for (ll val : answers) {
            cout << val_to_idx[val].back() + 1 << " ";
            val_to_idx[val].pop_back();
        }
        cout << endl;
    }

    return 0;
}