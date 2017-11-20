/** 
 * PAT-A-1003
 * 可以用dijkstra算法或者DFS算法求解
 * 用DFS求解 思路：求两点间所有的路径，并记录救援队数量最大的
 * **/

#include <iostream>
#include <cstdio>
#include <climits>

using namespace std;

int city_num = 0;
int road_num = 0;
int C1 = -1;
int C2 = -1;
int rescue_team_num[501];
int city_graph[501][501];
bool visited[501];
int min_distance = INT_MAX;
int max_rescue_num = 0;
int path_num = 0;

void dfs(int current_node, int all_rescue_num, int distance)
{
    if (current_node == C2)
    {
        if (distance < min_distance)
        {
            //cout << "distance < min_distance" << endl;
            path_num = 1;
            max_rescue_num = all_rescue_num;
            min_distance = distance;
        }
        else if (distance == min_distance)
        {
            //cout << "distance == min_distance" << endl;
            path_num++;
            if (all_rescue_num > max_rescue_num)
                max_rescue_num = all_rescue_num;
        }
        return;
    }
    
    if (distance > min_distance)
        return;

    for (int i = 0; i < city_num; i++)
    {
        if (!visited[i] && city_graph[current_node][i] != INT_MAX)
        {
            visited[i] = true;
            dfs(i, all_rescue_num+rescue_team_num[i], distance+city_graph[i][current_node]);
            visited[i] = false;
        }
    }
}

int main()
{
    cin >> city_num >> road_num >> C1 >> C2;
    for (int i = 0; i < 501; i++)
        for (int j = 0; j < 501; j++)
            city_graph[i][j] = INT_MAX;
    for(int i = 0; i < 501; i++)
        visited[i] = false;
    for (int i = 0; i < city_num; i++)
    {
        cin >> rescue_team_num[i];
    }
    for (int i = 0; i < road_num; i++)
    {
        int c1, c2, l;
        cin >> c1 >> c2 >> l;
        city_graph[c1][c2] = l;
        city_graph[c2][c1] = l;
    }
    
    dfs(C1, rescue_team_num[C1], 0);
    cout << path_num << ' ' << max_rescue_num << endl;
    return 0;
}