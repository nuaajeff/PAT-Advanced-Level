#include <iostream>
#include <vector>
#include <queue>

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

void bfs(int curr)
{
    queue<int> q;
    visited[curr] = true;
    q.push(curr);
    int level = 0;
    int first = 0, last = 1;
    while (!q.empty()) {
        int curr = q.front();
        //cout << curr << " " << level << endl;
        q.pop();
        first++;
        for (int i = 0; i < follower[curr].size(); i++) {
            if (!visited[follower[curr][i]] && level+1 <= l) {
                visited[follower[curr][i]] = true;
                //cout << follower[curr][i] << endl;
                count++; 
                q.push(follower[curr][i]);
            }
        }
        //cout << "first: " << first << " last: " << last << " level: " << level << " count: " << count << endl;
        if (first == last) {
            level++;
            last = count+1;
        }
        if (level == l) break;
    }
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
        count = 0;
        for (int j = 0; j < visited.size(); j++) {
            visited[j] = false;
        }
        for (int j = 0; j < counted.size(); j++) {
            counted[j] = false;
        }
        bfs(query[i]);
        cout << count << endl;
    }
}