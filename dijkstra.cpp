#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int dijkstra() {
    int n;
    int m;
    cin >> n >> m;
    n++;
    long int infinity = 10000 * m;

    map<pair<int, int>, int> costs;
    vector<int> pipes[n];
    int d[n], used[n];
    int a, b, c;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        costs[{a, b}] = c;
        pipes[a].push_back(b);
    }

    for (int k = 0; k < n; ++k) {
        d[k] = 0;
        used[k] = 0;
    }

    int s, f;
    cin >> s >> f;

    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        used[node] = 1;
        cout << "node: " << node << endl;
        for (int i = 0; i < pipes[node].size(); ++i) {
            int next = pipes[node][i];
            cout << next << ": " << d[next] << ", " << costs[{node, next}] << "; ";
            int new_cost = d[node] + costs[{node, next}];
            if (new_cost < d[next]) d[next] = new_cost;
        }
        cout << endl;

        long int min = infinity;
        int v;
        for (int j = 1; j < n; ++j) {
            if (d[j] < min) {
                min = d[j];
                v = j;
            }
        }
        if (used[v] == 0) q.push(v);
    }

    if (d[f] != -1) {
        cout << d[f];
    } else cout << "No solution";

}