#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct Node {
    int address;
    int key;
    int next;
    bool flag;
};

bool cmp(const Node &a, const Node &b) {
    if (a.flag == false || b.flag == false) {
        return a.flag > b.flag;
    }
    return a.key < b.key;
}

int main()
{
    int n, head;
    cin >> n >> head;
    vector<Node> linked_lst;
    map<int, int> addr2idx;
    for (int i = 0; i < n; i++) {
        int ad, ke, ne;
        cin >> ad >> ke >> ne;
        Node no;
        no.address = ad;
        no.key = ke;
        no.next = ne;
        no.flag = false;
        addr2idx[ad] = i;
        linked_lst.push_back(no);
    }
    int valid = 0;
    while(head != -1) {
        linked_lst[addr2idx[head]].flag = true;
        head = linked_lst[addr2idx[head]].next;
        valid++;
    }
    if (valid == 0) {
        printf("0 -1\n");
        return 0;
    }
    sort(linked_lst.begin(), linked_lst.end(), cmp);
    head = linked_lst[0].address;
    for (int i = 0; i < linked_lst.size()-1; i++) {
        linked_lst[i].next = linked_lst[i+1].address;
    }
    linked_lst[linked_lst.size()-1].next = -1;
    //cout << n << " " << head << endl;
    printf("%d %05d\n", valid, linked_lst[0].address);
    for (int i = 0; i < valid-1; i++) {
        //cout << linked_lst[i].address << " " << linked_lst[i].key << " " << linked_lst[i].next << endl;
        printf("%05d %d %05d\n", linked_lst[i].address, linked_lst[i].key, linked_lst[i].next);
    }
    printf("%05d %d -1\n", linked_lst[valid-1].address, linked_lst[valid-1].key);
}