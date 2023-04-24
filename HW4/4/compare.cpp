#include "compare.h"
#include "point.h"

int CompareInt::sum(int x) {
    int ans = 0;
    for (; x; ans += x % 10, x /= 10);
    return ans;
}
bool CompareInt::compare(int a, int b) {
    if (type_ == 1) {
        return a < b;
    } else {
        int x = sum(a), y = sum(b);
        return x == y ? a < b : x < y;
    }
}
int ComparePoint::dist(Point a) {
    return a.x * a.x + a.y * a.y;
}

bool operator<(const Point &a, const Point &b) {
    return a.x == b.x ? a.y < b.y : a.x < b.x;
}
bool ComparePoint::compare(Point a, Point b) {
    if (type_ == 3) {
        return a < b;
    } else {
        int x = dist(a), y = dist(b);
        return x == y ? a < b : x < y;
    }

}

AbstractCompare<int>* get_compare_int(int type) {
    return new CompareInt(type);
}
AbstractCompare<Point>* get_compare_point(int type) {
    return new ComparePoint(type);
}