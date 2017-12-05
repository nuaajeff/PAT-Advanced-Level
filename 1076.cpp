/**
 * 1.如果不在退出时取消已经visited的值可能会导致最后没办法统计完全
 * 2.DFS会超时，改用BFS
 **/
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> follow(1010); // followed by user[i]
vector<vector<int>> follower(1010); // user[i]'s follower
vector<int> query;
vector<bool> visited(1010, false);
vector<bool> counted(1010, false);
int n, l, count;

void dfs(int curr, int level)
{
    //cout << curr << " " << level << endl;
    if (level > l) return;
    visited[curr] = true;
    if (!counted[curr]){
        count++;
        counted[curr] = true;
    }
    for (int i = 0; i < follower[curr].size(); i++) {
        if (!visited[follower[curr][i]] && level+1 <= l) {
            dfs(follower[curr][i], level+1);
        }
    }
    visited[curr] = false;
}

int main()
{
    cin >> n >> l;
    for (int i = 1; i <= n; i++) {
        int m;
        cin >> m;
        for (int j = 0; j < m; j++) {
            int fo;
            cin >> fo;
            follow[i].push_back(fo);
            follower[fo].push_back(i);
        }
    }
    /**
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < follower[i].size(); j++) {
            cout << "follower[" << i  << "][" << j << "]: " << follower[i][j] << endl;
        }
    }
    **/
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int q;
        cin >> q;
        query.push_back(q);
    }

    for (int i = 0; i < k; i++) {
        count = -1;
        for (int j = 0; j < visited.size(); j++) {
            visited[j] = false;
        }
        for (int j = 0; j < counted.size(); j++) {
            counted[j] = false;
        }
        dfs(query[i], 0);
        cout << count << endl;
    }
}