#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;

/*
SOLUTION

count frequencies; if more than one of the freq counts is odd, then not possible
to construct a solution, init the middle letter if any, then expand outwards with pairs of letters
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string S;
    cin >> S;
    vector<int> freq(26, 0);
    for (char c : S) freq[c - 'A']++;
    int odd_cnt = 0;
    for (int i = 0; i < 26; i++) if (freq[i] % 2 == 1) odd_cnt++;
    if (odd_cnt > 1) {
        cout << "NO SOLUTION\n";
        return 0;
    }

    string ans = "";
    for (int i = 0; i < 26; i++) if (freq[i] % 2 == 1) {
        for (int f = 0; f < freq[i]; f++) ans += (char)(i + 'A');
    }
    for (int i = 0; i < 26; i++) if (freq[i] % 2 == 0 && freq[i] > 0) {
        string add = "";
        for (int f = 0; f < freq[i]; f += 2) add += (char)(i + 'A');
        string rev = add;
        reverse(rev.begin(), rev.end());
        ans = rev + ans + add;
    }
    cout << ans << endl;

    return 0;
}