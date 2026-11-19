#include <bits/stdc++.h>
using namespace std;

/*
SOLUTION

obvious idea is dfs with backtracking, but that naively TLEs (order of 3^48)
pruning / optimization ideas:
- do not store current path or paths as overhead memory; only store visited as const size boolean array
- if S forces a direction, take it immediately
- prune if only up/down pair is visitable OR only left/right pair is visitable like this:
    [ ] [X] [ ]
    [<] [O] [>]
    [ ] [X] [ ]
- prune if only two adjacent directions are visitable AND a blocker exists like this:
    [ ] [^] [X]
    [X] [O] [>]
    [ ] [X] [ ]
*/

int ans = 0;
string S;
bool visited[7][7];
const int PATH_LENGTH = 48;

void generate_paths(int step, int x, int y, int px = 0, int py = -1) {
    if (step == PATH_LENGTH && x == 6 && y == 0) {
        ans++;
        return;
    }
    if (x == 6 && y == 0) return;
    if (step == PATH_LENGTH) return;

    // forced direction by S
    if (S[step] != '?') {
        int dx, dy;
        if (S[step] == 'L') {
            dx = 0;
            dy = -1;
        }
        else if (S[step] == 'U') {
            dx = -1;
            dy = 0;
        }
        else if (S[step] == 'R') {
            dx = 0;
            dy = 1;
        }
        else {
            dx = 1;
            dy = 0;
        }
        if (x + dx >= 0 && x + dx < 7 && y + dy >= 0 && y + dy < 7 && !visited[x + dx][y + dy]) {
            visited[x + dx][y + dy] = true;
            generate_paths(step + 1, x + dx, y + dy, x, y);
            visited[x + dx][y + dy] = false;
        }
        return;
    }
    
    // prune if only two opposite directions are visitable
    int visitable = 0;
    for (int k = 0; k < 4; k++) {
        int dx = (k - 2) % 2, dy = (k - 1) % 2;
        if (x + dx >= 0 && x + dx < 7 && y + dy >= 0 && y + dy < 7 && !visited[x + dx][y + dy]) {
            visitable |= (1 << k);
        }
    }
    if (visitable == 5 || visitable == 10) return;

    // prune if two adjacent directions are visitable but a blocker is present
    if (step >= 1) {
        int prev_x = x - px, prev_y = y - py;
        char c;
        if (prev_x == 0 && prev_y == -1) c = 'L';
        else if (prev_x == -1 && prev_y == 0) c = 'U';
        else if (prev_x == 0 && prev_y == 1) c = 'R';
        else c = 'D';
        if (c == 'L' || c == 'U') {
            if (visitable == 3 && visited[x - 1][y - 1]) return;
        }
        if (c == 'U' || c == 'R') {
            if (visitable == 6 && visited[x - 1][y + 1]) return;
        }
        if (c == 'R' || c == 'D') {
            if (visitable == 12 && visited[x + 1][y + 1]) return;
        }
        if (c == 'D' || c == 'L') {
            if (visitable == 9 && visited[x + 1][y - 1]) return;
        }
    }
    
    // dfs w/ backtracking
    for (int k = 0; k < 4; k++) {
        if (visitable & (1 << k)) {
            int dx = (k - 2) % 2, dy = (k - 1) % 2;
            visited[x + dx][y + dy] = true;
            generate_paths(step + 1, x + dx, y + dy, x, y);
            visited[x + dx][y + dy] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> S;
    visited[0][0] = true;
    generate_paths(0, 0, 0);
    cout << ans << endl;

    return 0;
}