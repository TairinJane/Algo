#include <iostream>
#include <cmath>

using namespace std;

struct Sign {
    int count;
    int id;
};

int signs() {

    int n;
    cin >> n;
    Sign signs[n];
    int min_value = 10001;
    int max_value = 0;
    int min_i = -1;
    int max_i = -1;

    for (int i = 0; i < n; ++i) {
        cin >> signs[i].count;
        signs[i].id = i + 1;
        if (signs[i].count >= max_value) {
            max_value = signs[i].count;
            max_i = i;
        }
        if (signs[i].count < min_value) {
            min_value = signs[i].count;
            min_i = i;
        }
    }

    while (min_i != max_i && min_value != INT_MAX) {
        cout << signs[max_i].id << " " << signs[min_i].id << " ";
        signs[max_i].count--;
        signs[min_i].count--;
        min_value = INT_MAX;
        max_value = -1;
        for (int i = 0; i < n; ++i) {
            if (signs[i].count != 0 && signs[i].count >= max_value) {
                max_value = signs[i].count;
                max_i = i;
            }
            if (signs[i].count != 0 && signs[i].count < min_value) {
                min_value = signs[i].count;
                min_i = i;
            }
        }
    }

    for (int i = 0; i < max_value; ++i) {
        cout << signs[max_i].id << " ";
        signs[max_i].count--;
    }

    return 0;
}
