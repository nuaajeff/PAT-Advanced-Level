#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
const int INF = 1000000;
vector<vector<int>> graph(510, vector<int>(510, INF));
vector<vector<int>> cost(510, vector<int>(510, INF));
vector<vector<int>> pre(510);
vector<int> answer;
vector<int> temp;
int n, m, s, d, ans_distance;
int min_cost = INF;

void dijkstra()
{
    vector<bool> visited(n, false);
    vector<int> dis(n, INF);
    dis[s] = 0;
    for (int i = 0; i < n; i++) {
        int u = -1, min = INF;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && dis[j] < min) {
                u = j;
                min = dis[j];
            }
        }
        if (u == -1) return;
        visited[u] = true;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && graph[u][j] != INF) {
                if (dis[u] + graph[u][j] < dis[j]) {
                    pre[j].clear();
                    pre[j].push_back(u);
                    dis[j] = dis[u] + graph[u][j];
                }
                else if (dis[u] + graph[u][j] == dis[j]) {
                    pre[j].push_back(u);
                }
            }
        }
    }
}

void dfs(int cur, int total_cost, int total_distance)
{
    if (cur == s && total_cost < min_cost) {
        min_cost = total_cost;
        ans_distance = total_distance;
        answer = temp;
        return;
    }
    /**
    for (int i = 0; i < pre[cur].size(); i++) {
        temp.push_back(pre[cur][i]);
        dfs(pre[cur][i], total_cost+cost[cur][i], total_distance+graph[cur][i]);
        temp.pop_back();
    }
    **/
    for (auto pr : pre[cur]) {
        temp.push_back(pr);
        dfs(pr, cost[cur][pr]+total_cost, graph[cur][pr]+total_distance);
        temp.pop_back();
    }
}

int main()
{
    cin >> n >> m >> s >> d;

    for (int i = 0; i < m; i++) {
        int c1, c2, dis, co;
        cin >> c1 >> c2 >> dis >> co;
        graph[c1][c2] = dis;
        graph[c2][c1] = dis;
        cost[c1][c2] = co;
        cost[c2][c1] = co;
    }

    dijkstra();
    dfs(d, 0, 0);

    for (int i = answer.size()-1; i >= 0; i--) {
        cout << answer[i] << ' ';
    }
    cout << d << ' ';
    cout << ans_distance << " " << min_cost;
}