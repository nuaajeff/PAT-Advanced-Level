#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

vector<int> inorder;
vector<int> preorder;
vector<int> tree(110000, -1);
vector<int> post_order;
int n; 

void build(int prel, int prer, int inl, int inr, int index)
{
    if (prer < prel) return;
    int root = preorder[prel];
    tree[index] = preorder[prel];
    int i;
    for (i = inl; i <= inr; i++) {
        if (inorder[i] == root) {
            break;
        }
    }
    int left_len = i - inl;
    build(prel+1, prel+left_len, inl, i-1, index*2+1);
    build(prel+left_len+1, prer, i+1, inr, index*2+2);
}

void postorder(int index) 
{
    if (tree[index] == -1) return;
    //cout << "index: " << index << endl;
    postorder(index*2+1);
    postorder(index*2+2);
    post_order.push_back(tree[index]);
}

int main()
{
    cin >> n;
    stack<int> s;
    for (int i = 0; i < 2*n; i++) {
        string str;
        cin >> str;
        if (str == "Push") {
            int node;
            cin >> node;
            preorder.push_back(node);
            s.push(node);
        }
        else if (str == "Pop") {
            int node = s.top();
            s.pop();
            inorder.push_back(node);
        }
    }
    build(0, n-1, 0, n-1, 0);
    postorder(0);
    int cnt = 0;
    /**
    for (int i = 0; cnt != n; i++) {
        if (tree[i] != -1) { 
            cout << "i: " << i << "tree: " << tree[i] << endl;
            cnt++;
        }
    }
    **/
    for (int i = 0; i < n; i++) {
        i < n-1 ? cout << post_order[i] << " " : cout << post_order[i];
    }
}