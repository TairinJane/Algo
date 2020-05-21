#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main() {
    int vector_size = 32;

    long int n, k;
    cin >> n >> k;
    int v_length = n / vector_size + 1;
    vector<long int> v[v_length];
    for (int i = 0; i < v_length; ++i) {
        for (int j = 1; j <= vector_size && vector_size * i + j <= n; ++j) {
            v[i].push_back(vector_size * i + j);
        }
    }

    for (auto &j : v) {
        for (long i : j) {
            cout << i << " ";
        }
        cout << endl;
    }

    long int current_i = 1;

    while (n > 0) {
        current_i = (current_i + k - 1) % n;
        if (current_i == 0) current_i = n;
//        cout << "size: " << n << endl;
//        cout << "current: " << current_i << endl;
        int v_index = 0;
        int index = current_i;
        while (index > v[v_index].size()) {
            cout << "current index: " << index << endl;
            index -= v[v_index].size();
            v_index++;
        }
        cout << "current index: " << index << endl;

        cout << v[v_index][index - 1] << endl;
        v[v_index].erase(v[v_index].cbegin() + index - 1);
        n--;
    }

    return 0;
}