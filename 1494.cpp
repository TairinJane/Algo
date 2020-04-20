#include <iostream>
#include <stack>

using namespace std;

int balls() {

    int n;
    cin >> n;
    stack<int> stack;
    int max = 1;

    for (int i = 0; i < n; ++i) {
        int ball;
        cin >> ball;
        if (stack.empty()) {
            for (int j = max; j < ball; ++j) {
                stack.push(j);
            }
        } else {
            int top = stack.top();
            if (top == ball) stack.pop();
            else if (top < ball) {
                for (int j = max + 1; j < ball; ++j) {
                    stack.push(j);
                }
                cout << endl;
            } else {
                cout << "Cheater\n";
                break;
            }
        }
        if (ball > max) max = ball;
        if (i == n - 1) cout << "Not a proof";
    }

    return 0;
}
