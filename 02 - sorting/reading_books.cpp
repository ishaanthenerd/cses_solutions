#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
SOLUTION

if one book X takes at least as long as all of the rest to read, then the answer is 2X (alternate who reads it)
otherwise, the answer is the sum of all books
proof: person A reads from longest to shortest length, person B reads from 2nd longest to shortest, then finishes with the longest book --> this guarantees that their books never line ups
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    multiset<ll> books;
    for (int i = 0; i < N; i++) {
        ll book;
        cin >> book;
        books.insert(book);
    }
    
    ll max_book = *books.rbegin();
    ll sum_book = 0;
    for (ll book : books) sum_book += book;
    cout << max(2 * max_book, sum_book) << endl;

    return 0;
}