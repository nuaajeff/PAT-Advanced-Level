/**
 * 该实现方法有两个测试点过不了
 * 分析原因，应该是因为输入没有保证顺序，即输入的ID不一定是已经存在父节点的
 * 有可能先输入子节点，才输入父节点
 * 如果想用动态数组实现需要参考刘汝佳白书
 * */
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode
{
    int label;
    vector<TreeNode*> children;
};

vector<int> ans;

void dfs(TreeNode* curr, int level)
{
    if (level+1 > ans.size())
        ans.push_back(0);
    if (curr->children.size() == 0)
        ans[level]++;
    for (int i = 0; i < curr->children.size(); i++)
        dfs(curr->children[i], level+1);
}

void first_order(TreeNode* tree)
{
    cout << tree->label << endl;
    for (int i = 0; i < tree->children.size(); i++)
    {
        first_order(tree->children[i]);
    }
}

void find_by_id(TreeNode* tree, int id, TreeNode* &curr)
{
    if (tree->label == id)
    {
        //cout << "tree.label: " << tree->label << " id: " << id << endl; 
        curr = tree;
        //cout << "bingo" << endl;
        return;
    }
    for (int i = 0; i < tree->children.size(); i++)
    {
        find_by_id(tree->children[i], id, curr);
    }
}

int main()
{
    int nodes_num = 0;
    int non_leaf_nodes_num = 0;
    cin >> nodes_num >> non_leaf_nodes_num;
    TreeNode* tree = new TreeNode;
    tree->label = 1;
    TreeNode* current = tree;
    for (int i = 0; i < non_leaf_nodes_num; i++)
    {
        int id;
        int k;
        cin >> id >> k;
        //cout << "id: " << id << endl;
        find_by_id(tree, id, current);
        //cout << "Current: " << current->label << endl;
        for (int j = 0; j < k; j++)
        {
            int cid;
            cin >> cid;
            TreeNode* child = new TreeNode;
            child->label = cid;
            current->children.push_back(child);
        }
    }

    dfs(tree, 0);
    for (int i = 0; i < ans.size(); i++)
        i != ans.size() - 1 ? cout << ans[i] << ' ' : cout << ans[i] << endl;

    return 0;
}
