#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;

/*
SOLUTION

use a segtree on a node storing the sum + best prefix on the interval
make sure to change (1) initialization, (2) f, and (3) default!
*/

template <typename T>
struct ST {
    int n;
    vector<T> a, st;
    ST(vector<T> b) : n(b.size()), a(b) {
        st.assign(4 * n, T(0, 0));
        for (int i = 0; i < n; i++) update(1, 0, n - 1, i, a[i]);
    }
    T f(T x, T y) { return T(x.sum + y.sum, max(x.prefix, x.sum + y.prefix)); }

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
        if (ql > right || qr < left) return T(0, 0); // default
        if (ql <= left && right <= qr) return st[pos];
        int mid = (left + right) / 2;
        return f(query(2 * pos, left, mid, ql, qr), query(2 * pos + 1, mid + 1, right, ql, qr));
    }
};

struct Node {
    ll sum, prefix;
    Node(ll sum, ll prefix) : sum(sum), prefix(prefix) {}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll N, Q;
    cin >> N >> Q;
    vector<Node> starter;
    for (ll i = 0; i < N; i++) {
        ll x;
        cin >> x;
        starter.push_back(Node(x, max(0LL, x)));
    }
    ST<Node> seg(starter);

    while (Q--) {
        ll T;
        cin >> T;
        if (T == 1) {
            ll K, U;
            cin >> K >> U;
            seg.update(1, 0, seg.n - 1, --K, Node(U, max(0LL, U)));
        }
        else {
            ll A, B;
            cin >> A >> B;
            cout << seg.query(1, 0, seg.n - 1, --A, --B).prefix << endl;
        }
    }

    return 0;
}