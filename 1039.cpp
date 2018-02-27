#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    map<string, vector<int> > stu_cor;
    int n, k;
    cin >> n >> k;
    while(k--) {
        int cor_i, cor_ni;
        cin >> cor_i >> cor_ni;
        while(cor_ni--) {
            string name;
            cin >> name;
            stu_cor[name].push_back(cor_i);
        }
    }

    while(n--) {
        string name;
        cin >> name;
        vector<int> cor_lst(stu_cor[name]);
        sort(cor_lst.begin(), cor_lst.end());
        cout << name << " " << cor_lst.size();
        for (auto i : cor_lst) {
            cout << " " << i;
        }
        cout << endl;
    }
}