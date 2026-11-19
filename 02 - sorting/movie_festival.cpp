#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

/*
SOLUTION

order movies by <end, start>; let the answer[i] = # of movies watchable where i is the last movie watched
for any movie, if the start comes after every end, then watching only this movie gives us an answer of 1
o/w, find the maximum number of prior movies that are watchable and add 1
the final answer then becomes the maximum of all answers
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<pii> movies(N); // end, start
    for (int i = 0; i < N; i++) cin >> movies[i].second >> movies[i].first;
    sort(movies.begin(), movies.end());

    vector<int> answer(N, 0), max_ans(N, 0);
    answer[0] = max_ans[0] = 1;
    for (int i = 1; i < N; i++) {
        // find largest idx s.t. end at idx <= start at i
        if (movies[0].first > movies[i].second) {
            answer[i] = 1;
            max_ans[i] = max(max_ans[i - 1], answer[i]);
            continue;
        }
        int low = 0, high = i - 1;
        while (low < high) {
            int mid = (low + high + 1) / 2;
            if (movies[mid].first <= movies[i].second) low = mid;
            else high = mid - 1;
        }
        // set new ans and max
        answer[i] = max_ans[low] + 1;
        max_ans[i] = max(max_ans[i - 1], answer[i]);
    }
    cout << max_ans.back() << endl;

    return 0;
}