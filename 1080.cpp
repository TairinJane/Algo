#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int colors() {
    long int n;
    cin >> n;
    n++;
    vector<int> graph[n];
    int colors[n];
    queue<int> q;

    for (int i = 1; i < n; ++i) {
        colors[i] = -1;
        int num;
        cin >> num;
        while (num != 0) {
            graph[i].push_back(num);
            graph[num].push_back(i);
            cin >> num;
        }
    }

    q.push(1);
    colors[1] = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int i = 0; i < graph[node].size(); ++i) {
            int child = graph[node][i];
            if (colors[child] == -1) {
                colors[child] = colors[node] == 1 ? 0 : 1;
                q.push(child);
            } else if (colors[child] == colors[node]) {
                cout << -1;
                return 0;
            }
        }
    }

    for (int i = 1; i < n; ++i) {
        cout << colors[i];
    }
}