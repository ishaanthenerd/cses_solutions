#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;

/*
SOLUTION

use a segtree on sum; add a binary walk to determine the first index (left) where the left-side sum == P
be careful to FIRST DO THE UPDATE ON P! then go down the tree
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

    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<int> filled(N, 1);
    ST<int> seg(filled);

    while (N--) {
        int P;
        cin >> P;
        int pos = 1, left = 0, right = seg.n - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (seg.st[2 * pos] >= P) {
                pos = 2 * pos;
                right = mid;
            }
            else {
                P -= seg.st[2 * pos];
                pos = 2 * pos + 1;
                left = mid + 1;
            }
        }
        cout << A[left] << " ";
        seg.update(1, 0, seg.n - 1, left, 0);
    }
    cout << endl;

    return 0;
}