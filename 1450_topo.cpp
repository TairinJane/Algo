#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> pipes[501];
int d[501], used[501];
int s, f;
vector<int> topological;
int topo_s, topo_f;

void dfs(int v) {
    used[v] = 1;
    for (int i : pipes[v]) {
        if (used[i] != 1) {
            dfs(i);
        }
    }
    topological.push_back(v);

    if (v == s) topo_s = (int) topological.size() - 1;
    if (v == f) topo_f = (int) topological.size() - 1;
}

int topo() {
    int n;
    int m;
    scanf("%d %d", &n, &m);
    n++;

    map<pair<int, int>, int> costs;
    int a, b, c;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &a, &b, &c);
        costs[{a, b}] = c;
        pipes[a].push_back(b);
    }

    for (int k = 0; k < n; ++k) {
        d[k] = 0;
        used[k] = 0;
    }

    scanf("%d %d", &s, &f);

    dfs(s);

    if (topo_s > topo_f) {
        for (int j = topo_s; j > topo_f; --j) {
            int node = topological[j];
            for (int i = 0; i < pipes[node].size(); ++i) {
                int next = pipes[node][i];
                int new_cost = d[node] + costs[{node, next}];
                if (new_cost > d[next]) d[next] = new_cost;
            }
            cout << endl;
        }

        if (d[f] != 0) cout << d[f];
        else cout << "No solution";

    } else cout << "No solution";

}