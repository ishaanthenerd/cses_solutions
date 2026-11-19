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
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};
 
// end of template code
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N, M;
    cin >> N >> M;
    LineContainer lc;
    for (int i = 0; i < N; i++) {
        ll y1, y2;
        cin >> y1 >> y2;
        lc.add((y2 - y1) / M, y1);
    }
    for (int i = 0; i <= M; i++) {
        cout << lc.query(i) << " \n"[i == M];
    }
    
    return 0;
}