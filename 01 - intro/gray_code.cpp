#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;

/*
SOLUTION

solve the problem for N - 1 recursively (if N = 1, done)
take a copy, append its reverse, then add 0s at the end of each string in the first half and 1s for the second
*/

vector<string> solve(int N) {
    if (N == 1) return {"0", "1"};
    vector<string> prev = solve(N - 1);
    vector<string> rev = prev;
    reverse(rev.begin(), rev.end());
    for (int i = 0; i < prev.size(); i++) prev[i] += "0";
    for (int i = 0; i < rev.size(); i++) rev[i] += "1";
    for (int i = 0; i < rev.size(); i++) prev.push_back(rev[i]);
    return prev;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    vector<string> ans = solve(N);
    for (string s : ans) cout << s << endl;

    return 0;
}