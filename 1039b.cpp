// 本题考查字符串hash
// 注意细节：虽然名字有4个字符，但是必须设置成char[5]
// 需要给字符串的结尾留下空间。结尾为\0
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 26 * 26 * 26 * 10 + 1;
vector<int> stu[maxn];

int str2int(char name[]) {
    int id = 0;
    for (int i = 0; i < 3; i++) {
        id = id * 26 + (name[i] - 'A');
    }
    id = id * 10 + (name[3] - '0');
    return id;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    while(k--) {
        int cor_i, cor_ni;
        scanf("%d %d", &cor_i, &cor_ni);
        while(cor_ni--) {
            char name[5];
            scanf("%s", name);
            int id = str2int(name);
            stu[id].push_back(cor_i);
        }
    }

    while(n--) {
        char name[5];
        scanf("%s", name);
        int id = str2int(name);
        sort(stu[id].begin(), stu[id].end());
        printf("%s %lu", name, stu[id].size());
        for (auto i : stu[id]) {
            printf(" %d", i);
        }
        printf("\n");
    }
}