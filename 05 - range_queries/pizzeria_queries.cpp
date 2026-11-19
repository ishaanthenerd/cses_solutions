#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;
 
/*
SOLUTION

store {P[i] + i} and {P[i] + (N - 1 - i)} as two arrays & build segtrees on them
to get the answer at some index, either go left (use first one) or go right (use second one), then subtract the appropriate extra quantities and take the minimum
*/

template <typename T>
struct ST {
    int n;
    vector<T> a, st;
    ST(vector<T> b) : n(b.size()), a(b) {
        st.assign(4 * n, 0);
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
        if (ql > right || qr < left) return numeric_limits<T>::max(); // default
        if (ql <= left && right <= qr) return st[pos];
        int mid = (left + right) / 2;
        return f(query(2 * pos, left, mid, ql, qr), query(2 * pos + 1, mid + 1, right, ql, qr));
    }
};
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int N, Q;
    cin >> N >> Q;
    vector<int> P(N);
    for (int i = 0; i < N; i++) cin >> P[i];
    
    vector<int> left_low(P), right_low(P);
    for (int i = 0; i < N; i++) {
        left_low[i] += i;
        right_low[i] += (N - 1 - i);
    }
    ST<int> seg_left(left_low), seg_right(right_low);

    while (Q--) {
        int T;
        cin >> T;
        if (T == 1) {
            int K, X;
            cin >> K >> X;
            K--;
            seg_left.update(1, 0, N - 1, K, X + K);
            seg_right.update(1, 0, N - 1, K, X + (N - 1 - K));
        }
        else {
            int K;
            cin >> K;
            K--;
            int rhs = seg_left.query(1, 0, N - 1, K, N - 1) - K;
            int lhs = seg_right.query(1, 0, N - 1, 0, K) - (N - 1 - K);
            cout << min(lhs, rhs) << endl;
        }
    }

    return 0;
}
