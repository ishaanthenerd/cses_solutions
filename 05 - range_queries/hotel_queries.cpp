#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;

/*
SOLUTION

use a segtree on maximum; use a binary walk to get the first available hotel for each group
*/

template <typename T>
struct ST {
    int n;
    vector<T> a, st;
    ST(vector<T> b) : n(b.size()), a(b) {
        st.assign(4 * n, 0);
        for (int i = 0; i < n; i++) update(1, 0, n - 1, i, a[i]);
    }
    T f(T x, T y) { return max(x, y); }

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
        if (ql > right || qr < left) return numeric_limits<T>::min(); // default
        if (ql <= left && right <= qr) return st[pos];
        int mid = (left + right) / 2;
        return f(query(2 * pos, left, mid, ql, qr), query(2 * pos + 1, mid + 1, right, ql, qr));
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    vector<int> H(N);
    for (int i = 0; i < N; i++) cin >> H[i];
    ST<int> seg(H);

    while (M--) {
        int R;
        cin >> R;
        if (seg.st[1] < R) {
            cout << 0 << endl;
        }
        else {
            int pos = 1, left = 0, right = seg.n - 1;
            while (left < right) {
                int mid = (left + right) / 2;
                if (seg.st[2 * pos] >= R) {
                    pos = 2 * pos;
                    right = mid;
                }
                else {
                    pos = 2 * pos + 1;
                    left = mid + 1;
                }
            }
            cout << left + 1 << " ";
            seg.update(1, 0, seg.n - 1, left, seg.a[left] - R);
        }
    }
    cout << endl;

    return 0;
}