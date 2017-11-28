#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<vector<int>> graph;
vector<int> roots;
vector<bool> visited;
set<int> result;
vector<int> id;
int count_;
int maxdepth = 0;

void dfs(int n, int depth)
{
    if (!visited[n])
        visited[n] = true;
    if (depth > maxdepth)
    {
        roots.clear();
        roots.push_back(n);
        maxdepth = depth;
    }
    else if (depth == maxdepth)
    {
        roots.push_back(n);
    }
    for (int i = 0; i < graph[n].size(); i++)
    {
        if (!visited[graph[n][i]])
            dfs(graph[n][i], depth+1);
    }
}

int find(int p)
{
    while(p != id[p])
        p = id[p];
    return p;
}

void union_(int p, int q)
{
    int p_root = find(p);
    int q_root = find(q);
    if (p_root == q_root) return;

    id[p_root] = q_root;
    count_--;
}

bool connected(int p, int q)
{
    return find(p) == find(q);
}

int main()
{
    int n;
    cin >> n;
    graph.resize(n+1);
    visited.resize(n+1, false);
    id.resize(n+1);
    for (int i = 0; i < id.size(); i++) id[i] = i;
    count_ = n;
    for (int i = 0; i < n-1; i++)
    {
        int p, q;
        cin >> p >> q;
        graph[p].push_back(q);
        graph[q].push_back(p);
        if (connected(p, q)) continue;
        union_(p, q);
    }
    if (count_ > 1)
    {
        cout << "Error: " << count_ << " components" << endl;
        return 0;
    }
    dfs(1, 0);
    result.insert(roots.cbegin(), roots.cend());
    maxdepth = 0;
    visited.assign(n+1, false);
    int begin = roots[0];
    roots.clear();
    dfs(begin, 0);
    result.insert(roots.cbegin(), roots.cend());
    for (auto x : result)
    {
        cout << x << endl;
    }

    return 0;
}