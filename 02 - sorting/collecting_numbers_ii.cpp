#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
SOLUTION

for each value v from 1 to N, keep track of if it causes a new round (+1 at the start immediately)
for two values vi & vj, if they are one apart, update three things in the total
o/w, update four things in the total (contributions of vi, vi + 1, vj, vj + 1)
*/

vector<int> inv;
int f(int v) { return inv[v - 1] > inv[v]; } // does going v - 1 --> v add 1 to the total?

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    vector<int> arr(N + 2, 0);
    arr[0] = N + 1;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    inv.assign(N + 2, 0);
    for (int i = 0; i <= N + 1; i++) inv[arr[i]] = i;

    int total = 0;
    for (int v = 1; v <= N; v++) total += f(v);
    
    while (M--) {
        int i, j;
        cin >> i >> j;
        int vi = arr[i], vj = arr[j];
        if (vi == vj) {
            cout << total << endl;
            continue;
        }
        else if (abs(vi - vj) == 1) {
            int v = min(vi, vj);
            total = total - (f(v) + f(v + 1) + f(v + 2));
            arr[i] = vj;
            arr[j] = vi;
            inv[vi] = j;
            inv[vj] = i;
            total = total + (f(v) + f(v + 1) + f(v + 2));
        }
        else {
            total = total - (f(vi) + f(vi + 1) + f(vj) + f(vj + 1));
            arr[i] = vj;
            arr[j] = vi;
            inv[vi] = j;
            inv[vj] = i;
            total = total + (f(vi) + f(vi + 1) + f(vj) + f(vj + 1));
        }
        cout << total << endl;
    }

    return 0;
}