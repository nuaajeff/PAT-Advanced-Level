#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;

vector<vector<int>> tree(100010);
int n;
int max_depth = -1;
int leaf_num = 0;

void dfs(int root, int level)
{
    if (level > max_depth) {
        max_depth = level;
        leaf_num = 1;
    } else if (level == max_depth) {
        leaf_num++;
    }
    for (int i = 0; i < tree[root].size(); i++) {
        dfs(tree[root][i], level+1);
    }
}

int main()
{
    double p, r;
    cin >> n >> p >> r;
    r /= 100;
    int root;
    for (int i = 0; i < n; i++) {
        int supplier;
        cin >> supplier;
        if (supplier == -1) {
            root = i;
            continue;
        }
        tree[supplier].push_back(i);
    }
    dfs(root, 0);
    printf("%.2f %d\n", p * pow(1+r, max_depth), leaf_num);
    return 0;
}