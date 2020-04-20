#include <iostream>
#include <vector>

using namespace std;

struct Sign {
    int count;
    int id;
};

int znaki3() {

    int n;
    cin >> n;
    Sign signs[n];
    int max_value = 0;
    int max_i = -1;
    int total = 0;

    for (int i = 0; i < n; ++i) {
        cin >> signs[i].count;
        signs[i].id = i + 1;
        total += signs[i].count;
        if (signs[i].count > max_value) {
            max_value = signs[i].count;
            max_i = i;
        }
    }

    vector<vector<int>> v;
    total -= max_value;
    signs[max_i].count = 0;
    for (int k = 0; k < max_value; ++k) {
        vector<int> vec;
        vec.push_back(signs[max_i].id);
        v.push_back(vec);
    }

    int j = 0;
    int k = 0;
    while (total > 0 && j < max_value) {
        while (signs[j].count <= 0) j++;
        v[k].push_back(signs[j].id);
        signs[j].count--;
        total--;
        if (++k >= max_value) k = 0;
    }

    for (const vector<int> &vector : v) {
        for (int sign : vector) {
            cout << sign << " ";
        }
    }

    return 0;
}
