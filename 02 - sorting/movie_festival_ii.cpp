#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

/*
SOLUTION

sort all movies by earliest ending time, then by earliest starting time
keep track of the ending times for all K people
when a movie is processed, find the person who has the least amount of downtime btwn movies and pick them to watch it; update their ending time with the processed movie ending time
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N >> K;
    vector<pii> movies(N); // end, start
    for (int i = 0; i < N; i++) cin >> movies[i].second >> movies[i].first;
    sort(movies.begin(), movies.end());

    int ans = 0;
    multiset<int> ends;
    for (int i = 0; i < K; i++) ends.insert(0);
    for (int i = 0; i < N; i++) {
        if (movies[i].second < *ends.begin()) continue;
        ans++;
        auto it = --ends.upper_bound(movies[i].second);
        ends.erase(it);
        ends.insert(movies[i].first);
    }
    cout << ans << endl;

    return 0;
}