/**
 * 解题思路：该题相当于在求去掉一个点后连通图的个数
 * 连通图个数-1即需要多少条路来使其连通
 * 可用DFS、BFS、查并集，本解法采用DFS
 * 不需要真的去掉一个点，只需要提前将其标记为已访问即可
 * 或者另设一个变量标记该点，不对该点进行遍历即可
 **/
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int city[1001][1001];
bool visited[1001];
int city_num, way_num, check_num;
int connect;

void dfs(int current)
{
    visited[current] = true;
    for (int i = 1; i < city_num+1; i++)
    {
        if (!visited[i] && city[current][i])
        {
            dfs(i);
        }

    }
}

int main()
{
    memset(city, 0, sizeof(city));
    vector<int> check_city;
    cin >> city_num >> way_num >> check_num;
    while (way_num--)
    {
        int city1, city2;
        cin >> city1 >> city2;
        city[city1][city2] = city[city2][city1] = 1;
    }
    while (check_num--)
    {
        int check;
        cin >> check;
        check_city.push_back(check);
    }
    for (int i = 0; i < check_city.size(); i++)
    {
        memset(visited, false, sizeof(visited));
        connect = 0;
        for (int j = 1; j < city_num+1; j++)
        {
            visited[check_city[i]] = true;
            if (!visited[j])
            {
                dfs(j);
                connect++;
            }
        }
        cout << connect-1 << endl;
    }
    return 0;
}