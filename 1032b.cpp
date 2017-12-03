#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

struct Node 
{
    char data;
    int next;
    bool flag;
};

int main()
{
    int addr1, addr2, n;
    cin >> addr1 >> addr2 >> n;
    vector<Node> nodes(100000);
    for (int i = 0; i < n; i++) {
        char data;
        int addr, next;
        Node node;
        scanf("%d %c %d", &addr, &data, &next);
        nodes[addr].data = data;
        nodes[addr].next = next;
        nodes[addr].flag = false;
        nodes.push_back(node);
    }
    for (int i = addr1; i != -1; i = nodes[i].next) {
        nodes[i].flag = true;
    }
    for (int i = addr2; i != -1; i = nodes[i].next) {
        if (nodes[i].flag == true) {
            printf("%05d", i);
            return 0;
        }
    }
    printf("-1");
    return 0;
}