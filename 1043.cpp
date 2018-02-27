#include <iostream>
#include <vector>

using namespace std;

struct node {
    int root;
    node* left;
    node* right;
};

void insert(node* &tree, int i) {
    if (tree == NULL) {
        tree = new node;
        tree->root = i;
        tree->left = NULL;
        tree->right = NULL;
        return;
    }
    if (i < tree->root) {
        insert(tree->left, i);
    }
    else {
        insert(tree->right, i);
    }
}

node* build(const vector<int> &keys) {
    node* tree = NULL;
    for (int i = 0; i < keys.size(); i++) {
        insert(tree, keys[i]);
    }
    return tree;
}

void pre_traverse(node* tree, vector<int> &v) {
    if (tree == NULL) {
        return;
    }
    v.push_back(tree->root);
    pre_traverse(tree->left, v);
    pre_traverse(tree->right, v);
}

void pre_m_traverse(node* tree, vector<int> &v) {
    if (tree == NULL) {
        return;
    }
    v.push_back(tree->root);
    pre_m_traverse(tree->right, v);
    pre_m_traverse(tree->left, v);
}

void post_traverse(node* tree, vector<int> &v) {
    if (tree == NULL) {
        return;
    }
    post_traverse(tree->left, v);
    post_traverse(tree->right, v);
    v.push_back(tree->root);
}

void post_m_traverse(node* tree, vector<int> &v) {
    if (tree == NULL) {
        return;
    }
    post_m_traverse(tree->right, v);
    post_m_traverse(tree->left, v);
    v.push_back(tree->root);
}

int main() {
    int n;
    cin >> n;
    vector<int> keys;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        keys.push_back(k);
    }

    node* tree = build(keys);

    vector<int> preorder;
    pre_traverse(tree, preorder);
    vector<int> preorder_m;
    pre_m_traverse(tree, preorder_m);

    if (preorder == keys) {
        cout << "YES" << endl;
        vector<int> postorder;
        post_traverse(tree, postorder);
        for (int i = 0; i < postorder.size() - 1; i++) {
            cout << postorder[i] << " ";
        }
        cout << postorder[postorder.size()-1] << endl;
    }
    else if (preorder_m == keys) {
        cout << "YES" << endl;
        vector<int> postorder;
        post_m_traverse(tree, postorder);
        for (int i = 0; i < postorder.size() - 1; i++) {
            cout << postorder[i] << " ";
        }
        cout << postorder[postorder.size()-1] << endl;
    }
    else {
        cout << "NO" << endl;
    }
}