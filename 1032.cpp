#include <iostream>
#include <cstdio>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int be1, be2, n;
    cin >> be1 >> be2 >> n;
    int addr, next;
    char data;
    vector<int> be, con;
    map<int, int> ne;
    //cout << "n: " << n << endl;
    ne[be1]++;
    ne[be2]++;
    for (int i = 0; i < n; i++) {
        //cout << "i: " << i << endl;
        cin >> addr >> data >> next;
        ne[next]++;
    }
    bool exist = false;
    for (auto it = ne.cbegin(); it != ne.cend(); it++) {
        if (it->second >= 2) {
            int ans = it->first;
            if (ans == -1) break;
            printf("%05d", ans);
            //cout << it->first << endl;
            exist = true;
        }
    }
    if (!exist) {
        cout << -1 << endl;
    }
    return 0;
}