#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
 
/*
SOLUTION

part 1
recognize that an op done on [C, D] involves doing a negative op on [0, C - 1] and a positive one on [0, D]
split them into negative / positive maps from value --> list of (A, B, query_idx)
at each query value (C - 1 or D), set the statuses of the unadded elements that are now <= the value to 1 
(this can be done by taking a set and using lower_bound on each element of the original array, then storing value --> list of next to add)
to resolve the query, take a range sum from A to B (this requires a segtree)

part 2
sets / maps have bad constant factor, so to work around it...
- have a query list w/ both update and range sum queries (to be handled after updates for the same (C - 1 or D) value!)
- have a process list w/ {(C - 1 or D), A, B, query_idx, +/- 1}
- go through the query list in order; updates are free; use a variable to keep track of the current range sum query that is not resolved, then solve it until the first list value is no longer equal to the query value
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

    vector<vector<int>> queries(Q, vector<int>(4));
    for (int i = 0; i < Q; i++) {
        int A, B, C, D;
        cin >> A >> B >> C >> D;
        A--;
        B--;
        C--;
        queries[i] = {A, B, C, D};
    }

    vector<pii> query_list;
    for (int i = 0; i < N; i++) query_list.push_back({X[i], i});
    for (int i = 0; i < Q; i++) {
        query_list.push_back({queries[i][2], INT_MAX});
        query_list.push_back({queries[i][3], INT_MAX});
    }
    sort(query_list.begin(), query_list.end());

    vector<vector<int>> process_list;
    for (int i = 0; i < Q; i++) {
        process_list.push_back({queries[i][2], queries[i][0], queries[i][1], i, -1});
        process_list.push_back({queries[i][3], queries[i][0], queries[i][1], i, 1});
    }
    sort(process_list.begin(), process_list.end());

    int process_idx = 0;
    vector<int> ans(Q, 0);
    ST<int> seg(vector<int>(N, 0));
    for (pii p : query_list) {
        if (p.second != INT_MAX) {
            seg.update(1, 0, N - 1, p.second, 1);
        }
        else {
            while (process_idx < 2 * Q && process_list[process_idx][0] == p.first) {
                int delta = seg.query(1, 0, N - 1, process_list[process_idx][1], process_list[process_idx][2]);
                ans[process_list[process_idx][3]] += process_list[process_idx][4] * delta;
                process_idx++;
            }
        }
    }
    for (int final_ans : ans) cout << final_ans << endl;

    return 0;
}