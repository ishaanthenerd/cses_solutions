#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

/*
SOLUTION

segtree + coord compress is just BROKEN
actual solution - first sort ascending by first coord, descending by second coord
to count how many ranges are contained w/ some range, go right to left and update segtree w/ y values
to count how many this range is contained in, go left to right w/ the same update
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
};

template<typename T>
vector<T> apply(vector<int> order, vector<T> arr) {
    vector<T> ans(arr.size());
    for (int i = 0; i < arr.size(); i++) ans[i] = arr[order[i]];
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<pii> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i].first >> arr[i].second;
    
    vector<int> order(N);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int a, int b) {
        if (arr[a].first != arr[b].first) return arr[a].first < arr[b].first;
        return arr[a].second > arr[b].second;
    });
    vector<int> inv(N);
    for (int i = 0; i < N; i++) inv[order[i]] = i;
    vector<pii> sorted = apply(order, arr);

    map<int, int> compress;
    for (int i = 0; i < N; i++) compress[sorted[i].second] = 0;
    int cnt = 0;
    for (auto &p : compress) p.second = cnt++;
    int C = compress.size();

    ST<int> seg(vector<int>(C, 0));
    vector<int> contains(N, 0);
    for (int i = N - 1; i >= 0; i--) {
        int y = compress[sorted[i].second];
        contains[i] = seg.query(1, 0, seg.n - 1, 0, y);
        seg.update(1, 0, seg.n - 1, y, seg.a[y] + 1);
    }

    for (int i = 0; i < C; i++) seg.update(1, 0, seg.n - 1, i, 0);
    vector<int> is_contained(N, 0);
    for (int i = 0; i < N; i++) {
        int y = compress[sorted[i].second];
        is_contained[i] = seg.query(1, 0, seg.n - 1, y, seg.n - 1);
        seg.update(1, 0, seg.n - 1, y, seg.a[y] + 1);
    }

    contains = apply(inv, contains);
    is_contained = apply(inv, is_contained);
    for (int i = 0; i < N; i++) cout << contains[i] << " \n"[i + 1 == N];
    for (int i = 0; i < N; i++) cout << is_contained[i] << " \n"[i + 1 == N];
    
    return 0;
}