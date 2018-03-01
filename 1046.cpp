// 该题借鉴PAT-A-1044的思想，值得注意

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

void swap(int &v1, int &v2) 
{
    int t = v1;
    v1 = v2;
    v2 = t;
}

int main() 
{
    int n, m;
    scanf("%d", &n);
    vector<int> distance;
    vector<int> distance_sum;
    distance.push_back(0);
    distance_sum.push_back(0);
    int sum_distance = 0;
    for (int i = 1; i <= n; i++) {
        int d;
        scanf("%d", &d);
        distance.push_back(d);
        distance_sum.push_back(distance_sum[i-1]+d);
        sum_distance += d;
    }

    scanf("%d", &m);
    while(m--) {
        int m1, m2;
        scanf("%d %d", &m1, &m2);
        if (m1 > m2) swap(m1, m2);
        int distance1 = distance_sum[m2-1] - distance_sum[m1-1];
        int distance2 = sum_distance - distance1;
        (distance1 < distance2) ? cout << distance1 << endl : cout << distance2 << endl;
    }
    return 0;
}