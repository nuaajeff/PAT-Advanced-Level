#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode
{
    string label;
    TreeNode* parent;
    vector<TreeNode*> children;
};

vector<int> ans;

void dfs(TreeNode* curr, int level)
{
    if (level+1 > ans.size())
    {
        ans.push_back(0);
    }
    if (curr->children.size() == 0)
    {
        ans[level]++;
    }
    for (int i = 0; i < curr->children.size(); i++)
    {
        dfs(curr->children[i], level+1);
    }
}

void first_order(TreeNode* tree)
{
    cout << tree->label << endl;
    for (int i = 0; i < tree->children.size(); i++)
    {
        first_order(tree->children[i]);
    }
}

void find_by_id(TreeNode* tree, string id, TreeNode* &curr)
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
    tree->label = "01";
    TreeNode* current = tree;
    for (int i = 0; i < non_leaf_nodes_num; i++)
    {
        string id;
        int k;
        cin >> id >> k;
        //cout << "id: " << id << endl;
        find_by_id(tree, id, current);
        //cout << "Current: " << current->label << endl;
        for (int j = 0; j < k; j++)
        {
            string cid;
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
