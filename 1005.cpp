#include <iostream>

using namespace std;

int rock_heaps() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int diff = INT_MAX;
    for (int i = (1 << n) - 1; i >= 0; --i) {
        int heap = 0;

        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) heap += a[j];
            else heap -= a[j];
        }
        diff = min(diff, abs(heap));
    }
    cout << endl << diff;
    return 0;
}
