#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

struct Sign {
    int count;
    int id;
};

int main() {

    int n;
    cin >> n;
    Sign signs[n];

    for (int i = 0; i < n; ++i) {
        cin >> signs[i].count;
        signs[i].id = i + 1;
    }

    sort(signs, signs + n, [](Sign a, Sign b) { return a.count > b.count; });

    int i = 0;
    int j;
    while (i < n) {
        if (signs[i].count == 0) i++;
        else {
            cout << signs[i].id << " (i = " << i << ") ";
            signs[i].count--;
            j = n - 1;
            while (signs[j].count == 0 && j > 0) j--;
            if (signs[j].count != 0 && j >= 0) {
                cout << signs[j].id << " (j = " << j << ") ";
                signs[j].count--;
            }
            if (signs[i].count == 0) i++;
        }
    }

    return 0;
}
