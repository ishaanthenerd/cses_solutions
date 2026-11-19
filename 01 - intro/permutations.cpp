#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
/*
SOLUTION

if N is 2 or 3, impossible; o/w, list out all of the evens, then the odds
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int N;
    cin >> N;
    if (N == 2 || N == 3) cout << "NO SOLUTION\n";
    else {
        for (int i = 2; i <= N; i += 2) cout << i << " ";
        for (int i = 1; i <= N; i += 2) cout << i << " ";
        cout << endl;
    }
 
    return 0;
}