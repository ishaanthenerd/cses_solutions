#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

/*
SOLUTION

for each mountain M, there is a leftmost and rightmost mountain up until which can be explored in one visit
compute the left/right mountains using monotonic stack
use a segtree to store updates to dp / query on maximum of the range
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

    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; i++) cin >> H[i];

    vector<int> forward(N, N), backward(N, -1);
    stack<int> mono;
    for (int i = 0; i < N; i++) {
        while (mono.size() >= 1 && H[mono.top()] <= H[i]) {
            forward[mono.top()] = i;
            mono.pop();
        }
        mono.push(i);
    }
    while (mono.size() >= 1) mono.pop();
    for (int i = N - 1; i >= 0; i--) {
        while (mono.size() >= 1 && H[mono.top()] <= H[i]) {
            backward[mono.top()] = i;
            mono.pop();
        }
        mono.push(i);
    }

    vector<int> order(N);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](const int i, const int j) {
        return H[i] < H[j];
    });

    ST<int> dp(vector<int>(N, 0));
    for (int i : order) {
        dp.update(1, 0, N - 1, i, 1 + dp.query(1, 0, N - 1, backward[i] + 1, forward[i] - 1));
    }
    cout << dp.st[1] << endl;

    return 0;
}