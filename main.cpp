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
    set<pair<int, int>> isolated;
    for (int i = 0; i < points.size() - 1; ++i) {
        dj = points[i + 1].second - points[i].second;
        di = points[i + 1].first - points[i].first;
        cout << "di: " << di << ", dj: " << dj << endl;
        if (di == 0) {
            if (dj > 2) count++;
            else if (dj == 2) {
                isolated.insert({points[i].first, points[i].second + 1});
                isolated_count++;
            }
        } else {
            int wall = n - points[i].second;
            if (wall > 0) {
                if (wall == 1) {
                    isolated.insert({points[i].first, points[i].second + 1});
                    isolated_count++;
                } else count++;
            }
            if (points[i + 1].second > 1) {
                if (points[i + 1].second == 2) {
                    isolated.insert({points[i + 1].first, 1});
                    isolated_count++;
                } else count++;
            }
            if (di > 1) {
                if (n > 1) count += (di - 1);
                else {
                    isolated.insert({points[i].first + 1, points[i].second});
                    isolated_count++;
                }
            }
        }
        cout << "count by dj: " << count << ", isolated: " << isolated_count << endl;
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
                if (di == 2) {
                    isolated.insert({points[i].first + 1, points[i].second});
                    isolated_count++;
                } else count++;
            }
        } else {
            int wall = m - points[i].first;
            if (wall > 0) {
                if (wall == 1) {
                    isolated.insert({points[i].first + 1, points[i].second});
                    isolated_count++;
                } else count++;
            }
            wall = points[i + 1].first - 1;
            if (wall > 0) {
                if (wall == 1) {
                    isolated.insert({1, points[i + 1].second});
                    isolated_count++;
                } else count++;
            }
            if (dj > 1) {
                if (m > 1) count += (dj - 1);
                else {
                    isolated.insert({points[i].first, points[i].second + 1});
                    isolated_count++;
                }
            }
        }
        cout << "count by di: " << count << ", isolated: " << isolated_count << endl;
    }
    cout << endl << "count: " << count << endl;

    for (auto &point : isolated) {
        cout << point.first << " " << point.second << endl;
    }

    count += (isolated_count - (int) isolated.size());

    cout << endl << "count + isolated: " << count << endl;


    return 0;
}