#include <bits/stdc++.h>
using namespace std;
 
/*
SOLUTION

use a segtree on line container and win
*/

// start of templ

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};
 
struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	static const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) return x->p = inf, 0;
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
		if (empty()) return LLONG_MIN;
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};
 
// end of templ
 
struct STLC {
    int n;
    vector<LineContainer> a, st;
    STLC(int n) : n(n), a(n), st(4 * n) {}
    
    void update(ll slope, ll intercept, int start, int end, int pos = 1, int left = 0, int right = -1) {
        if (right == -1) right += n;
        if (end < left || right < start) return;
        if (start <= left && right <= end) {
            st[pos].add(slope, intercept);
        }
        else {
            int mid = (left + right) / 2;
            update(slope, intercept, start, end, 2 * pos, left, mid);
            update(slope, intercept, start, end, 2 * pos + 1, mid + 1, right);
        }
    }
    
    ll query(int x) {
        int pos = 1, left = 0, right = n - 1;
        ll ans = LLONG_MIN;
        while (left < right) {
            ans = max(ans, st[pos].query(x));
            int mid = (left + right) / 2;
            if (x <= mid) {
                right = mid;
                pos = 2 * pos;
            }
            else {
                left = mid + 1;
                pos = 2 * pos + 1;
            }
        }
        ans = max(ans, st[pos].query(x));
        return ans;
    } 
};
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    STLC cope(100001);
    int N;
    cin >> N;
    while (N--) {
        int T;
        cin >> T;
        if (T == 1) {
            ll A, B;
            int L, R;
            cin >> A >> B >> L >> R;
            cope.update(A, B, L, R);
        }
        else {
            int X;
            cin >> X;
            ll ans = cope.query(X);
            if (ans == LLONG_MIN) cout << "NO" << endl;
            else cout << ans << endl;
        }
    }
    
    return 0;
}