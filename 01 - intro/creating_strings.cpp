#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
constexpr ll MOD = 1e9 + 7;

/*
SOLUTION

cheese it with next_permutation(S.begin(), S.end()) where S is vector<char>
bool return is the opposite of whether the next_permutation operation went from the last permutation to the first one (when false, break loop)
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string temp;
    cin >> temp;
    vector<char> S;
    for (char c : temp) S.push_back(c);
    sort(S.begin(), S.end());
    vector<vector<char>> ans; 
    do {
        ans.push_back(S);
    } while (next_permutation(S.begin(), S.end()));

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        for (char c : ans[i]) cout << c;
        cout << endl;
    }

    return 0;
}