#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    int m, n, k;
    cin >> m >> n >> k;
    while (k--) {
        vector<int> pop_seq;
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            pop_seq.push_back(num);
        }
        int current = 1;
        stack<int> stck;
        int i;
        for (i = 0; i < pop_seq.size(); i++) {
            bool full = false;
            while (stck.empty() || stck.top() < pop_seq[i]) {
                stck.push(current);
                if (stck.size() > m) {
                    full = true;
                    break;
                }
                current++;
            }
            if (full) {
                cout << "NO" << endl;
                break;
            }
            //cout << "stck.top: " << stck.top() << " pop_seq[i]: " << pop_seq[i] << endl;
            if (stck.top() == pop_seq[i]) {
                stck.pop();
            }
            else if (stck.top() > pop_seq[i]) {
                cout << "NO" << endl;
                break;
            }
        }
        if (i == pop_seq.size()) {
            cout << "YES" << endl;
        }
    }
}