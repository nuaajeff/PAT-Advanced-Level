#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

const int INF = 10000000;
vector<vector<int>> graph(2010, vector<int>(2001, 0));
map<string, int> str_to_int;
map<int, string> int_to_str;
vector<bool> visited(2010, false);
vector<int> components[2010];
vector<int> weight(2010, 0);
int num = 1;
int connected = 0;

void dfs(int node)
{
    visited[node] = true;
    components[connected].push_back(node);
    for (int i = 1; i <= num; i++) {
        if (graph[node][i] > 0) {
            weight[node] += graph[node][i];
        }
        if (!visited[i] && graph[node][i] > 0) {
            dfs(i);
        }
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        string name1, name2;
        int time;
        cin >> name1 >> name2 >> time;
        if (str_to_int.find(name1) == str_to_int.end()) {
            str_to_int[name1] = num;
            int_to_str[num] = name1;
            num++;
        }
        if (str_to_int.find(name2) == str_to_int.end()) {
            str_to_int[name2] = num;
            int_to_str[num] = name2;
            num++;
        }
        graph[str_to_int[name1]][str_to_int[name2]] += time;
        graph[str_to_int[name2]][str_to_int[name1]] += time;
    }

    for (int i = 1; i <= num; i++) {
        if (!visited[i]) {
            dfs(i);
            connected++;
        }
    }

    vector<int> head_of_gang;
    vector<string> head_of_gang_str;
    map<string, int> people_of_gang;
    for (int i = 0; i < connected; i++) {
        int max_idx = -1;
        int max_weight = -1;
        int total_weight = 0;
        for (int j = 0; j < components[i].size(); j++) {
            total_weight += weight[components[i][j]];
        }
        if (components[i].size() > 2 && total_weight / 2 > k) {
            for (int j = 0; j < components[i].size(); j++) {
                if (weight[components[i][j]] > max_weight) {
                    max_weight = weight[components[i][j]];
                    max_idx = components[i][j];
                }
            }
            head_of_gang.push_back(max_idx);
            head_of_gang_str.push_back(int_to_str[max_idx]);
            people_of_gang[int_to_str[max_idx]] = components[i].size();
        }
    }

    sort(head_of_gang_str.begin(), head_of_gang_str.end());
    cout << head_of_gang_str.size() << endl;
    for (int i = 0; i < head_of_gang_str.size(); i++) {
        cout << head_of_gang_str[i] << " " << people_of_gang[head_of_gang_str[i]] << endl;
    }
}