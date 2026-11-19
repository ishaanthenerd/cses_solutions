#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

/*
SOLUTION

idea is that for each ps[i], we want the minimum value of ps[i - B] ... ps[i - A] to subtract off
use a segtree to get this minimum and update it with each new prefix sum
*/

template <typename T>
struct ST {
    int n;
    vector<T> a, st;
    ST(vector<T> b) : n(b.size()), a(b) {
        st.assign(4 * n, T());
        for (int i = 0; i < n; i++) update(1, 0, n - 1, i, a[i]);
    }
    T f(T x, T y) { return min(x, y); }

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
        if (ql > right || qr < left) return 2e15; // default
        if (ql <= left && right <= qr) return st[pos];
        int mid = (left + right) / 2;
        return f(query(2 * pos, left, mid, ql, qr), query(2 * pos + 1, mid + 1, right, ql, qr));
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, A, B;
    cin >> N >> A >> B;
    vector<ll> arr(N + 1);
    for (int i = 1; i <= N; i++) cin >> arr[i];

    ST<ll> seg(vector<ll>(N + 1, 2e15));
    ll ps = 0, ans = -2e15;
    seg.update(1, 0, seg.n - 1, 0, 0);
    for (int i = 1; i <= N; i++) {
        ps += arr[i];
        ans = max(ans, ps - seg.query(1, 0, seg.n - 1, max(0, i - B), min(seg.n - 1, i - A)));
        seg.update(1, 0, seg.n - 1, i, ps);
    }   
    cout << ans << endl;

    return 0;
}