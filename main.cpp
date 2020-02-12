#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
//    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
//        sum += a[i];
    }
//    sort(a, a + n, greater<>());
    int diff = INT_MAX;
    for (int i = (1 << n) - 1; i >= 0; --i) {
        int heap = 0;

        for (int j = 0; j < n; ++j) {
            cout << " " << i << " " << j << " " << (1 << j) << " " << (i & (1 << j)) << endl;
            if (i & (1 << j)) heap += a[j];
            else heap -= a[j];
        }
        diff = min(diff, abs(heap));
        cout << i << " " << heap << " " << diff << endl;
    }
    cout << endl << diff;
    return 0;
}
