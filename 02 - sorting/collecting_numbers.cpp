#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
SOLUTION

take inv_A as an array from value to index
for each value in order, if inv_A returns a lower index than before, there needs to be another pass to get there
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> A(N + 1, 0);
    for (int i = 1; i <= N; i++) cin >> A[i];
    vector<int> inv_A(N + 1, 0);
    for (int i = 1; i <= N; i++) inv_A[A[i]] = i;
    
    int ans = 1;
    for (int i = 1; i <= N; i++) if (inv_A[i] < inv_A[i - 1]) ans++;
    cout << ans << endl;

    return 0;
}