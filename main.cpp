#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int get_by_index(int tree[], int index, int border) {
    int cur = 1;
    cout << "cur: " << cur << ", index: " << index << endl;
    while (cur * 2 < border) {
        if (tree[cur * 2] >= index) {
            cur *= 2;
        } else {
            index -= tree[cur * 2];
            cur = cur * 2 + 1;
        }
//        cout << "cur: " << cur << ", index: " << index << endl;
    }
    if (index == 1 && tree[2 * cur] > 0) return tree[2 * cur];
    return tree[2 * cur + 1];
}

int main() {
    int n, k;
    cin >> n >> k;

    if (n == 1) {
        cout << 1;
        return 0;
    }

    int border = 1;
    while (border < n)
        border <<= 1;
    cout << "border: " << border << endl;
    int tree[2 * border];


    for (int i = 0; i < n; i++)
        tree[border + i] = i + 1;
    for (int i = border + n; i < 2 * border; ++i) {
        tree[i] = 0;
    }
    for (int i = border - 1; i > 0; i--) {
        if (2 * i < border) {
            tree[i] = tree[2 * i] + tree[2 * i + 1];
        } else {
            tree[i] = 0;
            if (tree[2 * i] > 0)
                tree[i]++;
            if (tree[2 * i + 1] > 0)
                tree[i]++;
        }
    }

    for (int l = 1; l < border + n; ++l) {
        cout << tree[l] << " ";
    }
    cout << endl;

    int cur = 1;
    while (n > 0) {
        cur = (cur + k - 1) % n;
        if (cur == 0) cur = n;
        n--;
        int index = get_by_index(tree, cur, border);
        cout << index << endl;
        tree[border + index - 1] = 0;

        int i = border + index - 1;
        while (i > 1) {
            i /= 2;
            tree[i]--;
        }
        /*for (int l = 1; l < 2 * border; ++l) {
            cout << tree[l] << " ";
        }
        cout << endl;*/
    }

    return 0;
}