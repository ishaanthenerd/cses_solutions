#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
constexpr ll MOD = 1e9 + 7;

/*
SOLUTION

coord compress the values
have a vector<queue<int>> storing value --> queue<indices> (idea: front gets a 1 for being first, rest get 0s)
sort the queries; when the first element of a query moves forward, delete all intermediate indices from their respective queues and move each 1 forward if possible
each range is then a sum; updates / sums can be done with a segtree
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

    int N, Q;
    cin >> N >> Q;
    vector<int> X(N);
    for (int i = 0; i < N; i++) cin >> X[i];
    vector<pii> queries(Q);
    for (int i = 0; i < Q; i++) {
        cin >> queries[i].first >> queries[i].second;
        queries[i] = {queries[i].first - 1, queries[i].second - 1};
    }

    map<int, int> compress;
    for (int i = 0; i < N; i++) compress[X[i]] = 0;
    int cnt = 0;
    for (auto &p : compress) p.second = cnt++;
    for (int i = 0; i < N; i++) X[i] = compress[X[i]];

    int C = compress.size();
    vector<queue<int>> val_to_idx(C);
    for (int i = 0; i < N; i++) val_to_idx[X[i]].push(i);
    ST<int> seg(vector<int>(N, 0));
    for (int i = 0; i < C; i++) {
        if (val_to_idx[i].size() >= 1) {
            seg.update(1, 0, N - 1, val_to_idx[i].front(), 1);
        }
    }

    vector<int> order(Q);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](const int i, const int j) {
        return queries[i] < queries[j];
    });

    vector<int> ans(Q);
    int starting_idx = 0;
    for (int i : order) {
        ll first_idx = queries[i].first, last_idx = queries[i].second;
        if (first_idx > starting_idx) {
            for (int j = starting_idx; j < first_idx; j++) {
                val_to_idx[X[j]].pop();
                if (val_to_idx[X[j]].size() >= 1) seg.update(1, 0, N - 1, val_to_idx[X[j]].front(), 1);
            }
            starting_idx = first_idx;
        }
        ans[i] = seg.query(1, 0, N - 1, first_idx, last_idx);
    }
    for (int i = 0; i < Q; i++) cout << ans[i] << endl;

    return 0;
}