#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;
 
/*
SOLUTION

use a segtree
*/

template <typename T>
struct ST {
    int n;
    vector<T> a, st;
    ST(vector<T> b) : n(b.size()), a(b) {
        st.assign(4 * n, 0);
        for (int i = 0; i < n; i++) update(1, 0, n - 1, i, a[i]);
    }
    T f(T x, T y) { return x + y; }
 
    void update(int pos, int left, int right, int idx, T val) {
        if (idx < left || idx > right) return;
        if (left == right) {
            st[pos] = a[idx] = val;
            return;
        }
        int mid = (left + right) / 2;
        update(2 * pos, left, mid, idx, val);
        update(2 * pos + 1, mid + 1, right, idx, val);
        st[pos] = f(st[2 * pos], st[2 * pos + 1]);
    }
 
    T query(int pos, int left, int right, int ql, int qr) {
        if (ql > right || qr < left) return 0; // default
        if (ql <= left && right <= qr) return st[pos];
        int mid = (left + right) / 2;
        return f(query(2 * pos, left, mid, ql, qr), query(2 * pos + 1, mid + 1, right, ql, qr));
    }
};
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    ll N, Q;
    cin >> N >> Q;
    vector<ll> X(N);
    for (ll i = 0; i < N; i++) cin >> X[i];
    ST<ll> seg(X);
    while (Q--) {
        ll T;
        cin >> T;
        if (T == 1) {
            ll K, U;
            cin >> K >> U;
            seg.update(1, 0, N - 1, --K, U);
        }
        else {
            ll A, B;
            cin >> A >> B;
            cout << seg.query(1, 0, N - 1, --A, --B) << endl;
        }
    }
 
    return 0;
}
