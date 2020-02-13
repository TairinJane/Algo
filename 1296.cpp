#include <iostream>
#include <algorithm>

using namespace std;

int hyper_loop() {

    int n;
    cin >> n;
    long int max_sum = 0;
    long int current_max = 0;

    for (int i = 0; i < n; ++i) {
        long int p;
        cin >> p;
        if (current_max + p < 0) {
            current_max = 0;
        } else current_max += p;
        max_sum = max(max_sum, current_max);
    }
    cout << max_sum;
    return 0;
}
