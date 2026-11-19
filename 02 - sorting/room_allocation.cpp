#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
 
/*
SOLUTION

process guests in sorted order
when a guest arrives, find the room that is (1) available and (2) has the least down time
place the guest there OR allocate a new room for them
*/

template <typename T>
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
    vector<pii> arr(N); // end, start
    for (int i = 0; i < N; i++) cin >> arr[i].second >> arr[i].first;
    
    vector<int> order(N);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int a, int b) {
        return arr[a] < arr[b];
    });
    vector<pii> sorted = apply(order, arr);
    vector<int> inv(N);
    for (int i = 0; i < N; i++) inv[order[i]] = i;
    
    vector<int> ans;
    set<pii> rooms;
    for (pii p : sorted) {
        int start = p.second, end = p.first;
        if (rooms.size() == 0 || start <= (*rooms.begin()).first) {
            ans.push_back(rooms.size() + 1);
            rooms.insert({end, rooms.size() + 1});
        }
        else {
            auto it = --rooms.lower_bound({start, 0});
            pii old_room = *it;
            ans.push_back(old_room.second);
            rooms.erase(it);
            rooms.insert({end, old_room.second});
        }
    }
    
    ans = apply(inv, ans);
    cout << rooms.size() << endl;
    for (int i = 0; i < N; i++) cout << ans[i] << " \n"[i + 1 == N];
    
    return 0;
}