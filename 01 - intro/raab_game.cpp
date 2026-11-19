#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
constexpr ll MOD = 1e9 + 7;

/*
SOLUTION

observations: if one person gets 0, other must get 0 for it to be possible; total score is capped by N
if both are true, then a solution is constructable as below
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while (T--) {
        int N, A, B;
        cin >> N >> A >> B;
        if (A + B > N) {
            cout << "NO\n";
            continue;
        }
        if (min(A, B) == 0) {
            cout << (max(A, B) == 0 ? "YES\n" : "NO\n");
            if (max(A, B) == 0) {
                for (int i = 0; i < 2; i++) {
                    for (int j = 0; j < N; j++) {
                        cout << j + 1 << " \n"[j + 1 == N];
                    }
                }
            }
            continue;
        }

        vector<int> A_arr(N), B_arr(N);
        iota(A_arr.begin(), A_arr.end(), 1);
        iota(B_arr.begin(), B_arr.end(), 1);
        for (int i = 0; i < A; i++) A_arr[i] += B;
        for (int i = A; i < A + B; i++) A_arr[i] -= A;

        cout << "YES\n";
        for (int i = 0; i < N; i++) cout << A_arr[i] << " \n"[i + 1 == N];
        for (int i = 0; i < N; i++) cout << B_arr[i] << " \n"[i + 1 == N];
    }

    return 0;
}