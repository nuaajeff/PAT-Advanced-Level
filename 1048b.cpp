#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    vector<int> coin_hash(1010, 0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        coin_hash[c]++;
    }
    for (int i = 1; i < m && i < 501; i++) {
        if (coin_hash[i] && coin_hash[m-i]) {
            if (i == m - i && coin_hash[i] <= 1) {
                continue;
            }
            printf("%d %d\n", i, m - i);
            return 0;
        }
    }
    printf("No Solution\n");
    return 0;
}