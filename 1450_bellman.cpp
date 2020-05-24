#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    int m;
    scanf("%d %d", &n, &m);
    n++;

    int d[n];
    int s, f;

    vector<pair<pair<int, int>, int>> costs;
    int a, b, c;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &a, &b, &c);
        costs.push_back({{a, b}, -c});
    }

    for (int k = 0; k < n; ++k) {
        d[k] = 1;
    }

    scanf("%d %d", &s, &f);

    bool any = true;
    d[s] = 0;
    while (any) {
        any = false;
        for (pair<const pair<int, int>, int> e : costs) {
            int u = e.first.first;
            if (d[u] > 0) continue;
            int v = e.first.second;
            int cost = e.second;
            if (d[u] + cost < d[v]) {
                d[v] = d[u] + cost;
                any = true;
            }
        }
        for (int i = 1; i < n; ++i) {
            cout << d[i] << ", ";
        }
        cout << endl;
    }

    if (d[f] < 0) cout << -d[f];
    else cout << "No solution";
}