#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const string &a, const string &b)
{
    if (a + b < b + a) return true;
    else return false;
}

int main()
{
    int n;
    cin >> n;
    vector<string> num;
    for (int i = 0; i < n; i++) {
        string nu;
        cin >> nu;
        num.push_back(nu);
    }
    sort(num.begin(), num.end(), cmp);
    string ans;
    for (int i = 0; i < n; i++) {
        ans += num[i];
    }
    while (ans.size() != 0 && ans[0] == '0') {
        ans.erase(ans.begin());
    }
    if (ans.size() == 0) cout << 0;
    else cout << ans;
    
    return 0;
}