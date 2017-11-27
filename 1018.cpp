/**
 * memset通常用于对字节进行初始化，对于非字节类的数据如int，最好只初始化为0，否则会引起异常
 * 作为替代，可以使用fill进行初始化
 * 本题用DFS+Dijkstra解决，需要重做以加强理解
 **/
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

const int INT_MAX = 1000000000;

const int MAXV = 510;
int cmax, n, sp, m;
int graph[MAXV][MAXV], weight[MAXV];
int d[MAXV]; // 记录最短距离
vector<int> pre[MAXV]; // 记录前驱
vector<int> tempPath, path;
bool visited[MAXV] = {false};
int min_need = INT_MAX, min_remain = INT_MAX;
int path_num = 0;

void dijkstra(int s)
{
    fill(d, d+MAXV, INT_MAX);
    d[s] = 0;
    for (int i = 0; i <= n; i++)
    {
        int u = -1, min = INT_MAX;
        // 在所有尚未访问但是可到达的顶点中找到距离最近的（重要）
        // 然后访问这个距离最近的点
        for (int j = 0; j <= n; j++)
        {
            if (visited[j] == false && d[j] < min)
            {
                u = j;
                min = d[j];
            }
        }
        if (u == -1) return; // 思考此处返回条件
        visited[u] = true;
        // 然后将上边选出的顶点所连接的点进行更新
        for (int v = 0; v <= n; v++)
        {
            if (visited[v] == false && graph[u][v] != INT_MAX)
            {
                if (d[u] + graph[u][v] < d[v])
                {
                    d[v] = d[u] + graph[u][v];
                    //cout << "dv: " << d[v] << endl;
                    pre[v].clear();
                    pre[v].push_back(u);
                }
                else if (d[u] + graph[u][v] == d[v])
                {
                    pre[v].push_back(u);
                }
            }
        }
    }
}

void dfs(int v)
{
    if (v == 0)
    {
        tempPath.push_back(v);

        int need = 0, remain = 0;
        for (int i = tempPath.size() - 1; i >= 0; i--)
        {
            int id = tempPath[i];
            if (weight[id] > 0)
            {
                remain += weight[id];
            }
            else
            {
                if (remain > abs(weight[id]))
                {
                    remain -= abs(weight[id]);
                }
                else
                {
                    need += abs(weight[id]) - remain;
                    remain = 0;
                }
            }
        }
        if (need < min_need)
        {
            min_need = need;
            min_remain = remain;
            path = tempPath;
        }
        else if (need == min_need && remain < min_remain)
        {
            min_remain = remain;
            path = tempPath;
        }
        tempPath.pop_back();
        return;
    }
    tempPath.push_back(v);
    for (int i = 0; i < pre[v].size(); i++)
    {
        dfs(pre[v][i]);
    }
    tempPath.pop_back();
}

int main()
{
    cin >> cmax >> n >> sp >> m;
    fill(graph[0], graph[0]+MAXV*MAXV, INT_MAX);
    for (int i = 1; i <= n; i++)
    {
        int ci;
        cin >> ci;
        weight[i] = ci - cmax/2;
    }
    for (int i = 0; i < m; i++)
    {
        int si, sj, tij;
        cin >> si >> sj >> tij;
        graph[si][sj] = graph[sj][si] = tij;
    }
    dijkstra(0);

    dfs(sp);

    printf("%d ", min_need);
    for (int i = path.size() - 1; i >= 0; i--)
    {
        printf("%d", path[i]);
        if (i > 0) printf("->");
    }
    printf(" %d", min_remain);

    return 0;
}