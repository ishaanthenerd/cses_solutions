#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
/*
SOLUTION

keep track of the current number of repetitions and the current best, resetting after a change; take max at the end
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    string S;
    cin >> S;
    int N = S.length();
    int ans = 0, cur = 1;
    for (int i = 1; i < N; i++) {
        if (S[i] == S[i - 1]) cur++;
        else {
            ans = max(ans, cur);
            cur = 1;
        }
    }
    cout << max(ans, cur) << endl;
 
    return 0;
}