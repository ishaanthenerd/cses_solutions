#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
SOLUTION

use left-casted ray from the desired Point (right-casted will work too)
if it crosses an even # of edges, it's outside, o/w it's inside
handle BOUNDARY by checking both strictly inside and loosely inside
*/

double sign(double x) { return (x > 0) - (x < 0); }

template <typename T>
struct Point {
    T x, y;
    Point(T x = 0, T y = 0) : x(x), y(y) {}
    Point operator-(const Point other) const { return Point(this->x - other.x, this->y - other.y); }
    Point operator*(const T other) const { return Point(this->x * other, this->y * other); }
    bool operator<(const Point other) const { return this->x < other.x && this->y < other.y; }
    static T dot(Point p1, Point p2) { return p1.x * p2.x + p1.y * p2.y; }
    static T cross(Point p1, Point p2) { return p1.x * p2.y - p2.x * p1.y; } 
    static T cross(Point p1, Point p2, Point o) { return Point<T>::cross(p1 - o, p2 - o); }
    static bool onSegment(Point p1, Point p2, Point x) { return Point<T>::cross(p1, p2, x) == 0 && Point<T>::dot(p1 - x, p2 - x) <= 0; }
};

bool inside(vector<Point<double>> polygon, Point<double> P, bool strict) {
    bool crossed = false;
    int n = polygon.size();
    for (int i = 0; i < n; i++) {
        Point<double> p1 = polygon[i], p2 = polygon[i + 1 - n * (i + 1 == n)];
        if (Point<double>::onSegment(p1, p2, P)) return !strict;
        crossed ^= (((P.y < p1.y) - (P.y < p2.y)) * sign(Point<double>::cross(p1, p2, P))) > 0; // reversing this is fine too
    }
    return crossed;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    vector<Point<double>> pts;
    for (int i = 0; i < N; i++) {
        double A, B;
        cin >> A >> B;
        pts.push_back(Point(A, B));
    }
    while (M--) {
        double A, B;
        cin >> A >> B;
        Point P(A, B);
        bool cond1 = inside(pts, P, false), cond2 = inside(pts, P, true);
        if (cond1 && cond2) cout << "INSIDE" << endl;
        else if (cond1 ^ cond2) cout << "BOUNDARY" << endl;
        else cout << "OUTSIDE" << endl;
    }

    return 0;
}