/**
 * Reference: 刘汝佳紫书例题6-8
 **/
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector<int> inorder;
vector<int> postorder;
vector<int> tree(100000, -1);

void build(int postl, int postr, int inl, int inr, int index)
{
    if (postl > postr) return;
    tree[index] = postorder[postr];
    //cout << tree[index] << endl;
    int i;
    for (i = inl; i <= inr; i++)
        if (inorder[i] == postorder[postr])
            break;
    int cnt = i - inl;
    build(postl, postl+cnt-1, inl, i-1, index*2+1);
    build(postl+cnt, postr-1, i+1, inr, index*2+2);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int leaf;
        cin >> leaf;
        postorder.push_back(leaf);
    }
    for (int i = 0; i < n; i++)
    {
        int leaf;
        cin >> leaf;
        inorder.push_back(leaf);
    }
    build(0, n-1, 0, n-1, 0);
    int cnt = 0;
    for (int i = 0; i < tree.size(); i++)
    {
        if (tree[i] != -1 && cnt != n - 1)
        {
            cout << tree[i] << " ";
            cnt++;
        }
        else if (tree[i] != -1)
        {
            cout << tree[i];
            break;
        }
    }
    return 0;
}