#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    int m;
    scanf("%d %d", &n, &m);
    n++;

    vector<pair<int, int>> min_tree;
    vector<pair<int, pair<int, int>>> lengths;

    int a, b, l;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &a, &b, &l);
        lengths.push_back({l, {a, b}});
    }

    sort(lengths.begin(), lengths.end());

    int tree[n];
    for (int i = 0; i < n; ++i)
        tree[i] = i;

    int max = 0;
    for (int i = 0; i < m; ++i) {
        a = lengths[i].second.first;
        b = lengths[i].second.second;
        l = lengths[i].first;
        if (tree[a] != tree[b]) {
            if (l > max) max = l;
            min_tree.emplace_back(a, b);
            int b_tree = tree[b];
            for (int j = 0; j < n; ++j)
                if (tree[j] == b_tree)
                    tree[j] = tree[a];
        }
    }

    cout << max << endl;
    cout << min_tree.size() << endl;
    for (auto &node : min_tree) {
        cout << node.first << " " << node.second << endl;
    }

    return 0;
}