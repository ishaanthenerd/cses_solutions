#include <bits/stdc++.h>
using namespace std;
 
/*
SOLUTION

use a line container and win
*/

// start of template code
 
#define rep(i,a,b) for(int i=a; i<(b); ++i)
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#pragma once
 
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
	    if (empty()) return -1;
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};
 
// end of template code
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    LineContainer lc;
    while (N--) {
        int T;
        cin >> T;
        if (T == 1) {
            ll A, B;
            cin >> A >> B;
            lc.add(A, B);
        }
        else {
            ll X;
            cin >> X;
            cout << lc.query(X) << endl;
        }
    }
    
    return 0;
}