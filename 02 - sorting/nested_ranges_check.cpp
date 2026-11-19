#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

/*
SOLUTION

sort the array in ascending order by first index and descending order by second index, process right to left
keep some set which has what y values you have currently found
contains:       - never delete from the set, update the answer for the current answer only
is_contained:   - delete from the set when some interval finds a later one which engulfs it
                - set also include indices for each y value
undo the sorting at the start to get the answers for the original array
*/

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

    vector<bool> contains(N, false);
    set<int> found;
    for (int i = N - 1; i >= 0; i--) {
        auto it = found.upper_bound(sorted[i].second);
        if (it != found.begin()) contains[i] = true;
        found.insert(sorted[i].second);
    }
    contains = apply(inv, contains);

    vector<bool> is_contained(N, false);
    set<pii> vi;
    for (int i = N - 1; i >= 0; i--) {
        auto it = vi.upper_bound({sorted[i].second, N});
        if (it != vi.begin()) {
            vector<pii> garbage;
            for (it--; ; it--) {
                is_contained[(*it).second] = true;
                garbage.push_back(*it);
                if (it == vi.begin()) break;
            }
            for (pii p : garbage) vi.erase(p);
        }
        vi.insert({sorted[i].second, i});
    }
    is_contained = apply(inv, is_contained);

    for (int i = 0; i < N; i++) cout << contains[i] << " \n"[i + 1 == N];
    for (int i = 0; i < N; i++) cout << is_contained[i] << " \n"[i + 1 == N];

    return 0;
}