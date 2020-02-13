#include <iostream>

using namespace std;

int teams_fight() {

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n, k;
        cin >> n >> k;
        int full = n / k;
        int r = n % k;
        // n - full - участников, с которыми драться чувакам из команд с f + 1
        // таких (f+1)*r
        // n - f + 1 - кол-во противников для чуваков из групп поменьше (f)
        // таких n - (f+1)*r
        // всех учли 2 раза, делим обратно
        int max = ((n - (full + 1) * r) * (n - full) + (r * (full + 1)) * (n - full - 1)) / 2;
        cout << max << endl;
    }
    return 0;
}
