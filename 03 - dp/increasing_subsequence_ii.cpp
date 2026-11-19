#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
constexpr ll MOD = 1e9 + 7;

/*
SOLUTION

coord compress the array values
for each value X[i], we want to count all subsequences ending before this point with a smaller value; this can be accomplished with a segtree on array values
once queried, add the new subsequences to X[i]'s spot in the segtree
after all values are processed, the segtree top contains the answer
*/

template <typename T>
struct ST {
    int n;
    vector<T> a, st;
    ST(vector<T> b) : n(b.size()), a(b) {
        st.assign(4 * n, 0);
        for (int i = 0; i < n; i++) update(1, 0, n - 1, i, a[i]);
    }
    T f(T x, T y) { return (x + y) % MOD; }

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

    ll N;
    cin >> N;
    vector<ll> X(N);
    for (ll i = 0; i < N; i++) cin >> X[i];

    map<ll, ll> compress;
    for (ll val : X) compress[val] = 1;
    ll cnt = 0;
    for (auto &p : compress) p.second = cnt++;
    for (ll i = 0; i < N; i++) X[i] = compress[X[i]];

    ll K = compress.size();
    ST<ll> seg(vector<ll>(K, 0));
    for (ll i = 0; i < N; i++) {
        ll q = 1;
        if (X[i] != 0) q = (q + seg.query(1, 0, K - 1, 0, X[i] - 1)) % MOD;
        seg.update(1, 0, K - 1, X[i], (seg.a[X[i]] + q) % MOD);
    }
    cout << seg.st[1] << endl;

    return 0;
}