#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

vector<int> course[2510];
char name[40010][5];

bool cmp(int a, int b) {
    return strcmp(name[a], name[b]) < 0;
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%s", name[i]);
        int c;
        scanf("%d", &c);
        for (int j = 0; j < c; j++) {
            int cor;
            scanf("%d", &cor);
            course[cor].push_back(i);
        }
    }
    for (int i = 1; i <= k; i++) {
        printf("%d %lu\n", i, course[i].size());
        sort(course[i].begin(), course[i].end(), cmp);
        for (auto n : course[i]) {
            printf("%s\n", name[n]);
        }
    }
    return 0;
}
