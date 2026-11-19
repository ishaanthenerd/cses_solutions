#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;

/*
SOLUTION

keep track of the current leftmost person and a 0/1 array for who's alive
since K is large, mod it by the # of people alive
check if this new K can fit within all of the alive people at and to the left of the current person; if so, the answer is to the right of the current person; if not, the answer will cycle back to the beginning
use a segtree to keep track of queries (counting alive people w/ segwalk) and updates (killing people)
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

    int walk(int k) {
        int pos = 1, left = 0, right = n - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (st[2 * pos] >= k) {
                right = mid;
                pos = 2 * pos;
            }
            else {
                k -= st[2 * pos];
                left = mid + 1;
                pos = 2 * pos + 1;
            }
        }
        return left;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, K, left = 0;
    cin >> N >> K;
    K++;
    ST<int> seg(vector<int>(N, 1));
    
    for (int i = N; i >= 1; i--) {
        int new_K = (K % i) + i * (K % i == 0), next;
        int rhs = seg.query(1, 0, seg.n - 1, left, seg.n - 1);
        int lhs = seg.st[1] - rhs;
        if (rhs >= new_K) next = seg.walk(lhs + new_K);
        else next = seg.walk(new_K - rhs);
        cout << next + 1 << " \n"[i == 1];
        seg.update(1, 0, seg.n - 1, next, 0);
        left = (next + 1) % N;
    }

    return 0;
}