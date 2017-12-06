#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
    int left, right;
};

vector<Node> tree;
vector<int> level_order;
vector<int> in_order;
int n;

int findroot()
{
    vector<bool> ischild(n, false);
    for (int i = 0; i < n; i++) {
        if (tree[i].left != -1) ischild[tree[i].left] = true;
        if (tree[i].right != -1) ischild[tree[i].right] = true;
    }
    for (int i = 0; i < n; i++) {
        if (ischild[i] == false) return i;
    }
}

void invert(int root)
{
    if (root == -1) return;
    int tmp = tree[root].left;
    tree[root].left = tree[root].right;
    tree[root].right = tmp;
    invert(tree[root].left);
    invert(tree[root].right);
}

void level_travel(int root)
{
    queue<int> q;
    q.push(root);
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        if (tree[curr].left != -1)
            q.push(tree[curr].left);
        if (tree[curr].right != -1)
            q.push(tree[curr].right);
        level_order.push_back(curr);
    }
}

void in_travel(int root)
{
    if (root == -1) return;
    if (tree[root].left != -1) in_travel(tree[root].left);
    in_order.push_back(root);
    if (tree[root].right != -1) in_travel(tree[root].right);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        Node no;
        char left, right;
        cin >> left >> right;
        if (left == '-') {
            no.left = -1;
        } else {
            no.left = left - '0';
        }
        if (right == '-') {
            no.right = -1;
        } else {
            no.right = right - '0';
        }
        tree.push_back(no);
    }

    int root = findroot();
    // cout << root << endl;
    invert(root);

    /**
    for (int i = 0; i < n; i++) {
        cout << "i: " << i << " left: " << tree[i].left << " right: " << tree[i].right << endl;
    }
    **/
    
    level_travel(root);
    in_travel(root);

    for (int i = 0; i < n; i++) {
        i < n-1 ? cout << level_order[i] << " " : cout << level_order[i] << endl;
    }
    for (int i = 0; i < n; i++) {
        i < n-1 ? cout << in_order[i] << " " : cout << in_order[i] << endl;
    }

}