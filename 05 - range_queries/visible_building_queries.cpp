#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
 
/*
SOLUTION

idea: each building has some first building to its left that blocks it; compute these w/ a monotonic stack
process the queries offline (sorted order)
for each query, if the left endpoint comes forward, delete each building from the old to the new left; update the later buildings that need it accordingly (set visible status from 0 to 1); then compute the sum on the query range
use a segtree to process the above updates / sums
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
    vector<int> H(N);
    for (int i = 0; i < N; i++) cin >> H[i];
    vector<pii> queries(Q);
    for (int i = 0; i < Q; i++) cin >> queries[i].first >> queries[i].second;

    vector<int> query_order(Q);
    iota(query_order.begin(), query_order.end(), 0);
    sort(query_order.begin(), query_order.end(), [&](int x, int y) {
        return queries[x] < queries[y];
    });
    
    vector<int> first_left_ge(N, -1);
    stack<int> mono;
    for (int i = N - 1; i >= 0; i--) {
        while (mono.size() >= 1 && H[i] >= H[mono.top()]) {
            first_left_ge[mono.top()] = i;
            mono.pop();
        }
        mono.push(i);
    }
    map<int, vector<int>> release;
    for (int i = 0; i < N; i++) if (first_left_ge[i] != -1) release[first_left_ge[i]].push_back(i);

    vector<int> blank(N, 0);
    for (int i = 0; i < N; i++) if (first_left_ge[i] == -1) blank[i] = 1;
    ST<int> seg(blank);

    vector<int> ans(Q, 0);
    int first_incl = 0;
    for (int i : query_order) {
        int A = queries[i].first - 1, B = queries[i].second - 1;
        if (A > first_incl) {
            for (int j = first_incl; j < A; j++) {
                for (int k : release[j]) {
                    seg.update(1, 0, N - 1, k, 1);
                }
            }
            first_incl = A;
        }
        ans[i] = seg.query(1, 0, N - 1, A, B);
    }
    for (int i = 0; i < Q; i++) cout << ans[i] << endl;

    return 0;
}
