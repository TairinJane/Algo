#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {

    long int n;
    cin >> n;
    long int x[n];
    long int y[n];
    long long int sum = 0;

    for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];
    sort(x, x + n);
    sort(y, y + n);

    for (int i = 1; i < n; ++i) {
        sum += ((x[i] - x[i - 1]) + (y[i] - y[i - 1])) * i * (n - i) * 2;
    }

    sum /= n * (n - 1);

    cout << sum;
    return 0;
}
