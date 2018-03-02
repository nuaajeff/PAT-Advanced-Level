#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int min(int a, int b) 
{
    return a < b ? a : b;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> coins;
    for (int i = 0; i < n; i++) {
        int c;
        scanf("%d", &c);
        coins.push_back(c);
    }
    int smallest_v1 = 501;
    int v1, v2;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (coins[i] + coins[j] == m) {
                int min_coin = min(coins[i], coins[j]);
                if (min_coin < smallest_v1) {
                    smallest_v1 = min_coin;
                    v1 = min_coin;
                    v2 = m - v1;
                }
            }
        }
    }
    if (smallest_v1 != 501) {
        printf("%d %d\n", v1, v2);
    } else {
        printf("No Solution\n");
    }
}