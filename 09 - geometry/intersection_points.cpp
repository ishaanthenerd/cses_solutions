#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
 
/*
SOLUTION

make a segtree on y values
horizontal segments are insertions / removals, vertical segments are queries
*/

template <typename T>
struct ST {
    int n;
    vector<T> a, st;
    ST(vector<T> b) : n(b.size()), a(b) {
        st.assign(4 * n, T());
        for (int i = 0; i < n; i++) update(1, 0, n - 1, i, a[i]);
    }
    T f(T x, T y) { return x + y; }
    
    void update(int pos, int left, int right, int idx, T val) {
        if (left == right) {
            st[pos] = a[idx] = val;
            return;
        }
        int mid = (left + right) / 2;
        if (idx <= mid) update(2 * pos, left, mid, idx, val);
        else update(2 * pos + 1, mid + 1, right, idx, val);
        st[pos] = f(st[2 * pos], st[2 * pos + 1]);
    }
    
    T query(int pos, int left, int right, int ql, int qr) {
        if (qr < left || right < ql) return 0; // default
        if (ql <= left && right <= qr) return st[pos];
        int mid = (left + right) / 2;
        return f(query(2 * pos, left, mid, ql, qr), query(2 * pos + 1, mid + 1, right, ql, qr));
    }
};
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    vector<vector<ll>> segs(N, vector<ll>(4, 0));
    for (int i = 0; i < N; i++) for (int j = 0; j < 4; j++) cin >> segs[i][j];
    
    map<ll, ll> compress;
    for (int i = 0; i < N; i++) compress[segs[i][1]] = 0;
    for (int i = 0; i < N; i++) compress[segs[i][3]] = 0;
    ll cnt = 0;
    for (auto &p : compress) p.second = cnt++;
    for (int i = 0; i < N; i++) segs[i][1] = compress[segs[i][1]];
    for (int i = 0; i < N; i++) segs[i][3] = compress[segs[i][3]];
    
    vector<vector<ll>> queries;
    for (int i = 0; i < N; i++) {
        if (segs[i][0] == segs[i][2]) {
            queries.push_back({segs[i][0], 2, segs[i][1], segs[i][3]});
        }
        else {
            queries.push_back({segs[i][0], 1, segs[i][1]});
            queries.push_back({segs[i][2], 3, segs[i][1]});
        }
    }
    sort(queries.begin(), queries.end());
    
    ll ans = 0;
    ST<ll> st(vector<ll>(compress.size(), 0));
    for (vector<ll> v : queries) {
        if (v[1] == 1) {
            st.update(1, 0, st.n - 1, v[2], st.a[v[2]] + 1);
        }
        else if (v[1] == 2) {
            ans += st.query(1, 0, st.n - 1, v[2], v[3]);
        }
        else {
            st.update(1, 0, st.n - 1, v[2], st.a[v[2]] - 1);
        }
    }
    cout << ans << endl;
    
    return 0;
}