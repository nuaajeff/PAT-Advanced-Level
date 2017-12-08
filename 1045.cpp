#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m, l;
    vector<int> favorite;
    vector<int> stripe;
    cin >> n;
    cin >> m;
    vector<int> hash(n+1, -1);
    for (int i = 0; i < m; i++) {
        int color;
        cin >> color;
        favorite.push_back(color);
        hash[color] = i+1;
    }
    cin >> l;
    for (int i = 0; i < l; i++) {
        int color;
        cin >> color;
        stripe.push_back(color);
    }
    vector<int> lst;
    for (int i = 0; i < l; i++) {
        if (hash[stripe[i]] == -1) {
            continue;
        }
        else {
            lst.push_back(hash[stripe[i]]);
        }
    }
    vector<int> dp(lst.size());
    int ans = 1;
    for (int i = 0; i < dp.size(); i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (dp[j] >= dp[i] && lst[j] <= lst[i]) {
                dp[i] += 1;
                if (dp[i] > ans) {
                    ans = dp[i];
                }
            }
        }
    }
    cout << ans;
}
