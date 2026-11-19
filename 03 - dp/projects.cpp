#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

/*
SOLUTION

this is a scheduling problem, so first sort all tasks by end time, then start time, then amount
for each task i, find the last task in order j s.t. end time for j < start time for i
the best option at or before j can be found by taking a prefix max; use that to get i's best profit, then update the prefix max
*/

struct Project {
    ll a, b, p;
    Project(ll a, ll b, ll p) : a(a), b(b), p(p) {}
    bool operator<(Project other) {
        if (this->b != other.b) return this->b < other.b;
        if (this->a != other.a) return this->a < other.a;
        return this->p < other.p;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll N;
    cin >> N;
    vector<Project> projects;
    for (ll i = 0; i < N; i++) {
        ll a, b, p;
        cin >> a >> b >> p;
        projects.push_back(Project(a, b, p));
    }
    sort(projects.begin(), projects.end());

    vector<ll> profit(N, 0), max_profit(N, 0);
    profit[0] = projects[0].p;
    max_profit[0] = projects[0].p;

    for (ll i = 1; i < N; i++) {
        // get last project where ending < this one's starting
        if (projects[0].b >= projects[i].a) {
            profit[i] = projects[i].p;
        }
        else {
            ll low = 0, high = i - 1;
            while (low < high) {
                ll mid = (low + high + 1) / 2;
                if (projects[mid].b < projects[i].a) low = mid;
                else high = mid - 1;
            }
            profit[i] = max_profit[low] + projects[i].p;
        }

        // set the max profit
        max_profit[i] = max(max_profit[i - 1], profit[i]);
    }
    cout << max_profit[N - 1] << endl;

    return 0;
}