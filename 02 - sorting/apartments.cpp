#include <bits/stdc++.h>
using namespace std;

/*
SOLUTION

sort people and apartments
use two pointer; iterate through apartments, have the person point to the smallest value >= current apt - K
remember that every time a person is used, you have to move the person pointer forward!
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M, K;
    cin >> N >> M >> K;
    vector<int> A(N), B(M);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < M; i++) cin >> B[i];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int ans = 0, person = 0;
    for (int apt = 0; apt < M; apt++) {
        while (person < N && A[person] < B[apt] - K) person++;
        if (person < N && abs(A[person] - B[apt]) <= K) {
            ans++;
            person++;
        }
    }
    cout << ans << endl;

    return 0;
}