/**
 * 注意输出格式
 * 直接用cout输出int格式不能保证7位
 * 也可以选择用string来存id
 **/
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <string>

using namespace std;

int main()
{
    int n;

    //cin >> n;
    //getchar();
    scanf("%d", &n);
    vector<map<string, set<int>>> maps(6);
    for (int i = 0; i < n; i++) {
        string book_title, author, key, publisher, year;
        int id;
        //cin >> id;
        scanf("%d", &id);
        getchar();

        getline(cin, book_title);
        maps[1][book_title].insert(id);

        getline(cin, author);
        maps[2][author].insert(id);

        while (cin >> key) {
            maps[3][key].insert(id);
            char c = getchar();
            if (c == '\n') break;
        }

        getline(cin, publisher);
        maps[4][publisher].insert(id);

        getline(cin, year);
        maps[5][year].insert(id);
    }

    int m;
    //cin >> m;
    //getchar();
    scanf("%d", &m);
    getchar();
    for (int i = 0; i < m; i++) {
        int idx_;
        scanf("%d: ", &idx_);
        string content;
        getline(cin, content);
        cout << idx_ << ": " << content << "\n";
        //string query;
        //getline(cin, query);
        //cout << query << endl;
        //string index = query.substr(0, 1);
        //char idx = index[0] - '0';
        //int idx_ = idx;
        //string content = query.substr(3, query.size()-3);

        //cout << query << endl;
        if (maps[idx_].find(content) == maps[idx_].end()) {
            cout << "Not Found" << endl;
            continue;
        }
        for (auto x : maps[idx_][content]) {
            printf("%07d\n", x);
        }
    }

    return 0;
}