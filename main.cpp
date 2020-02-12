#include <iostream>
//#include <algorithm>

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
    /*int heap;
    for (int k = 0; k < n; ++k) {
        heap = 0;
        heap += a[k];
        for (int i = 0; i < n - k; ++i) {
            heap += a[i];
            if (heap >= sum / 2) break;
        }
        diff = min(diff, abs(heap - (sum - heap)));
    }*/
    for (int i = (1 << (n - 1)) - 1; i >= 0; --i) {
        int heap = 0;

        for (int j = 0; j < n; ++j)
            if (i & (1 << j)) heap += a[j];
            else heap -= a[j];

        diff = min(diff, abs(heap));
//        cout << i << " " << heap << endl;
    }
    cout << endl << diff;
    return 0;
}
