#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

struct Point {
    int x;
    int y;
    double angle;
    int id;
};

int mediana() {

    int n;
    cin >> n;
    Point min_point = {1000001, 1000001, 0, 0};
    int first_point_i = 0;

    Point points[n];

    for (int i = 0; i < n; ++i) {
        cin >> points[i].x >> points[i].y;
        points[i].id = i + 1;
        if (points[i].x < min_point.x || (points[i].x == min_point.x && points[i].y < min_point.y)) {
            min_point = points[i];
            first_point_i = i;
        }
    }

    Point temp = points[first_point_i];
    points[first_point_i] = points[0];
    points[0] = temp;
    first_point_i = points[0].id;

    for (int i = 1; i < n; ++i) {
        points[i].angle = atan2(points[i].y - min_point.y, points[i].x - min_point.x);
    }

    sort(points + 1, points + n, [](Point a, Point b) { return a.angle < b.angle; });

    int second_point_i = points[n / 2].id;

    cout << first_point_i << " " << second_point_i;

    return 0;
}
