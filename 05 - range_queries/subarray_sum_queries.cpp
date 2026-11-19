#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

/*
SOLUTION

use a Node for each interval in the segtree
each Node stores the current sum, the best prefix, the best suffix, and the best subarray sum (either left end's subarray sum, right end's subarray sum, or the best left suffix + best right prefix)
*/

struct Node {
    ll sum, prefix, suffix, ans;
    Node(ll x = 0) { 
        sum = x;
        prefix = suffix = ans = max(0LL, x);
    }
    Node(ll sum, ll prefix, ll suffix, ll ans) : sum(sum), prefix(prefix), suffix(suffix), ans(ans) {}
};

Node combine(Node x, Node y) {
    return Node(
        x.sum + y.sum,
        max(x.prefix, x.sum + y.prefix),
        max(y.suffix, y.sum + x.suffix),
        max(max(x.ans, y.ans), x.suffix + y.prefix)  
    );
}

template <typename T>
struct ST {
    int n;
    vector<T> a, st;
    ST(vector<T> b) : n(b.size()), a(b) {
        st.assign(4 * n, Node());
        for (int i = 0; i < n; i++) update(1, 0, n - 1, i, a[i]);
    }
    T f(T x, T y) { return combine(x, y); }

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
        if (ql > right || qr < left) return Node(); // default
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
    vector<ll> X(N);
    for (int i = 0; i < N; i++) cin >> X[i];
    vector<Node> nodes;
    for (int i = 0; i < N; i++) nodes.push_back(Node(X[i]));
    ST<Node> seg(nodes);

    while (M--) {
        int K, V;
        cin >> K >> V;
        K--;
        seg.update(1, 0, seg.n - 1, K, Node(V));
        cout << seg.st[1].ans << endl;
    }

    return 0;
}