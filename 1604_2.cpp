#include <iostream>
#include <cmath>

using namespace std;

struct Sign {
    int count;
    int id;
};

int znaki2() {

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

    while (total > 0) {
        cout << signs[max_i].id << " ";
        total--;
        for (int i = 0; i < n; ++i) {
            if (signs[i].count != 0 && i != max_i) {
                cout << signs[i].id << " ";
                signs[i].count--;
                total--;
            }
        }
    }

    return 0;
}
