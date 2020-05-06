#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main() {
    int m, n, k;
    cin >> m >> n >> k;

    vector<pair<int, int>> points;
    points.emplace_back(1, 0);
    for (int i = 0; i < k; ++i) {
        int a, b;
        cin >> a >> b;
        points.emplace_back(a, b);
    }
    points.emplace_back(m, n + 1);

    sort(points.begin(), points.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.first == b.first ? a.second < b.second : a.first < b.first;
    });

    for (auto &point : points) {
        cout << point.first << " " << point.second << endl;
    }

    int dj, di;
    int count = 0;
    int isolated_count = 0;
    vector<pair<int, int>> isolated;
    for (int i = 0; i < points.size() - 1; ++i) {
        dj = points[i + 1].second - points[i].second;
        di = points[i + 1].first - points[i].first;
        cout << "di: " << di << ", dj: " << dj << endl;
        if (di == 0) {
            if (dj > 2) count++;
            else if (dj == 2) isolated.emplace_back(points[i].first, points[i].second + 1);
        } else {
            int wall = n - points[i].second;
            if (wall > 0) {
                if (wall == 1) isolated.emplace_back(points[i].first, points[i].second + 1);
                else count++;
            }
            if (points[i + 1].second > 1) {
                if (points[i + 1].second == 2) isolated.emplace_back(points[i + 1].first, 1);
                else count++;
            }
            if (di > 1) count += (di - 1);
        }
        cout << "count by dj: " << count << endl;
    }
    cout << "count by dj: " << count << endl;

    sort(points.begin(), points.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second == b.second ? a.first < b.first : a.second < b.second;
    });
    points[0].first = 0;
    points[0].second = 1;
    points[k + 1].first = m + 1;
    points[k + 1].second = n;

    for (auto &point : points) {
        cout << point.first << " " << point.second << endl;
    }

    for (int i = 0; i < points.size() - 1; ++i) {
        dj = points[i + 1].second - points[i].second;
        di = points[i + 1].first - points[i].first;
        cout << "di: " << di << ", dj: " << dj << endl;
        if (dj == 0) {
            if (di > 1) {
                if (di == 2) isolated.emplace_back(points[i].first + 1, points[i].second);
                else count++;
            }
        } else {
            int wall = m - points[i].first;
            if (wall > 0) {
                if (wall == 1) isolated.emplace_back(points[i].first + 1, points[i].second);
                else count++;
            }
            wall = points[i + 1].first - 1;
            if (wall > 0) {
                if (wall == 1) isolated.emplace_back(1, points[i + 1].second);
                else count++;
            }
            if (dj > 1) count += (dj - 1);
        }
        cout << "count by di: " << count << endl;
    }
    cout << endl << "count: " << count << endl;

    for (auto &point : isolated) {
        cout << point.first << " " << point.second << endl;
    }

    set<pair<int, int>> unique(isolated.begin(), isolated.end());
    cout << endl << "unique:" << endl;
    for (auto &point : unique) {
        cout << point.first << " " << point.second << endl;
    }
    count += (int) (isolated.size() - unique.size());

    cout << endl << "count + isolated: " << count << endl;


    return 0;
}