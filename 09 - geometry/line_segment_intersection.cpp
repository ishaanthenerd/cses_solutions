#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
SOLUTION

part 1 (setup)
dot takes the dot product, cross takes the cross product (can take a third parameter which is the origin)
on segment checks if a third point sits on the line segment that p1 / p2 make; it checks for (1) a cross product of zero between two vectors and (2) a dot product that is <= 0 (indicates the third point is in between the endpts)

part 2 (actual solve)
for each point, compute the cross product from the other segment to it (i.e. if p3 o---o p4 & using p1, compute (p1 - p3) X (p4 - p3))
check if both pairs of signs (p1 / p2 pair and p3 / p4 pair) are opposites; if so, then there is an intersection the "normal" way
to get the intersection point, remember the px = t * p1 + (1 - t) * p2 characterization for a line segment? we want to pick a t s.t. (px - p3) X (p4 - p3) = 0 --> solve and plug in t to get the formula used
if there is no "normal" intersection, then check if any point sits on the other segment; if so, then done, and o/w/, there is no common point between both segments
*/

double sign(double x) { return (x > 0) - (x < 0); }

template <typename T>
struct Point {
    T x, y;
    Point(T x = 0, T y = 0) : x(x), y(y) {}
    Point operator-(const Point other) const { return Point(this->x - other.x, this->y - other.y); }
    Point operator*(const T other) const { return Point(this->x * other, this->y * other); }
    static T dot(Point p1, Point p2) { return p1.x * p2.x + p1.y * p2.y; }
    static T cross(Point p1, Point p2) { return p1.x * p2.y - p2.x * p1.y; } 
    static T cross(Point p1, Point p2, Point o) { return Point<T>::cross(p1 - o, p2 - o); }
    static bool onSegment(Point p1, Point p2, Point x) { return Point<T>::cross(p1, p2, x) == 0 && Point<T>::dot(p1 - x, p2 - x) <= 0; }
};

void solve() {
    double x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    Point<double> p1(x1, y1), p2(x2, y2), p3(x3, y3), p4(x4, y4);
    double c1 = Point<double>::cross(p4, p1, p3), c2 = Point<double>::cross(p4, p2, p3);
    double c3 = Point<double>::cross(p2, p3, p1), c4 = Point<double>::cross(p2, p4, p1);

    if (sign(c1) * sign(c2) < 0 && sign(c3) * sign(c4) < 0) {
        Point<double> kousaten = (p1 * c2 - p2 * c1) * (1 / (c2 - c1));
        double ep = 1e-6;
        bool cond = (min(x1, x2) - ep <= kousaten.x && kousaten.x <= max(x1, x2) + ep && min(x3, x4) - ep <= kousaten.x && kousaten.x <= max(x3, x4) + ep); // fp error w/o epsilon!
        cout << (cond ? "YES" : "NO") << endl;
    }
    else {
        bool cond = (Point<double>::onSegment(p3, p4, p1) || Point<double>::onSegment(p3, p4, p2) || Point<double>::onSegment(p1, p2, p3) || Point<double>::onSegment(p1, p2, p4));
        cout << (cond ? "YES" : "NO") << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}