#include <iostream>
#include <vector>
#include <string>

using namespace std;
vector<vector<int>> p(1010, vector<int>(1010, 0));

int main()
{
    string str;
    getline(cin, str);
    const int len = str.size();
    int ans = 1;
    for (int i = 0; i < len; i++)
    {
        p[i][i] = 1;
        if (i < len-1) {
            if (str[i] == str[i+1]) {
                p[i][i+1] = 1;
                ans = 2;
            }
        }
    }
    for (int l = 3; l <= len; l++) {
        for (int i = 0; i + l - 1 < len; i++) {
            int j = i + l - 1;
            if (str[i] == str[j] && p[i+1][j-1] == 1) {
                p[i][j] = 1;
                ans = l;
            }
        }
    }
    cout << ans;
    return 0;
}