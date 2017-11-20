#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector<int> tree[101];
vector<int> answer;

void dfs(int id, int level)
{
    if (level+1 > answer.size())
        answer.push_back(0);
    if (tree[id].size() == 0)
        answer[level]++;
    for (int i = 0; i < tree[id].size(); i++)
        dfs(tree[id][i], level+1);
}

int main()
{
    int node_num;
    int non_leaf_node_num;
    cin >> node_num >> non_leaf_node_num;
    for (int i = 0; i < non_leaf_node_num; i++)
    {
        int id, k;
        cin >> id >> k;
        for (int j = 0; j < k; j++)
        {
            int cid;
            cin >> cid;
            tree[id].push_back(cid);
        }
    }
    dfs(1, 0);
    for (int i = 0; i < answer.size(); i++)
    {
        i != answer.size() - 1 ? cout << answer[i] << " " : cout << answer[i];
    }

    return 0;
}