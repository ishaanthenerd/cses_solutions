#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
SOLUTION

# of products as a function of time is monotonic --> bsearch on time
make sure to break when products exceeds T, o/w you will end up with overflow!
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    ll T;
    cin >> N >> T;
    vector<ll> mach(N);
    for (int i = 0; i < N; i++) cin >> mach[i];

    ll low = 1, high = 1e18;
    while (low < high) {
        ll mid = (low + high) / 2;
        ll products = 0;
        for (int i = 0; i < N; i++) {
            products += mid / mach[i];
            if (products >= T) break;
        }
        if (products >= T) high = mid;
        else low = mid + 1;
    }
    cout << low << endl;

    return 0;
}