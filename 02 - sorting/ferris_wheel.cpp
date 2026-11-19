#include <bits/stdc++.h>
using namespace std;

/*
SOLUTION

add[i] controls whether or not this person is (1) the smaller of a 2-child gondola or (2) the only one in a gondola
sort the children by weight; process from smallest & find the biggest partner that will fit in their gondola
if a match is found, the second child doesn't waste a gondola, so set to false; o/w, do nothing (default is true)
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, X;
    cin >> N >> X;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end());

    vector<bool> add(N, true);
    for (int left = 0, right = N - 1; left < right; left++) {
        while (left < right && A[left] + A[right] > X) right--;
        if (left < right && A[left] + A[right] <= X) {
            add[right] = false;
            right--;
        }
    }
    cout << accumulate(add.begin(), add.end(), 0) << endl;

    return 0;
}