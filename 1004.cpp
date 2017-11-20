#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

struct TreeNode
{
    string label;
    TreeNode* parent;
    vector<TreeNode*> children;
};

int main()
{
    int nodes_num = 0;
    int non_leaf_nodes_num = 0;
    cin >> nodes_num >> non_leaf_nodes_num;
    struct TreeNode tree;
    for (int i = 0; i < non_leaf_nodes_num; i++)
    {

    }
}