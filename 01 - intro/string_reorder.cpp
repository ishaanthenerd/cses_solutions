#include <bits/stdc++.h>
using namespace std;

/*
SOLUTION

if there is an excess of a single character at the start (> N/2 if even, > (N + 1)/2 if odd), then impossible
otherwise, greedily take the smallest character possible unless the current character is forced
*/
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string S;
    cin >> S;
    int N = S.length();
    
    vector<int> freq(26, 0);
    for (int i = 0; i < N; i++) freq[S[i] - 'A']++;
    int max_freq = 0;
    for (int i = 0; i < 26; i++) max_freq = max(max_freq, freq[i]);
    if (2 * max_freq > N + 1) {
        cout << -1 << endl;
        return 0;
    }
    
    string ans = "";
    for (int i = 0; i < N; i++) {
        int max_freq = 0, max_char = -1;
        for (int j = 0; j < 26; j++) {
            if (freq[j] > max_freq) {
                max_freq = freq[j];
                max_char = j;
            }
        }
        
        if (2 * max_freq == (N - i + 1)) {
            ans += (char)('A' + max_char);
            freq[max_char]--;
        }
        else {
            int first = 0;
            while (freq[first] == 0 || (ans.length() >= 1 && ans[ans.length() - 1] == ('A' + first))) first++;
            ans += (char)('A' + first);
            freq[first]--;
        }
    }
    cout << ans << endl;
    
    return 0;
}