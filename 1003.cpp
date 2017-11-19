#include <iostream>
#include <cstdio>

int main()
{
    int city_num = 0;
    int rode_num = 0;
    int C1 = -1;
    int C2 = -1;
    int rescue_team_num[501];
    int city_graph[501][501];
    for (int i = 0; i < 501; i++)
        for (int j = 0; j < 501; j++)
            city_graph[i][j] = 0;
    cin >> city_num >> rode_num >> C1 >> C2;
    for (int i = 0; i < city_num; i++)
    {
        cin >> rescue_team_num[i];
    }
    for (int i = 0; i < rode_num; i++)
    {
        int c1, c2, l;
        cin >> c1 >> c2 >> l;
        city_graph[c1][c2] = l;
        city_graph[c2][c1] = l;
    }
    return 0;
}