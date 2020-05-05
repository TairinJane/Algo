#include <iostream>
#include <list>

using namespace std;

int soldiers() {

    long int n, k;
    cin >> n >> k;
    list<long int> list;
    for (int i = 1; i <= n; ++i) {
        list.push_back(i);
    }

    auto current = list.begin();
    long int current_i = 1;

    while (!list.empty()) {
        current_i = (current_i + k - 1) % n;
        if (current_i == 0) current_i = n;
//        cout << "size: " << n << endl;
//        cout << "current: " << current_i << endl;
        current = list.begin();
        for (int l = 1; l < current_i; ++l) {
            current++;
        }
        cout << *current << endl;
        list.erase(current);
        n--;
    }

    return 0;
}
